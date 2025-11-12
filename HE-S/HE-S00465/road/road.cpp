#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 5;
int n, m, k;
int c[15], a[15][10005];
int idx, cnt;
int f[N], tp[N];
int lt, ans;
int vis[15], lc[15];
struct Edge {
    int to, w, fr;
    friend bool operator < (Edge x, Edge y) {
        return x.w < y.w;
    }
}edge[N], tr[N];
void add1(int x, int y, int w) {
    edge[++ idx].to = y;
    edge[idx].fr = x;
    edge[idx].w = w;
}
int find(int x) {
    return f[x] == x ? f[x] : f[x] = find(f[x]);
}
void kruskal(int val, int d) {
    lt = ans;
    ans = 0;
    for (int i = 1; i <= d; i ++) vis[i] = 0, lc[i] = 0, ans += c[i];
    for (int i = 1; i <= n + d; i ++) f[i] = i;
    int cc = 0;
    sort(edge + 1, edge + idx + 1);
    for (int i = 1; i <= idx; i ++) {
        int u = find(edge[i].fr), v = find(edge[i].to);
        if (u == v) continue;
        if (u > v) swap(u, v);
        if (edge[i].to > n) vis[edge[i].to - n] ++, lc[edge[i].to - n] += edge[i].w;
        f[v] = u;
        tp[++ cc] = i;
        ans += edge[i].w;
    }
    for (int i = 1; i <= d; i ++) {
        if (!vis[i]) ans -= c[i];
        if (vis[i] == 1) ans -= (c[i] + lc[i]);
        // cout << vis[i] << endl;
    }
    if (ans < lt) {
        cnt = cc;
        for (int i = 1; i <= cnt; i ++) tr[i] = edge[tp[i]];
    } else ans = lt;
    idx = cnt;
    for (int i = 1; i <= idx; i ++) edge[i] = tr[i];
}
signed main() {
    // freopen("road4.in", "r", stdin); freopen("test.out", "w", stdout);
    freopen("road.in", "r", stdin); freopen("road.out", "w", stdout);
    scanf("%lld%lld%lld", &n, &m, &k);
    for (int i = 1; i <= m; i ++) {
        int u, v, w;
        scanf("%lld%lld%lld", &u, &v, &w);
        add1(u, v, w);
    }
    ans = 1e17;
    kruskal(0, 0);
    for (int i = 1; i <= k; i ++) {
        scanf("%lld", &c[i]);
        for (int j = 1; j <= n; j ++) {
            scanf("%lld", &a[i][j]);
            // if (a[i][j] < 1000) cout << i << " " << j << " " << a[i][j] << endl;
            add1(j, n + i, a[i][j]);
        }
        kruskal(c[i], i);
    }
    printf("%lld\n", ans);
    return 0;
}