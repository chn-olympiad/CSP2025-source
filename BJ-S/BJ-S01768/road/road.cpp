// 15:09 AC T1
// graph
#include <bits/stdc++.h>
using namespace std;
#define gc_u getchar_unlocked
int read(int x = 0, char c = gc_u()) {
    while (!isdigit(c)) c = gc_u();
    while (isdigit(c)) x = (x << 3) + (x << 1) + c - '0', c = gc_u();
    return x;
}
const int N = 1e4 + 5, M = 1e6 + 5, K = 15;
int n, m, k, tot, num;
long long c[K], a[K][N], fa[2 * N], siz[2 * N];
struct edge {int u, v; long long w;} e[M], ee[2 * M];
const bool cmp(const edge &x, const edge &y) {return x.w < y.w;}
int getfa(int x) {
    if (fa[x] == x) return x;
    return fa[x] = getfa(fa[x]);
}
void merge(int x, int y) {
    if (siz[x] < siz[y]) siz[y] += siz[x], fa[x] = y;
    else siz[x] += siz[y], fa[y] = x;
}
long long kruskal() {
    sort(ee + 1, ee + tot + 1, cmp);
    for (int i = 1; i <= num; i++) fa[i] = i, siz[i] = 1;
    int cnt = 0; long long res = 0;
    for (int i = 1; i <= tot; i++) {
        int u = ee[i].u, v = ee[i].v, w = ee[i].w;
        int fu = getfa(u), fv = getfa(v);
        if (fu == fv) continue;
        merge(fu, fv);
        res += w; cnt++;
        if (cnt == num) break;
    }
    return res;
}
void subtaska() {
    for (int i = 1; i <= m; i++) ee[i] = e[i];
    tot = m; num = n;
    for (int i = 1; i <= k; i++) {
        num++;
        for (int j = 1; j <= n; j++) {
            ee[++tot] = {num, j, a[i][j]};
        }
    }
    // cout << kruskal() << '\n';
    printf("%lld\n", kruskal());
    return;
}
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    // ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // cin >> n >> m >> k;
    n = read(), m = read(), k = read();
    for (int i = 1; i <= m; i++) {
        // cin >> e[i].u >> e[i].v >> e[i].w;
        e[i].u = read(), e[i].v = read(), e[i].w = read();
    }
    bool flaga = true;
    for (int i = 1; i <= k; i++) {
        // cin >> c[i];
        c[i] = read();
        if (c[i] != 0) flaga = false;
        bool flag = false;
        for (int j = 1; j <= n; j++) {
            // cin >> a[i][j];
            a[i][j] = read();
            if (a[i][j] == 0) flag = true;
        }
        if (!flag) flaga = false;
    }
    if (flaga) {
        subtaska();
        return 0;
    }
    long long ans = 1e18;
    for (int s = 0; s < (1 << k); s++) {
        for (int i = 1; i <= m; i++) ee[i] = e[i];
        tot = m; num = n; long long tmp = 0;
        for (int i = 1; i <= k; i++) {
            if (s & (1 << (i - 1))) {
                num++; tmp += c[i];
                for (int j = 1; j <= n; j++) {
                    ee[++tot] = {num, j, a[i][j]};
                }
            }
        }
        ans = min(ans, tmp + kruskal());
    }
    // cout << ans << '\n';
    printf("%lld\n", ans);
    return 0;
}