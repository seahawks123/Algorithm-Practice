class Solution {
private:
    void dfs(unordered_map<int, vector<int>>& map, int cur, unordered_set<int>& s){
        vector<int> neighbors = map[cur];
        for(int i = 0; i < neighbors.size(); i++){
            if(s.count(neighbors[i]) == 0){
                s.insert(neighbors[i]);
                dfs(map, neighbors[i], s);
            }
        }
    }
    bool connected(unordered_map<int, vector<int>>& map){
        unordered_set<int> s;
        int count = 0;
        for(auto it = map.begin(); it != map.end(); it++){
            if(s.count(it->first) == 0){
                s.insert(it->first);
                dfs(map, it->first, s);
                count++;
            }
        }
        return count == 1;
    }
    bool dfs_cycle(unordered_map<int, vector<int>>& map, vector<bool>& visited, int cur, int parent){
        vector<int> neighbors = map[cur];
        for(int i = 0; i < neighbors.size(); i++){
            if(!visited[neighbors[i]]){
                visited[neighbors[i]] = true;
                if(dfs_cycle(map, visited, neighbors[i], cur)){
                    return true;
                }
            }
            else{
                if(parent != neighbors[i]){
                    return true;
                }
            }
        }
        return false;
    }
    bool acyclic(unordered_map<int, vector<int>>& map, vector<bool>& visited){
        for(auto it = map.begin(); it != map.end(); it++){
            if(!visited[it->first]){
                visited[it->first] = true;
                if(dfs_cycle(map, visited, it->first, -1))
                    return false;
            }
        }
        return true;
    }
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        unordered_map<int, vector<int>> map;
        if(n <= 1)
            return true;
        if(edges.size() != (n - 1))
            return false;
        for(int i = 0; i < edges.size(); i++){
            map[edges[i].first].push_back(edges[i].second);  
            map[edges[i].second].push_back(edges[i].first);
        }
        vector<bool> visited(n, false);
        return connected(map) && acyclic(map, visited);
    }
};



class Solution {
private:
    bool dfs_cycle(unordered_map<int, vector<int>>& map, vector<bool>& visited, int cur, int parent){
        vector<int> neighbors = map[cur];
        for(int i = 0; i < neighbors.size(); i++){
            if(!visited[neighbors[i]]){
                visited[neighbors[i]] = true;
                if(dfs_cycle(map, visited, neighbors[i], cur)){
                    return true;
                }
            }
            else{
                if(parent != neighbors[i]){
                    return true;
                }
            }
        }
        return false;
    }
    bool acyclic(unordered_map<int, vector<int>>& map, vector<bool>& visited){
        for(auto it = map.begin(); it != map.end(); it++){
            if(!visited[it->first]){
                visited[it->first] = true;
                if(dfs_cycle(map, visited, it->first, -1))
                    return false;
            }
        }
        return true;
    }
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        unordered_map<int, vector<int>> map;
        if(n <= 1)
            return true;
        if(edges.size() != (n - 1))
            return false;
        for(int i = 0; i < edges.size(); i++){
            map[edges[i].first].push_back(edges[i].second);  
            map[edges[i].second].push_back(edges[i].first);
        }
        vector<bool> visited(n, false);
        if(acyclic(map, visited) == false)
            return false;
        for(auto i : visited){
            if(i == false)
                return false;
        }
        return true;
    }
};
