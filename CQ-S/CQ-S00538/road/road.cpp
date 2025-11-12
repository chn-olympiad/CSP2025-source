#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
#define endl '\n'
const int N = 10000 + 10;
const int M = 2e6 + 10;
int n, m, k;
struct edge {
    int u, v, w;
}e[M];
bool cmp (edge x, edge y) {
    return x.w < y.w;
}
int f[N];
int find (int x) {
    if (f[x] == x) return x;
    return f[x] = find(f[x]);
}
int etot;
ll solve () {
    for (int i = 1; i <= n + k; i ++) f[i] = i;
    ll res = 0;
    for (int i = 1; i <= etot; i ++) {
        int u = find(e[i].u), v = find(e[i].v);
        if (u != v) {
            f[u] = v;
            res += e[i].w;
        }
    }
    return res;
}
int dis[N];
bool vis[N];
bool mark[N];
int g[1010][1010];
int cost[12][N];
int main() {   
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    clock_t __c = clock();
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> k;
    if (k == 0) {
        etot = m;
        for (int i = 1; i <= m; i ++)
            cin >> e[i].u >> e[i].v >> e[i].w;
        sort (e + 1, e + 1 + m, cmp);
        cout << solve() << endl;
    } else {
        memset(g, 0x3f, sizeof g);
        for (int i = 1; i <= m; i ++) {
            cin >> e[i].u >> e[i].v >> e[i].w;
            g[e[i].u][e[i].v] = min(e[i].w, g[e[i].u][e[i].v]);
            g[e[i].v][e[i].u] = min(e[i].w, g[e[i].v][e[i].u]);
        }
        bool ok = 1;
        for (int i = 1; i <= k; i ++) {
            cin >> cost[i][0];
            if (cost[i][0] != 0) ok = 0;
            for (int j = 1; j <= n; j ++) cin >> cost[i][j];
        }
        if (ok) {
            etot = m;
            for (int i = 1; i <= k; i ++) {
                mark[i] = 1;
                for (int j = 1; j <= n; j ++) e[++ etot] = {n + i, j, cost[i][j]};
            }
            sort (e + 1, e + 1 + etot, cmp);
            cout << solve() << endl;
        } else {
            ll ans = 1e18;
            // cout << solve() << endl;
            for (int s = 0; s < (1 << k); s ++) {
                ll res = 0;
                etot = m;
                for (int i = 0; i < k; i ++) {
                    if (s >> i & 1) {
                        mark[i + 1] = 1;
                        res += cost[i + 1][0];
                        for (int u = 1; u <= n; u ++) e[++ etot] = {i + 1, u, cost[i + 1][u]};
                    } else mark[i + 1] = 0;
                }
                sort (e + 1, e + 1 + etot, cmp);
                ans = min(ans, res + solve());
            }
            cout << ans << endl;
        }
    }
    cerr << endl << "RUNTIMES: " << clock() - __c;
    return 0;
}
// 放平心态，没事的