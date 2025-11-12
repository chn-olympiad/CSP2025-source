// 60 pts

#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

struct DSU {
    vector<int> fa, siz;

    DSU(int n) 
        : fa(n)
        , siz(n, 1)
    {
        iota(fa.begin(), fa.end(), 0);
    }

    int leader(int u) { return u == fa[u] ? u : fa[u] = leader(fa[u]); }
    bool same(int u, int v) { return leader(u) == leader(v); }

    void merge(int u, int v)
    {
        u = leader(u);
        v = leader(v);

        if (u == v)
            return;

        if (siz[u] < siz[v])
            swap(u, v);

        siz[u] += siz[v];
        fa[v] = u;
    }
};

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> deg(n + k + 1);
    vector<array<int, 3>> edges(m);

    for (int i = 0; i < m; ++i)
        cin >> edges[i][1] >> edges[i][2] >> edges[i][0];

    for (int i = n + 1; i <= n + k; ++i) {
        int _;
        cin >> _;

        for (int j = 1; j <= n; ++j) {
            int w;
            cin >> w;
            edges.push_back({ w, i, j });
            ++m;
        }
    }
    
    i64 ans = 0;
    DSU uf(n + k + 1);
    vector<int> weight(n + k + 1);
    sort(edges.begin(), edges.end());

    for (int i = 0; i < m; ++i) {
        if (uf.same(edges[i][1], edges[i][2]))
            continue;

        ans += edges[i][0];
        uf.merge(edges[i][1], edges[i][2]);
        weight[edges[i][1]] = edges[i][0];
        weight[edges[i][2]] = edges[i][0];
        ++deg[edges[i][1]];
        ++deg[edges[i][2]];
    }

    for (int i = n + 1; i <= n + k; ++i) {
        if (deg[i] == 1)
            ans -= weight[i];
    }
    
    cout << ans << endl;
    return 0;
}