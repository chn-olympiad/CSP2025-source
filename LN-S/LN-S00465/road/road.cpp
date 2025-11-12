#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6 + 10;
const int K = 1e4 + 10;
const int M = 30;
int n, m, k, tp, c[N], p[K][M], d[N], f[N];
ll res;
struct edge {
    int s, t, v;
} e[N], nwe[N];
bool operator < (const edge &A, const edge &B) {
    return A.v < B.v;
}
int gf(int x) {
    if (f[x] == x)
        return x;
    return f[x] = gf(f[x]);
}
ll Kruskal() {
    ll ret = 0;
    for (int i = 1; i <= n; i++)
        f[i] = i;
    for (int i = 1; i <= tp; i++) {
        int x = nwe[i].s, y = nwe[i].t;
        if (gf(x) != gf(y)) {
            f[x] = gf(y);
            ret += 1LL * nwe[i].v;
        }
    }
    return ret;
}
ll solve() {
    ll ans = 0;
    tp = 0;
    for (int i = 1; i <= k; i++)
        if (d[i])
            ans += 1LL * (c[i] + p[i][i]);
    for (int i = 1; i <= m; i++)
       nwe[++tp] = e[i];
    for (int i = 1; i <= k; i++)
        for (int j = 1; j <= n; j++)
            if (i != j && d[i])
                nwe[++tp].s = min(i, j), nwe[tp].t = max(i, j), nwe[tp].v = p[i][j];
    sort(nwe + 1, nwe + tp + 1);
    ans += Kruskal();
    return ans;
}
void dfs(int tp) {
    if (tp == k + 1) {
        res = min(res, solve());
        return;
    }
    d[tp] = 1;
    dfs(tp + 1);
    d[tp] = 0;
    dfs(tp + 1);
}
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    res = 1LL << 60LL;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= m; i++)
        scanf("%d%d%d", &e[i].s, &e[i].t, &e[i].v);
    for (int i = 1; i <= m; i++)
        if (e[i].s > e[i].t)
            swap(e[i].s, e[i].t);
    for (int i = 1; i <= k; i++) {
        scanf("%d", &c[i]);
        for (int j = 1; j <= n; j++)
            scanf("%d", &p[i][j]);
    }
    dfs(1);
    printf("%lld\n", res);
    return 0;
}
