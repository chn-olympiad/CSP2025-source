#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using i128 = __int128;
using u128 = unsigned __int128;

namespace io {
    inline i64 rd() {
        i64 s = 0, f = 1;
        char c = getchar();
        while (c < '0' || c > '9') {
            c = getchar();
        } 
        while (c >= '0' && c <= '9') {
            s = (s << 1) + (s << 3) + (c - '0');
            c = getchar();
        }
        return s * f;
    }

    static char cc[55];
    template<class T>
    inline void pt(T x, char c = '\n') {
        if (!x) {
            putchar('0'), putchar(c);
            return ;
        }
        if (x < 0) {
            x *= -1, putchar('-');
        }
        int tot = 0;
        while (x) {
            cc[++tot] = x % 10 + '0';
            x /= 10;
        }
        for (int i = tot; i; i--) {
            putchar(cc[i]);
        }
        putchar(c);
    }
    inline void ptstr(std::string s) {
        for (auto v : s) {
            putchar(v);
        }
    }
}
using io::rd;
using io::pt;
using io::ptstr;

using vi = std::vector<int> ;
using vI = std::vector<i64> ;
using str = std::string;

#define int i64

char x_x;

const int N = 1e4 + 5, M = 1e6 + 5, K = 10;
const int SM = (1 << K) + 5;

int n, m, k;
int a[N][K + 5], c[N];
struct ed {
    int u, v, w;
    bool operator <(const ed &c) const {
        return w < c.w;
    }
} e[M];
int tot;

int fa[N], mn[N][K + 1];
inline int fd(int x) {
    return x == fa[x] ? x : fa[x] = fd(fa[x]);
}
inline void mg(int u, int v) {
    u = fd(u), v = fd(v);
    if (u == v) {
        return ;
    }
    fa[u] = v;
    for (int i = 1; i <= k; i++) {
        mn[v][i] = std::min(mn[v][i], mn[u][i]);
    }
}
inline void init() {
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
        for (int j = 1; j <= k; j++) {
            mn[i][j] = a[i][j];
        }
    }
}

signed main() {
    freopen("road4.in", "r", stdin);
    freopen("road.out", "w", stdout);

    // std::ios::sync_with_stdio(false);
    // std::cin.tie(nullptr), std::cout.tie(nullptr);

    n = rd(), m = rd(), k = rd();
    for (int i = 1, u, v, w; i <= m; i++) {
        u = rd(), v = rd(), w = rd();
        tot++;
        e[tot].u = u, e[tot].v = v, e[tot].w = w;
    }
    for (int i = 1; i <= k; i++) {
        c[i] = rd();
        for (int j = 1; j <= n; j++) {
            a[j][i] = rd();
        }
    }
    std::sort(e + 1, e + tot + 1);
    int ans = 1e18, up = (1 << k) - 1;
    for (int i = 0; i <= up; i++) {
        int res = 0;
        for (int j = 1; j <= k; j++) {
            if (i & (1 << (j - 1))) {
                res += c[j];
            }
        }
        init();
        int ct = 0;
        for (int j = 1; j <= tot; j++) {
            if (ct == n - 1) {
                break;
            }
            if (fd(e[j].u) == fd(e[j].v)) {
                continue;
            }
            int u = fd(e[j].u), v = fd(e[j].v);
            int tp = e[j].w;
            for (int kk = 1; kk <= k; kk++) {
                if (i & (1 << (kk - 1))) {
                    tp = std::min(tp, mn[u][kk] + mn[v][kk]);
                }
            }
            res += tp;
            mg(u, v);
            ct++;
        }
        ans = std::min(ans, res);
    }
    pt(ans);

    std::cerr << clock() * 1.0 / CLOCKS_PER_SEC << '\n';

    return (0 ^ 0);
}