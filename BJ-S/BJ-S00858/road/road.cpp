#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e4 + 15, M = 2e6 + 5, logN = 15;
int n, m, k, c[15], w[15][N], fa[N], f[N][logN], ans = 1e18;
struct Edge {
    int u, v, w;
} a[M], backup[M];

int getfa (int x) {
    if (x == fa[x]) return x;
    return fa[x] = getfa(fa[x]);
}

bool cmp (Edge x, Edge y) {
    return x.w < y.w;
}

void work (int x) {
    int res = 0, tm = m;
    for (int i = 1; i <= tm; ++i)
        backup[i] = a[i];
    for (int i = 1; i <= n + k; ++i)
        fa[i] = i;
    for (int i = 1; i <= k; ++i) {
        if ((x >> (i - 1)) & 1) {
            res += c[i];
            for (int j = 1; j <= n; ++j)
                a[++ m] = (Edge) {j, i + n, w[i][j]};
        }
    }
    sort (a + 1, a + m + 1, cmp);
    for (int i = 1; i <= m; ++i) {
        int fax = getfa(a[i].u), fay = getfa(a[i].v);
        if (fax == fay) continue ;
        res += a[i].w;
        fa[fax] = fay;
    }
    ans = min(ans, res);
    for (int i = 1; i <= tm; ++i)
        a[i] = backup[i];
    m = tm;
}

signed main () {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf ("%lld %lld %lld", &n, &m, &k);
    for (int i = 1; i <= m; ++i)
        scanf ("%lld %lld %lld", &a[i].u, &a[i].v, &a[i].w),
        backup[i] = a[i];
    bool flag = 1;
    for (int i = 1; i <= k; ++i) {
        scanf ("%lld", &c[i]);
        bool res = 0;
        for (int j = 1; j <= n; ++j)
            scanf ("%lld", &w[i][j]), res |= (w[i][j] == 0);
        res &= (c[i] == 0);
        flag &= res;
    }
    if (flag) {
        for (int i = 1; i <= k; ++i) {
            int p = 0;
            for (int j = 1; j <= n; ++j)
                if (w[i][j] == 0) p = j;
            for (int j = 1; j <= n; ++j)
                if (p != j) a[++m] = (Edge) {p, j, w[i][j]};
        }
        for (int i = 1; i <= n; ++i)
            fa[i] = i;
        sort (a + 1, a + m + 1, cmp);
        int res = 0;
        for (int i = 1; i <= m; ++i) {
            int fax = getfa(a[i].u), fay = getfa(a[i].v);
            if (fax == fay) continue ;
            res += a[i].w;
            fa[fax] = fay;
        }
        printf ("%lld\n", res);
        return 0;
    }
    for (int i = 1; i <= n + k; ++i)
        fa[i] = i;
    int tm = 0;
    sort (a + 1, a + m + 1, cmp);
    for (int i = 1; i <= m; ++i) {
        int fax = getfa(a[i].u), fay = getfa(a[i].v);
        if (fax == fay) continue ;
        fa[fax] = fay;
        a[++tm] = a[i];
    }
    m = tm;
    for (int i = 0; i < (1 << k); ++i)
        work(i);
    printf ("%lld\n", ans);
    return 0;
}
/*
4 4 1
1 4 6
2 4 5
3 4 4
2 3 7
0 1 6 0 5
*/
