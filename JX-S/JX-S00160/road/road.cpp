#include<bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
using namespace std;
const int N = 1e4 + 5, M = 1e6 + 5;
struct node {
    int u, v, w;
} e[M * 11];
ll ans, sum, res;
int n, m, k, cnt, idx, c[N], fa[N], val[N], a[12][N];
inline bool cmp (node x, node y) {return x.w < y.w;}
int find (int u) {return u == fa[u] ? u : fa[u] = find(fa[u]);}
int main () {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &k), idx = n;
    FOR(i, 1, m) scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
    FOR(i, 1, n) fa[i] = i;
    sort(e + 1, e + 1 + m, cmp);
    for (int i = 1, p, q, u, v, w; i <= m; i++) {
        u = e[i].u, v = e[i].v, w = e[i].w, p = find(u), q = find(v);
        if (p != q) {
            fa[p] = q, ans += w;
            if (++cnt == n - 1) break;
        }
    }
    if (!k) printf("%lld", ans), exit(0);
    FOR(i, 1, k) {
        scanf("%d", &c[i]), sum += c[i];
        FOR(j, 1, n) scanf("%d", &a[i][j]);
    }    
    if (n <= 1000) {
        ans = cnt = 0;
        FOR(i, 1, n) fa[i] = i;
        if (!sum) {
            FOR(i, 1, k) FOR(j, 1, n) FOR(t, j + 1, n) e[++m] = {j, t, a[i][j] + a[i][t]};
            sort(e + 1, e + 1 + m, cmp);
            for (int i = 1, p, q, u, v, w; i <= m; i++) {
                u = e[i].u, v = e[i].v, w = e[i].w, p = find(u), q = find(v);
                if (p != q) {
                    fa[p] = q, ans += w;
                    if (++cnt == n - 1) break;
                }
            } 
            printf("%lld", ans);
        }
        exit(0);
    }
    res = ans, ans = sum = cnt = 0;
    FOR(i, 1, k) FOR(j, 1, n) {
        e[++m] = {j, ++idx, a[i][j]};
        e[++m] = {idx, ++idx, c[i]};
        e[++m] = {idx, j, a[i][j]};
    }
    FOR(i, 1, idx) fa[i] = i;
    sort(e + 1, e + 1 + m, cmp);    
    for (int i = 1, p, q, u, v, w; i <= m; i++) {
        u = e[i].u, v = e[i].v, w = e[i].w, p = find(u), q = find(v);
        if (p != q) {
            fa[p] = q, ans += w;
            if (++cnt == idx - 1) break;          
        }
    }
    printf("%lld", min(res, ans));//cuo jie
    return 0;
}//zhe shi bao li dui pai (qian wan bie jiao cuo!!!