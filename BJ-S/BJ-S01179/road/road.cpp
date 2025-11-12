#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e4 + 5, M = 1e6 + 5; const ll inf = 1e18;
int n, m, k, cnt, f[N], a[10][N], c[10]; struct Edge { int u, v, w; bool operator < (const Edge &r) { return w < r.w; } } e[M];
int Find(int x) { return x == f[x] ? x : (f[x] = Find(f[x])); } vector <pair<int,int> > tr[N]; ll dp[N][1024];
void dfs(int u, int fa) {
    if(u != 1 && tr[u].size() == 1) {
        for(int i = 0; i < (1 << k); i++) {
            dp[u][i] = 0;
            for(int j = 0; j < k; j++) if((i >> j) & 1) dp[u][i] += c[j] + a[j][u];
        }
        return ;
    }
    for(auto x : tr[u]) if(x.first != fa) dfs(x.first, u);
    for(int i = 1; i < (1 << k); i++) dp[u][i] = inf;
    for(auto x : tr[u]) {
        int v = x.first, w = x.second; if(v == fa) continue ;
        dp[u][0] += w + dp[v][0];
        for(int S = 1; S < (1 << k); S++) {
            if(dp[u][S] == inf) {
                dp[u][S] = w;
                for(int t = 0; t < k; t++)
                    if((S >> t) & 1) dp[u][S] = min(dp[u][S], a[t][u] * 1ll);
                // printf("%d %lld\n", S, dp[u][S]);
                dp[u][S] += dp[v][S];
            }
            else {
                ll mn = inf;
                for(int i = S; i; i = (i - 1) & S) if(S & i) mn = min(mn, dp[v][i]);
                mn = min(mn, w + min(dp[v][0], dp[v][S])); 
                dp[u][S] += mn;
            }
            for(int i = 0; i < k; i++) if(!((S >> i) & 1)) dp[u][S^(1<<i)] = min(dp[u][S^(1<<i)], dp[u][S] + a[i][u] + c[i]);
        }
    // printf("Node %d v:%d\n", u, v);
    // for(int S = 0; S < (1 << k); S++) printf("S:%d dp:%lld\n", S, dp[u][S]);
    }
}
int main() {
    freopen("road.in", "r", stdin); freopen("road.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= m; i++) scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
    for(int i = 0; i < k; i++) { scanf("%d", &c[i]); for(int j = 1; j <= n; j++) scanf("%d", &a[i][j]); }
    for(int i = 1; i <= n; i++) f[i] = i; sort(e + 1, e + m + 1);
    ll ans = 0;
    for(int i = 1; i <= m; i++) {
        int u = Find(e[i].u), v = Find(e[i].v);
        if(u == v) continue ; cnt++, f[u] = v, ans += e[i].w;
        tr[e[i].u].push_back({e[i].v, e[i].w});
        tr[e[i].v].push_back({e[i].u, e[i].w});
        if(cnt == n - 1) break;
    }
    if(k == 0) return printf("%lld\n", ans), 0;
    dfs(1, 0);
    ans = inf; for(int i = 0; i < (1 << k); i++) ans = min(ans, dp[1][i]);
    printf("%lld\n", ans);
    return 0;
}