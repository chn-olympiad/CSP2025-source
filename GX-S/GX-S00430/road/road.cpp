#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
private:
    int comp_cnt;
    vector<int> parent;
    vector<int> sizes;

public:
    DisjointSet(int size) : comp_cnt(size), parent(size), sizes(size, 1) {
        for (int i = 0; i < size; i++) parent[i] = i;
    }

    int find(int x) {return parent[x] == x ? x : parent[x] = find(parent[x]);}

    bool unite(pair<int, int> edge){
        int x_root = find(edge.first);
        int y_root = find(edge.second);
        if (x_root == y_root) return false;

        comp_cnt--;
        if (sizes[x_root] < sizes[y_root]) swap(x_root, y_root);
        parent[y_root] = x_root;
        sizes[x_root] += sizes[y_root];
        return true;
    }

    bool full_connected() {return (comp_cnt == 1);}
};

int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int node_num, edge_num, build_num;
    cin >> node_num >> edge_num >> build_num;

    vector<pair<long long, pair<int, int>>> edges(edge_num);
    for (auto &it : edges){
        cin >> it.second.first >> it.second.second >> it.first;
        it.second.first--, it.second.second--;
    }
    sort(edges.begin(), edges.end());

    DisjointSet raw_dsu(node_num);
    vector<pair<long long, pair<int, int>>> useful_edges;
    for (auto it : edges){
        if (raw_dsu.full_connected()) break;
        if (raw_dsu.unite(it.second)) useful_edges.push_back(it);
    }

    vector<long long> build_cost(build_num);
    vector<vector<long long>> new_edges_cost(build_num, vector<long long>(node_num));
    for (int i = 0; i < build_num; i++){
        cin >> build_cost[i];
        for (int j = 0; j < node_num; j++) cin >> new_edges_cost[i][j];
    }

    long long ans = LLONG_MAX;
    for (int mask = 0; mask < (1 << build_num); mask++){
        long long total_cost = 0;

        int node_cnt = node_num;
        vector<pair<long long, pair<int, int>>> new_edges = useful_edges;
        for (int i = 0; i < build_num; i++){
            if (mask & (1 << i)){
                total_cost += build_cost[i];
                for (int j = 0; j < node_num; j++) new_edges.push_back({new_edges_cost[i][j], {node_cnt, j}});
                node_cnt++;
            }
        }
        sort(new_edges.begin(), new_edges.end());

        DisjointSet dsu(node_cnt);
        for (auto it : new_edges){
            if (dsu.full_connected()) break;
            if (dsu.unite(it.second)) total_cost += it.first;
        }

        ans = min(ans, total_cost);
    }

    cout << ans << "\n";
    return 0;
}
