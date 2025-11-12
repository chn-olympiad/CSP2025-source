#include <bits/stdc++.h>
#define ll long long 
using namespace std;

const int N = 2e6 + 10;
const int M = 12;
int n, m, K;
int c[M], a[M][N];
int mp[M][N];

struct edge{
    int u, v, w, pl;

    bool operator < (const edge &x) const {
        return w < x.w;
    }
}e1[N], e2[N];

struct DSU{
    int fa[N], sz[N];

    void init() {
        for (int i = 1; i <= n + K + 1; i++) fa[i] = i, sz[i] = 1;
    }
    int fd(int x) {
        if (x == fa[x]) return x;
        return fa[x] = fd(fa[x]);
    }
}D;

ll kruskal1() {
    int cnt = 0;
    ll ans = 0;
    sort(e1 + 1, e1 + m + 1);
    for (int i = 1; i <= m; i++) {
        if (cnt == n - 1) break;
        edge k = e1[i];
        int u = k.u, v = k.v;
        u = D.fd(u), v = D.fd(v);
        if (u == v) continue;
        e2[++cnt] = {u, v, k.w, -1};
        if (D.sz[u] > D.sz[v]) swap(u, v);
        D.fa[u] = v, D.sz[v] += D.sz[u], ans += k.w;
    }
    return ans;
}
ll kruskal2(int tp) {
    int cnt = 0;
    ll ans = 0;
    int ct = __builtin_popcount(tp);
    for (int i = 1; i <= m; i++) {
        if (e2[i].pl != -1) {
            if (!((1 << e2[i].pl) & tp)) continue;
        }
        if (cnt == ct + n - 1) break;
        edge k = e2[i];
        int u = k.u, v = k.v;
        u = D.fd(u), v = D.fd(v);
        if (u == v) continue;
        if (D.sz[u] > D.sz[v]) swap(u, v);
        D.fa[u] = v, D.sz[v] += D.sz[u], ans += k.w;
    }
    return ans;
}

signed main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios :: sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m >> K;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        e1[i] = {u, v, w, -1};
    }
    D.init();
    ll tmp = kruskal1(), ans = tmp;
    m = n - 1;
    for (int i = 0; i < K; i++) {
        cin >> c[i];
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            e2[++m] = {n + i + 1, j, a[i][j], i};
        }
    }
    // for (int i = 1; i <= m; i++) {
    //     cout << e2[i].u << ' ' << e2[i].v << ' ' << e2[i].w << '\n';
    // }
    sort(e2 + 1, e2 + m + 1);
    // for (int i = 1; i < n; i++) {5182974424
    for (int i = 0; i < (1 << K); i++) {
        ll res = 0;
        for (int j = 0; j < K; j++) {
            if (!((1 << j) & i)) continue;
            res += c[j];
        }
        D.init();
        ans = min(ans, res + kruskal2(i));
    } 
    cout << ans << '\n';
    return 0;
}