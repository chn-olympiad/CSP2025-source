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

const int N = 1e5 + 5;

int n, a[N][3];

struct nd {
    int id, df, i;
    bool operator <(const nd &c) const {
        if (df != c.df) {
            return df > c.df;
        } else {
            return i > c.i;
        }
    }
};

inline void solve() {
    std::priority_queue<nd> q[3];
    n = rd();
    i64 ans = 0;
    for (int i = 1; i <= n; i++) {
        int id1 = 0, id2 = -1;
        for (int j = 0; j < 3; j++) {
            a[i][j] = rd();
        }
        for (int j = 1; j < 3; j++) {
            if (a[i][j] > a[i][id1]) {
                id2 = id1;
                id1 = j;
            } else if (id2 == -1 || a[i][j] > a[i][id2]) {
                id2 = j;
            }
        }
        nd tp;
        tp.i = i, tp.df = a[i][id1] - a[i][id2], tp.id = id2;
        if (q[id1].size() < (n / 2)) {
            q[id1].push(tp);
            ans += a[i][id1];
        } else {
            nd u = q[id1].top();
            if (u.df < tp.df) {
                ans -= u.df;
                ans += a[i][id1];
                q[id1].pop();
                q[id1].push(tp);
            } else {
                ans += a[i][id2];
            }
        }
    }
    pt(ans);
}

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    // std::ios::sync_with_stdio(false);
    // std::cin.tie(nullptr), std::cout.tie(nullptr);

    int t = rd();
    while (t--) {
        solve();
    }

    std::cerr << clock() * 1.0 / CLOCKS_PER_SEC << '\n';

    return (0 ^ 0);
}