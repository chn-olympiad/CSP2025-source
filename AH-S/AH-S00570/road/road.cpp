#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, m, k;
typedef pair <int, int> pii;
const ll inf = 1e15;
const int N = 1e4 + 25, M = 2e6 + 10;
const int K = (1ll << 10) + 5;
struct edge {
    int a, b, w;
    bool operator < (const edge &W) const {
        return w < W.w;
    }
} e[M];
int c[N];
int cnt;
int fa[N], sz[N], vis[N];
int find(int x) {
    return (x == fa[x]) ? x : fa[x] = find(fa[x]);
}
signed main(void) {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i ++) {
        int u, v, w;
        cin >> u >> v >> w;
        e[++ cnt] = {u, v, w};
    }
    for (int i = 1; i <= k; i ++) {
        cin >> c[i + n];
        for (int j = 1; j <= n; j ++) {
            int w;
            cin >> w;
            e[++ cnt] = {j, n + i, w};
        }
    }
    sort(e + 1, e + cnt + 1);
    ll ans = inf;
    for (int i = 0; i < (1ll << k); i ++) {
        int sum = 0;
        int gi = i;
        while (gi) {
            sum += gi % 2;
            gi /= 2;
        }
        for (int j = 1; j <= n + k; j ++) {
            fa[j] = j;
            sz[j] = 1;
            vis[j] = 0;
        }
        ll res = 0;
        for (int j = 1; j <= cnt; j ++) {
            int na = e[j].a, nb = e[j].b, nw = e[j].w;
            na = find(na);
            nb = find(nb);
            if(sz[na] == n + sum) break ;
            int f1 = 1, f2 = 1;
            if(na > n) {
                f1 = ((i >> (na - n - 1)) & 1);
            }
            if(nb > n) {
                f2 = ((i >> (nb - n - 1)) & 1);
            }
            if(!f1 || !f2) continue ;
            if(na != nb) {
                if(!vis[na]) res += c[na];
                if(!vis[nb]) res += c[nb];
                vis[na] = vis[nb] = 1;
                res += nw;
                if(sz[na] > sz[nb]) swap(na, nb);
                fa[na] = nb;
                sz[na] = sz[na] + sz[nb];
                sz[nb] = sz[na];
            }
        }
        ans = min(ans, res);
    }
    cout << ans << endl;
    return 0;
}
