#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;

inline int read() {
    int x = 0, w = 1; char c = getchar();
    while (!isdigit(c)) { if (c == '-') w = -w; c = getchar(); }
    while (isdigit(c)) { x = (x << 3) + (x << 1) + c - 48; c = getchar(); }
    return x * w;
}

inline void write(int x) {
    if (x < 0) x = -x, putchar('-');
    if (x > 9) write(x / 10);
    putchar(x % 10 + 48);
}

int n;
int m;
string s;
int c[25];
int f[262149][25];

int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);

    n = read(), m = read();

    cin >> s;

    for (int i = 0; i < n; i++)
        c[i] = read();

    int t = (1 << n);

    f[0][0] = 1;

    for (int S = 0; S < t; S++) {
        int i = __builtin_popcount(S);
        for (int j = 0; j <= i; j++) {
            for (int k = 0; k < n; k++) {
                if (S & (1 << k))
                    continue;
                if (i - j >= c[k] || s[i] == '0')
                    f[S | (1 << k)][j] = (f[S | (1 << k)][j] + f[S][j]) % mod;
                if (i - j < c[k] && s[i] == '1')
                    f[S | (1 << k)][j + 1] = (f[S | (1 << k)][j + 1] + f[S][j]) % mod;
            }
        }
    }

    int ans = 0;

    for (int i = m; i <= n; i++)
        ans = (ans + f[t - 1][i]) % mod;

    write(ans);
    puts("");

    return 0;
}
