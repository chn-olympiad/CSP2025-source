#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

struct DSU {
    int fa[20005], sz[20005];

    void init(int n) {
        for (int i = 1; i <= n; i++)
            fa[i] = i, sz[i] = 1;
    }

    int find(int x) {
        if (x == fa[x])
            return x;
        return fa[x] = find(fa[x]);
    }

    void unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y)
            return;
        if (sz[y] > sz[x])
            swap(x, y);
        fa[y] = x;
        sz[x] += sz[y];
    }
} dsu;

struct Edge {
    int u, v, w;

    bool operator < (const Edge &a) const {
        return w < a.w;
    }
} edges[1800005], ori[1000005];
int n, m, k, M;
int c[15], a[15][10005];
ll Kruskal(int d) {
    dsu.init(n + k);
    int cnt = 1;
    ll res = 0;
    sort(edges + 1, edges + M + 1);
    for (int i = 1; i <= M && cnt <= n + k - d; i++) {
        auto [u, v, w] = edges[i];
        if (dsu.find(u) != dsu.find(v)) {
            dsu.unite(u, v);
            res += w;
            cnt++;
        }
    }
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        cin >> ori[i].u >> ori[i].v >> ori[i].w;
    }
    for (int i = 1; i <= k; i++) {
        cin >> c[i];
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    }
    ll ans = numeric_limits<ll>::max();
    for (int mask = 0; mask < 1 << k; mask++) {
        M = m;
        for (int i = 1; i <= M; i++)
            edges[i] = ori[i];
        int diff = 0;
        ll res = 0;
        for (int i = 1; i <= k; i++) {
            if ((mask >> i - 1) & 1) {
                res += c[i];
                for (int j = 1; j <= n; j++)
                    edges[++M] = {n + i, j, a[i][j]};
            } else diff++;
        }
        if (res > ans)
            continue;
        ans = min(ans, res + Kruskal(diff));
    }
    cout << ans;
    return 0;
}
