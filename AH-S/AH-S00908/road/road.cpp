#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int M = 1e6 + 66, N = 2e5 + 66;
int n, m, k, o[12], r[12], fa[N], c[12], a[12][10002];
struct edge { int u, v, w; } e0[M], e[N], ee[N];
bool cmp(edge e1, edge e2) { return e1.w < e2.w; }
int findfa(int x) { return x == fa[x] ? x : fa[x] = findfa(fa[x]); }
inline int read() {
    int x = 0, f = 1; char ch = getchar_unlocked();
    while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar_unlocked(); }
    while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar_unlocked();
    return x * f;
}
inline ll readl() {
    ll x = 0, f = 1; char ch = getchar_unlocked();
    while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar_unlocked(); }
    while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar_unlocked();
    return x * f;
}
signed main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    n = read(), m = read(), k = read();
    for (int i = 1;i <= m;i++) {
        int u, v, w;
        u = read(), v = read(), w = read();
        e0[i] = {u, v, w};
    }
    for (int i = 1;i <= k;i++) {
        c[i] = read();
        for (int j = 1;j <= n;j++) a[i][j] = read();
    }
    for (int i = 1;i <= n;i++) fa[i] = i;
    stable_sort(e0 + 1, e0 + 1 + m, cmp);
    int mm = 0;
    ll ans = 0;
    for (int i = 1;i <= m;i++) {
        int x = findfa(e0[i].u), y = findfa(e0[i].v);
        if (x == y) continue;
        fa[x] = y, e[++mm] = e0[i], ans += e0[i].w;
    }
    int top = (1 << k);
    for (int t = 1;t <= top;t++) {
        for (int i = 1;i <= mm;i++) ee[i] = e[i];
        int tmp = t, nn = n, nm = mm;
        ll sum = 0;
        for (int i = 1;i <= k;i++) {
            o[i] = (tmp & 1), tmp >>= 1;
            if (o[i]) {
                sum += c[i], r[i] = ++nn;
                for (int j= 1;j <= n;j++)
                    ee[++nm] = {r[i], j, a[i][j]};
            }
        }
        for (int i = 1;i <= nn;i++) fa[i] = i;
        stable_sort(ee + 1, ee + 1 + nm, cmp);
        for (int i = 1;i <= nm;i++) {
            int x = findfa(ee[i].u), y = findfa(ee[i].v);
            if (x == y) continue;
            sum += ee[i].w;
            fa[x] = y;
        }
        ans = min(ans, sum);
    }
    cout << ans;
    return 0;
}
