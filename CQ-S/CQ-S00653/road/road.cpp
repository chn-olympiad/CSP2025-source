#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 1e5 + 5;
const int M = 1e5 + 1e4 + 5;
struct node {
    int u, v, w, typ;
    friend bool operator < (node x, node y) {
        return x.w < y.w;
    }
} e[N], e2[M];
int ncnt = 0;
struct DSU {
    vector<int> fa, siz;
    int n;
    DSU(int _n) : n(_n) {
        fa.assign(n + 1, 0);
        siz.assign(n + 1, 1);
        iota(fa.begin(), fa.end(), 0);
    }
    int find(int x) {
        if (x == fa[x]) return x;
        return fa[x] = find(fa[x]);
    }
    void unite(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return;
        if (siz[u] < siz[v]) swap(u, v);
        fa[v] = u;
        siz[u] += siz[v];
    }
};
int n, k;
using ll = long long;
int ecnt = 0;
ll kruskal() {
    DSU dsu(n + k);
    ll ans = 0;
    for (int i = 1; i <= ncnt; i++) {
        if (e[i].typ != 0) {
            e2[++ecnt] = e[i];
            continue;
        }
        int u = e[i].u, v = e[i].v;
        if (dsu.find(u) == dsu.find(v)) continue;
        dsu.unite(u, v);
        e2[++ecnt] = e[i];
        ans += e[i].w;
    }
    return ans;
}
bool vis[N];
ll kruskal2() {
    DSU dsu(n + k);
    ll ans = 0;
    for (int i = 1; i <= ecnt; i++) {
        if (!vis[e2[i].typ]) continue;
        int u = e2[i].u, v = e2[i].v;
        if (dsu.find(u) == dsu.find(v)) continue;
        dsu.unite(u, v);
        ans += e2[i].w;
    }
    return ans;
}
int a[11][N], c[N];
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int m;
    cin >> n >> m >> k;
    ncnt = m;
    for (int i = 1; i <= m; i++) {
        cin >> e[i].u >> e[i].v >> e[i].w;
        e[i].typ = 0;
    }
    vis[0] = 1;
    for (int i = 1; i <= k; i++) {
        cin >> c[i];
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            e[++ncnt] = {i + n, j, a[i][j], i};
        }
    }
    sort(e + 1, e + 1 + ncnt);
    kruskal();
    ll ans = LLONG_MAX;
    for (int i = 0; i < (1 << k); i++) {
        ll sum = 0;
        for (int j = 1; j <= k; j++) {
            if (i >> (j - 1) & 1) {
                vis[j] = 1;
                sum += c[j];
            }
        }
        ans = min(ans, kruskal2() + sum);
        for (int j = 1; j <= k; j++) {
            if (i >> (j - 1) & 1) {
                vis[j] = 0;
            }
        }
    }
    cout << ans;
    return 0;
}