#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;

    Edge (int u_ = 0, int v_ = 0, int w_ = 0) : u(u_), v(v_), w(w_) {}

    bool operator < (const Edge &cmp) const {
        return w < cmp.w;
    }
};

struct Union {
    vector<int> fas;

    Union (int n) : fas(n + 5) {
        for (int i = 1; i <= n; i++) fas[i] = i;
    }

    int find (int x) {
        return fas[x] == x ? x : fas[x] = find(fas[x]);
    }

    bool merge (int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return false;
        fas[y] = x;
        return true;
    }

    void assign (int n) {
        fas.assign(n + 5, 0);
        for (int i = 1; i <= n; i++) fas[i] = i;
    }
};

vector<vector<pair<int, int>>> g;

bool dfs (int n, vector<bool> &vis, int u, int fa = 0) {
    bool flag = u <= n;
    for (pair<int, int> i : g[u]) {
        int v, w; tie(v, w) = i;
        if (v == fa) continue;
        flag |= dfs(n, vis, v, u);
    }
    if (!flag) vis[u] = false;
    return flag;
}

int main () {

    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k, x, y, z;
    cin >> n >> m >> k;
    vector<Edge> e, ne;
    vector<int> a(k + 5);
    for (int i = 1; i <= m; i++) {
        cin >> x >> y >> z;
        e.emplace_back(x, y, z);
    }
    for (int i = 1; i <= k; i++) {
        cin >> a[i];
        for (int j = 1; j <= n; j++) {
            cin >> x;
            ne.emplace_back(n + i, j, x + a[i]);
        }
    }
    sort(e.begin(), e.end());
    Union dsu(n);
    for (int i = 0; i < m; i++) {
        if (dsu.merge(e[i].u, e[i].v)) {
            ne.emplace_back(e[i]);
        }
    }
    sort(ne.begin(), ne.end());
    vector<bool> vis(k + 5);
    dsu.assign(n + k);
    g.resize(n + k + 5);
    m = ne.size();
    for (int i = 0; i < m; i++) {
        if (dsu.merge(ne[i].u, ne[i].v)) {
            if (ne[i].u > n && !vis[ne[i].u - n]) {
                vis[ne[i].u - n] = true;
                for (int j = i; j < m; j++) {
                    if (ne[i].u == ne[j].u) ne[j].w -= a[ne[i].u - n];
                }
                sort(ne.begin() + i + 1, ne.end());
            }
            g[ne[i].u].emplace_back(ne[i].v, ne[i].w);
            g[ne[i].v].emplace_back(ne[i].u, ne[i].w);
        }
    }
    vis.assign(n + k + 5, true);
    dfs(n, vis, 1);
    long long ans = 0;
    for (int u = 1; u <= n + k; u++) if (vis[u]) {
        for (pair<int, int> i : g[u]) {
            int v, w; tie(v, w) = i;
            if (v > u && vis[v]) ans += w;
        }
    }
    for (int i = n + 1; i <= n + k; i++) {
        if (vis[i]) ans += a[i - n];
    }
    cout << ans;
    return 0;
}

// Why the last big sample is wrong???
// I think my code is correct!!!
