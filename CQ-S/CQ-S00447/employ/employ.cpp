#include <bits/stdc++.h>

#define fin(s) freopen(s".in", "r", stdin)
#define fout(s) freopen(s".out", "w", stdout)

using i64 = long long;
using namespace std;

template<typename T>
void read(T &x) {
    char ch = getchar();
    x = 0;
    T f = 1;

    while (!isdigit(ch)) {
        f -= (ch == '-') << 1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        x = (x << 1) + (x << 3) + (ch & 15);
        ch = getchar();
    }

    x *= f;
}
template<typename T, typename ...L>
void read(T &x, L &...y) {
    read(x);
    read(y...);
}

namespace mod {

constexpr int P = 998244353;

template<typename T>
T add(T x, T y) {
    while (x + y >= P) {
        return x + y - P;
    }
    return x + y;
}
template<typename T>
T add(T x) {
    return x;
}
template<typename T, typename ...L>
T add(T x, L ...y) {
    return add(x, add(y...));
}

template<typename T>
T sub(T x, T y) {
    while (x < y) {
        return x - y + P;
    }
    return x - y;
}
template<typename T>
T neg(T x) {
    return sub(0, x);
}

template<typename T>
T mul(T x, T y) {
    return (i64)x * y % P;
}
template<typename T>
T mul(T x) {
    return x;
}
template<typename T, typename ...L>
T mul(T x, L ...y) {
    return mul(x, mul(y...));
}

template<typename T>
void inc(T &x, T y) {
    x = add(x, y);
}
template<typename T>
void dec(T &x, T y) {
    x = sub(x, y);
}
template<typename T>
void apply(T &x, T y) {
    x = mul(x, y);
}

template<typename T>
T power(T a, i64 b) {
    T r = 1;
    for (; b; b /= 2, a = mul(a, a)) {
        if (b & 1) {
            r = mul(r, a);
        }
    }
    return r;
}
template<typename T>
T inv(T x) {
    return power(x, P - 2);
}
template<typename T>
T div(T x, T y) {
    return mul(x, inv(y));
}

}
//P = 998244353

constexpr int N = 505;

int n, m, dp[2][N][N], o;
string s;
int cnt[N];

int fac[N], ifac[N];
int comb(int n, int m) {
    if (m > n || m < 0) {
        return 0;
    }
    return mod::mul(fac[n], ifac[m], ifac[n - m]);
}

int main() {
    fin("employ");
    fout("employ");

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    cin >> s;
    s = '#' + s;
    for (int i = 1; i <= n; ++i) {
        int c;
        cin >> c;
        cnt[c]++;
    }

    fac[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fac[i] = mod::mul(fac[i - 1], i);
    }
    ifac[n] = mod::inv(fac[n]);
    for (int i = n; i >= 1; --i) {
        ifac[i - 1] = mod::mul(ifac[i], i);
    }

    dp[0][0][0] = 1;
    o = 0;

    for (int i = 1; i <= n; ++i, o = !o) {
        for (int j = 0; j <= i; ++j) {
            for (int k = 0; k <= i; ++k) {
                dp[!o][j][k] = 0;
            }
        }
        int les = 0;
        for (int j = 0; j < i; ++j) {
            les += cnt[j];
            for (int k = 0; k < i; ++k) if (dp[o][j][k]) {
                if (les > (i - 1 - k)) {
                    for (int t = 0, p = 1; t <= min(k, cnt[j + 1]); ++t) {
                        mod::inc(dp[!o][j + 1][k - t], mod::mul(dp[o][j][k], p, les - (i - 1 - k), comb(k, t)));
                        mod::apply(p, cnt[j + 1] - t);
                    }
                }
                if (s[i] == '1') {
                    if (k < n) {
                        mod::inc(dp[!o][j][k + 1], dp[o][j][k]);
                    }
                } else {
                    for (int t = 0, p = 1; t <= min(k + 1, cnt[j + 1]); ++t) {
                        mod::inc(dp[!o][j + 1][k - t + 1], mod::mul(dp[o][j][k], p, comb(k + 1, t)));
                        mod::apply(p, cnt[j + 1] - t);
                    }
                }
            }
        }
    }

    int ans = 0;

    for (int i = 0; i <= n - m; ++i) {
        int grtdkd = 0;
        for (int j = i + 1; j <= n; ++j) {
            grtdkd += cnt[j];
        }
        for (int j = 0, p = 1; j <= grtdkd; ++j) {
            mod::inc(ans, mod::mul(dp[o][i][j], p));
            mod::apply(p, grtdkd - j);
        }
    }

    cout << ans << "\n";

    return 0;
}

/*
4 3
1111
4 0 3 2

4 3
1111
3 0 1 1

g++ employ.cpp -o employ -O2 -std=c++14

A 性质：设 dp_{i, j, k}，表示放完了 c = 0~i，现在分界点在 j，录用了 k 个人的方案数。
考虑优化，这个做法对下标的适配性太差，需要换种做法。

dp(i, j, k) 前 i 个，有 j 个不合法的，有 k 个空留给了 > j 的数。
*/