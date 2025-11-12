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

    return (0 ^ 0);
}