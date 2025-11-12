#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 1e4 + 5;
const int MAXM = 1e6 + 5;

struct Edge {
    int u, v, w;
    bool operator < (const Edge& x) const {
        return w < x.w;
    }
} es[MAXM + MAXN * 10];

int n, m, k, kc[10][MAXN], ec, fa[MAXN + 10];

// int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

int find(int x) {
    while (x != fa[x]) x = fa[x] = fa[fa[x]];
    return x;
}

ll kruskal(int sel) {
    ll ans = 0;
    int need = n + __builtin_popcount(sel), cnt = 0;
    for (int i = 1; i <= n + k; ++i) {
        fa[i] = i;
        if (i > n && (sel & (1 << (i - n - 1)))) ans += kc[i - n - 1][0];
    }
    for (int i = 1; i <= ec; ++i) {
        int u = es[i].u, v = es[i].v;
        if (u > n && !(sel & (1 << (u - n - 1)))) continue;
        int fu = find(u), fv = find(v);
        if (fu == fv) continue;
        fa[fu] = fv;
        ans += es[i].w;
        if (++cnt == need) break;
    }
    return ans;
}

char gc() {
    static char B[1 << 20], *S = B, *T = B;
    if (S == T) {
        S = B;
        T = B + fread(B, 1, sizeof(B), stdin);
    }
    if (S == T) return EOF;
    return *S++;
    // return (S == T ? (((T = B + fread(S = B, 1, sizeof(B), stdin)) == B) ? EOF : *S++) : *S++);
}

int readint() {
    int x = 0;
    bool flg = 0;
    char ch = gc();
    while (ch < '0' || ch > '9') flg ^= (ch == '-'), ch = gc();
    while (ch >= '0' && ch <= '9') x = (x << 1) + (x << 3) + (ch ^ 48), ch = gc();
    return x * (flg ? -1 : 1);
}

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    // scanf("%d%d%d", &n, &m, &k);
    n = readint(); m = readint(); k = readint();
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        // scanf("%d%d%d", &u, &v, &w);
        u = readint(); v = readint(); w = readint();
        es[i] = { u, v, w };
    }
    ec = m;
    bool flagA = true;
    for (int i = 0; i < k; ++i) {
        // scanf("%d", &kc[i][0]);
        kc[i][0] = readint();
        flagA &= (kc[i][0] == 0);
        bool tmp = false;
        for (int j = 1; j <= n; ++j) {
            // scanf("%d", &kc[i][j]);
            kc[i][j] = readint();
            es[++ec] = { i + n + 1, j, kc[i][j] };
            tmp |= !kc[i][j];
        }
        flagA &= tmp;
    }
    sort(es + 1, es + ec + 1);
    if (flagA) {
        printf("%lld\n", kruskal((1 << k) - 1));
        return 0;
    }
    ll lim = kruskal(0);
    ll ans = lim;
    int mask = 0;
    for (int i = 0; i < k; ++i) {
        ll tmp = kruskal(1 << i);
        if (tmp > lim) mask |= (1 << i);
        else ans = min(ans, tmp);
    }
    for (int i = 1; i < (1 << k); ++i) {
        if ((i & mask) || __builtin_popcount(i) == 1) continue;
        ans = min(ans, kruskal(i));
    }
    printf("%lld\n", ans);
    return 0;
}