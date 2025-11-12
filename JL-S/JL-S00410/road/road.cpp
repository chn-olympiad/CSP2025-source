#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e4 + 5, M = 1e6 + 5, K = 12;
struct Node {int u, v, w;} e[M], re[M];
int n, m, k, w[K][N], c[K], fa[N], Ans, mnAns;
bool spe1 = 1, fis = 1;
inline bool operator < (Node x, Node y) {return x.w < y.w;}
inline int find(int u) {return fa[u] == u ? u : fa[u] = find(fa[u]);}
inline void Kruskal() {
    sort(e + 1, e + 1 + m);
    for(int i = 1; i <= n; ++ i) fa[i] = i;
    int ct = 0; Ans = 0;
    for(int i = 1; i <= m; ++ i) {
        int fx = find(e[i].u), fy = find(e[i].v);
        if(fx == fy) continue;
        ++ ct, fa[fx] = fy, Ans += e[i].w;
        if(fis) re[ct] = e[i];
        if(ct == n - 1) return ;
    }
}
inline void solvespe1() {
    for(int i = 1; i <= k; ++ i) {
        for(int j = 1; j <= n; ++ j) {
            ++ m; e[m].u = n + i, e[m].v = j, e[m].w = w[i][j];
        }
    }
    n += k; Kruskal();
    cout << Ans << '\n';
}
signed main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0); cin >> n >> m >> k;
    for(int i = 1; i <= m; ++ i) cin >> e[i].u >> e[i].v >> e[i].w;
    for(int i = 1; i <= k; ++ i) {
        cin >> c[i]; if(c[i] != 0) spe1 = 0;
        int tag = 0;
        for(int j = 1; j <= n; ++ j) {cin >> w[i][j]; if(!w[i][j]) tag = 1;}
        if(!tag) spe1 = 0;
    }
    if(spe1) {solvespe1(); return 0;}
    Kruskal(); mnAns = Ans, fis = 0;
    for(int st = 1; st < (1 << k); ++ st) {
        int res = 0, dts = 0; m = n - 1;
        for(int j = 1; j < n; ++ j) e[j] = re[j];
        for(int j = 0; j < k; ++ j) if(st >> j & 1) {
            res += c[j + 1], ++ dts;
            for(int o = 1; o <= n; ++ o) {
                ++ m, e[m].u = n + dts, e[m].v = o, e[m].w = w[j + 1][o];
            }
        }
        n += dts;
        Kruskal(); mnAns = min(Ans + res, mnAns);
        n -= dts;
    }
    cout << mnAns;
    return 0;
}
// Ren5Jie4Di4Ling5%