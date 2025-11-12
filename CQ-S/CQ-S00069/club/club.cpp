#include <bits/stdc++.h>

namespace CYRENE {
#define rep(i, st, ed) for (int i = (st), _##i = (ed); i <= _##i; ++i)
#define qep(i, st, ed) for (int i = (st), _##i = (ed); i <  _##i; ++i)
#define per(i, st, ed) for (int i = (st), _##i = (ed); i >= _##i; --i)
#define fi first
#define se second
#define eb emplace_back
// #define gc getchar
#define gc() (ihedp == italp && (italp = (ihedp = ibuf) + fread(ibuf, 1, BUF_SIZ, stdin), ihedp == italp) ? EOF : *(ihedp++))
#define pc putchar
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using vi = vector<int>;
using pii = pair<int, int>;
using vpii = vector<pair<int, int>>;

namespace IO {
    constexpr size_t BUF_SIZ = 1 << 20;

    char ibuf[BUF_SIZ], *ihedp, *italp;

    template<typename T>
    void read(T &x) {
        x = 0; char c = gc(); bool f = false;
        while (!isdigit(c)) f = (c == '-'), c = gc();
        while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = gc();
        if (f) x = -x;
    }

    template<typename T, typename ...Nxt>
    void read(T &x, Nxt &...nxt) { read(x); read(nxt...); }
} using namespace IO;

template<typename T> constexpr bool chkmax(T &x, T y) { return x < y ? x = y, true : false; }

constexpr int N = 1e5 + 5;

int n, a[N][3];

namespace BF {
    constexpr int N = 5005;

    i64 f[2][N][N];

    void solve() {
        rep(i, 1, n) rep(j, 0, 2) read(a[i][j]);
        int pre = 0, cur = 1;
        rep(j, 0, n / 2) rep(k, 0, n / 2) f[pre][j][k] = 0;
        rep(i, 1, n) {
            rep(j, 0, n / 2) rep(k, 0, n / 2) f[cur][j][k] = 0;
            rep(j, 0, min(i, n / 2)) rep(k, max(0, i - j - n / 2), min(i - j, n / 2)) {
                if (j) chkmax(f[cur][j][k], f[pre][j - 1][k] + a[i][0]);
                if (k) chkmax(f[cur][j][k], f[pre][j][k - 1] + a[i][1]);
                if (i - j - k) chkmax(f[cur][j][k], f[pre][j][k] + a[i][2]);
            }
            swap(pre, cur);
        }
        i64 ans = 0;
        rep(j, 0, n / 2) rep(k, n / 2 - j, n / 2) chkmax(ans, f[pre][j][k]);
        printf("%lld\n", ans);
    }
}

namespace FK {
    void solve() {
        rep(i, 1, n) rep(j, 0, 2) read(a[i][j]);
        vi w;
        rep(i, 1, n) w.eb(a[i][0]);
        sort(w.begin(), w.end(), greater<int>());
        i64 ans = 0;
        qep(i, 0, n / 2) ans += w[i];
        printf("%lld\n", ans);
    }
}

int moe() {
    int t; read(t);
    rep(lol, 1, t) {
        read(n);
        if (n <= 1000) BF::solve();
        else FK::solve();
    }
    return 0;
}
} // namespace CYRENE

int main() {
    std::freopen("club.in", "r", stdin);
    std::freopen("club.out", "w", stdout);
    return CYRENE::moe();
}

/*
a man's contribute is at least the midium w.
*/

/*
g++ -o club club.cpp -std=c++17 -O2 -Wall -Wno-unused-result -g -DDEBUG -fsanitize=address,undefined
*/
