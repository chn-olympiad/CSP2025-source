#include <bits/stdc++.h>
using namespace std;
const int N = 20, mod = 998244353;

int n, m;
string s;
int c[N];

long long f[1 << N][N];

int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);

    cin >> n >> m;
    cin >> s; s = '#' + s;
    for(int i = 1; i <= n; i++) cin >> c[i];

    f[0][0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = (1 << n) - 1; j >= 0; j--) {
            if(__builtin_popcount(j) < i - 1) continue;
            for(int k = i - 1; k >= 0; k--) {
                int p = i - k - 1;

                for(int t = 1; t <= n; t++) {
                    if((j >> (t - 1)) & 1) continue;

                    bool flag = ((p < c[t]) && (s[i] == '1'));
                    f[j | (1 << (t - 1))][k + flag] = (f[j | (1 << (t - 1))][k + flag] + f[j][k]) % mod;
                }
            }
        }
    }

    long long ans = 0;
    for(int j = m; j <= n; j++) {
        ans = (ans + f[(1 << n) - 1][j]) % mod;
    }

    cout << ans << '\n';
}