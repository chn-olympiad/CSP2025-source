/*
    Author : Sparkle_ZH & Sparklee
    Right Output ! & Accepted !
*/

#include <bits/stdc++.h>
#define lowbit(x) ((x) & (- (x)))
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define ll long long
#define fir first
#define sec second
using namespace std;

template<typename T> inline void write(T x, int f = -1) {
    if (x < 0) putchar('-'), x = -x;
    static short Stack[50], top(0);
    do Stack[++ top] = x % 10, x /= 10; while (x);
    while (top) putchar(Stack[top --] | 48);
    if (~ f) putchar(f ? '\n' : ' ');
}

const int N = 1e6 + 5;
int n, m, k, cnt, c[N], fa[N], a[10][N];
ll ans, cur;
bool f[N];

int find(int i) { return fa[i] == i ? i : fa[i] = find(fa[i]); }

struct edge {
    int u, v, w, fr;
    edge(int u = 0, int v = 0, int w = 0, int fr = 0) : u(u), v(v), w(w), fr(fr) {}
    bool operator < (const edge &rhs) {
        return w < rhs.w;
    }
} e[N], g[N];

signed main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= m; i ++)
        scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].w);

    sort(e + 1, e + 1 + m);

    iota(fa, fa + 1 + n, 0);

    for (int i = 1; i <= m; i ++) {
        int x = find(e[i].u), y = find(e[i].v);
        if (x != y) g[++ cnt] = edge(e[i].u, e[i].v, e[i].w, 0), ans += e[i].w, fa[x] = y;
    }

    for (int i = 1; i <= k; i ++) {
        scanf("%d", &c[i]);
        for (int j = 1; j <= n; j ++) {
            scanf("%d", &a[i][j]);
            g[++ cnt] = edge(n + i, j, a[i][j], i);
        }
    }

    sort(g + 1, g + 1 + cnt);

    for (int t = 1; t < (1 << k); t ++) {
        cur = 0;
        for (int i = 1; i <= k; i ++)
            if ((1 << (i - 1)) & t) cur += c[i];

        iota(fa, fa + 1 + n + k, 0);

        for (int i = 1; i <= cnt; i ++) {
            if (g[i].fr && ! ((1 << (g[i].fr - 1)) & t)) continue ;
            int x = find(g[i].u), y = find(g[i].v);
            if (x != y) cur += g[i].w, fa[x] = y;
            if (cur >= ans) break;
        }

        ans = min(ans, cur);
    }

    write(ans, 1);

    return 0;
}
