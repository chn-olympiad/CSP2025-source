#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

typedef long long ll;
const ll INF = 1e18;

struct DSU {
    vector<int> parent, rank_;
    DSU(int size) : parent(size), rank_(size, 0) {
        for (int i = 0; i < size; ++i) parent[i] = i;
    }
    int find(int x) {
        return parent[x] == x ? x : (parent[x] = find(parent[x]));
    }
    bool unite(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return false;
        if (rank_[x] < rank_[y]) parent[x] = y;
        else {
            parent[y] = x;
            if (rank_[x] == rank_[y]) rank_[x]++;
        }
        return true;
    }
};

struct Edge {
    int u, v;
    ll w;
    Edge(int u, int v, ll w) : u(u), v(v), w(w) {}
    bool operator<(const Edge& o) const { return w < o.w; }
};

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    
    int n, m, k;
    cin >> n >> m >> k;
    vector<Edge> old_edges;
    
    for (int i = 0; i < m; ++i) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        u--; v--;
        old_edges.emplace_back(u, v, w);
    }
    
    sort(old_edges.begin(), old_edges.end());
    
    vector<ll> c(k);
    vector<vector<ll>> a(k, vector<ll>(n));
    for (int j = 0; j < k; ++j) {
        cin >> c[j];
        for (int i = 0; i < n; ++i) {
            cin >> a[j][i];
        }
    }
    
    ll ans = INF;
    
    for (int mask = 0; mask < (1 << k); ++mask) {
        vector<Edge> edges = old_edges;
        ll cost = 0;
        vector<int> towns;
        
        for (int j = 0; j < k; ++j) {
            if (mask & (1 << j)) {
                cost += c[j];
                int town_id = n + j;
                towns.push_back(town_id);
                for (int i = 0; i < n; ++i) {
                    edges.emplace_back(i, town_id, a[j][i]);
                }
            }
        }
        
        int total_nodes = n + towns.size();
        DSU dsu(total_nodes);
        ll mst = 0;
        int cnt = 0;
        
        for (auto& e : edges) {
            if (dsu.unite(e.u, e.v)) {
                mst += e.w;
                cnt++;
                if (cnt == total_nodes - 1) break;
            }
        }
        
        ans = min(ans, cost + mst);
    }
    
    cout << ans << endl;
    return 0;
}