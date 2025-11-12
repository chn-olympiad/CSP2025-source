#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N = 1e4 + 5, M = 11, P = 1e6 + 5, inf = 1e18;
int n, m, k, ans, f[N][1 << M], g[N][1 << M], h[1 << M], v[M][N], c[M], fa[N];
struct edge {
    int x, y, w;
}e[P];
vector<edge> E;
inline int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
inline void kruskal() {
    sort(e + 1, e + 1 + m, [](edge a, edge b) {
        return a.w < b.w;
    });
    iota(fa, fa + 1 + n, 0);
    int cnt = 0;
    for(int i = 1; i <= m; i++) {
        auto [x, y, w] = e[i];
        x = find(x), y = find(y);
        if(x != y) {
            fa[y] = x;
            E.push_back({x, y, w}), cnt++;
        }
        if(cnt == n - 1) break;
    }
}
signed main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n >> m >> k;
    for(int i = 1, x, y, w; i <= m; i++) {
        cin >> x >> y >> w;
        e[i] = {x, y, w};
    }
    for(int i = 1; i <= k; i++) {
        cin >> c[i];
        for(int j = 1; j <= n; j++) cin >> v[i][j];
    }
    kruskal();
    iota(fa, fa + 1 + n, 0);
    memset(f, 0x3f, sizeof f);
    for(int i = 1; i <= n; i++) {
        for(int s = 0; s < 1 << k; s++) {
            g[i][s] = inf;
            for(int j = 1; j <= k; j++) {
                if(s >> j - 1 & 1) g[i][s] = min(g[i][s], v[j][i]);
            }
        }
        f[i][0] = 0;
    }
    for(auto [x, y, w] : E) {
        x = find(x), y = find(y);
        for(int s = 0; s < 1 << k; s++) {
            f[0][s] = inf;
            h[s] = inf;
            for(int t = s; ; t = t - 1 & s) {
                f[0][s] = min(f[0][s], f[x][s ^ t] + f[y][t] + w);
                f[0][s] = min(f[0][s], f[x][s ^ t] + f[y][t] + min(g[y][s ^ t], g[x][t]));
                h[s] = min(h[s], f[x][s ^ t] + f[y][t]);
                if(!t) break;
            }
        }
        for(int s = 0; s < 1 << k; s++) {
            for(int i = 1; i <= k; i++) {
                if((s >> i - 1 & 1)) f[0][s] = min(f[0][s], h[s ^ 1 << i - 1] + g[x][1 << i - 1] + g[y][1 << i - 1] + c[i]);
            }
        }
        fa[y] = x;
        for(int s = 0; s < 1 << k; s++) {
            f[x][s] = f[0][s];
            g[x][s] = min(g[x][s], g[y][s]);
        }
    }
    int ans = inf;
    for(int i = 1; i <= n; i++) {
        if(fa[i] == i) {
            for(int s = 0; s < 1 << k; s++) ans = min(ans, f[i][s]);
            break;
        }
    }
    cout << ans;
    return 0;
}