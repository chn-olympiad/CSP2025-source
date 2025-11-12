#include <bits/stdc++.h>
#define int long long
#define rep(x, y, z) for (int x = (y); x <= (z); ++x)
#define per(x, y, z) for (int x = (y); x >= (z); --x)
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
constexpr int maxm = 1.1e6 + 5, maxn = 1e4 + 25;
int n, m, k, c[15];
struct edge {int u, v, w, id;} e[maxm]; int te;
bool vis[15]; int deg[15];
struct DSU {
    int fa[maxn];
    void init() {rep(i, 1, n + k) fa[i] = i;}
    inline int find(int u) {return fa[u] == u ? u : fa[u] = find(fa[u]);}
    bool merge(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return false;
        fa[u] = v; return true;
    }
} dsu;
int kruskal() {
    dsu.init();
    memset(deg, 0, sizeof deg);
    int res = 0;
    rep(i, 1, m + n * k) {
        auto &[u, v, w, id] = e[i];
        if (vis[id]) continue;
        if (!dsu.merge(u, v)) continue;
        res += w; ++deg[id];
    }
    rep(i, 1, k) if (!vis[i]) res += c[i];
    return res;
}
int a[15];
signed main() {
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m >> k; te = m;
    rep(i, 1, m) {
        auto &[u, v, w, id] = e[i];
        cin >> u >> v >> w; id = 0;
    }
    rep(i, 1, k) {
        cin >> c[i]; a[i] = i;
        rep(j, 1, n) {
            int x; cin >> x;
            e[++te] = {i + n, j, x, i};
        }
    }
    sort(e + 1, e + 1 + te, [](edge e1, edge e2) {return e1.w < e2.w;});
    sort(a + 1, a + 1 + k, [](int x, int y) {return c[x] > c[y];});
    int ans = kruskal();
    rep(i, 1, k) {
        vis[a[i]] = true;
        int cur = kruskal();
        if (ans > cur) {
            ans = cur;
        } else vis[a[i]] = false;
    }
    cout << ans << endl;
    return 0;
}