#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ifstream fin("road.in");
ofstream fout("road.out");

bool chk_A(vector<vector<ll>> &cities) {
    int n = cities.size();
    for (int i = 0; i < n; ++i) {
        if (cities[i][0] != 0) {
            return false;
        }
    }
    return true;
}

struct DSU {
    int n;
    vector<int> parent;

    DSU(int n) : n(n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int u) {
        if (u != parent[u]) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    void join(int u, int v) {
        int ru = find(u), rv = find(v);
        if (ru != rv) {
            parent[rv] = parent[ru];
        }
    }
};

struct edge {
    int u, v;
    ll w;
};

vector<vector<int>> graph;

ll solve(int n, vector<edge>& edges) {
    graph.resize(n + 1);

    sort(edges.begin(), edges.end(), [](const edge& e1, const edge& e2) {
        return e1.w < e2.w;
    });

    DSU dsu(n + 1);
    ll ans = 0;

    for (edge &e : edges) {
        if (dsu.find(e.u) != dsu.find(e.v)) {
            dsu.join(e.u, e.v);
            ans += e.w;
            graph[e.u].push_back(e.v);
            graph[e.v].push_back(e.u);
        }
    }

    return ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m, k;
    fin >> n >> m >> k;

    vector<edge> edges(m);
    for (int i = 0; i < m; ++i) {
        fin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    // cities[i][0] = cost to build city i
    // cities[i][j] = cost to connect city i to town j
    vector<vector<ll>> cities(k, vector<ll>(n + 1));
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n + 1; ++j) {
            fin >> cities[i][j];
        }
    }

    // subtest 13, 14
    if (chk_A(cities)) {
        vector<edge> all_edges = edges;
        for (int city = 0; city < k; ++city) {
            for (int i = 1; i <= n; ++i) {
                all_edges.push_back(edge{n + city + 1, i, cities[city][i]});
            }
        }
        fout << solve(n + k, all_edges);
        return 0;
    }

    ll ans = LLONG_MAX;

    for (int mask = 0; mask < (1 << k); ++mask) {
        ll cost = 0;

        vector<int> cities_used;
        for (int i = 0; i < k; ++i) {
            if (mask & (1 << i)) {
                cities_used.push_back(i);
                cost += cities[i][0];
            }
        }

        vector<edge> edges_copy = edges;
        for (int city : cities_used) {
            for (int i = 1; i <= n; ++i) {
                edges_copy.push_back(edge{n + city + 1, i, cities[city][i]});
            }
        }

        cost += solve(n + k, edges_copy);

        // check if city is not used, then no need to build that city
        for (int city : cities_used) {
            if (graph[n + city + 1].size() == 1) {
                cost -= cities[city][0];
            }
        }

        ans = min(ans, cost);
        
        for (int i = 0; i < n + k; ++i) {
            graph[i].clear();
        }
    }

    fout << ans << '\n';
}