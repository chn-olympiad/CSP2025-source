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

constexpr int N = 3e5 + 5;

i64 a[N];

namespace sgt {
    i64 d[N << 2], b[N << 2];
    #define ls (p << 1)
    #define rs (p << 1 | 1)
    inline void psu(int p) {
        d[p] = d[ls] + d[rs];
    }
    inline void psd(int p, int l, int r) {
        if (!b[p]) {
            return ;
        }
        int mid = l + r >> 1;
        b[ls] += b[p], b[rs] += b[p];
        d[ls] += (mid - l + 1) * b[p], d[rs] += (r - mid) * b[p];
        b[p] = 0;
    }
    inline void bd(int p, int l, int r) {
        if (l == r) {
            d[p] = a[l], b[p] = 0;
            return ;
        }
        int mid = l + r >> 1;
        bd(ls, l, mid), bd(rs, mid + 1, r);
        psu(p);
    }
    inline void upd(int p, int l, int r, int s, int t, i64 v) {
        if (l <= s && t <= r) {
            d[p] += (t - s + 1) * v;
            b[p] += v;
            return ;
        }
    }
}

int main() {
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);

    // std::ios::sync_with_stdio(false);
    // std::cin.tie(nullptr), std::cout.tie(nullptr);

    int a = rd(), b = rd();
    pt(a + b, ' ');
    pt(0, '\n');
    pt(-1, 'c');
    ptstr("\n");
    ptstr("I love you!\n");
    // pt((int)sqrt(cc), '\n');

    return (0 ^ 0);
}