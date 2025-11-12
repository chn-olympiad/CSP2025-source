#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr int Mod = 998244353;

int n, m, s[505], c[505];

void ad(int &x, const int& y) { x += y; if (x >= Mod) x -= Mod; }

namespace Sub1 {

int dp[1 << 18][18];

int main() {
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 1 << n; j++) if (__builtin_popcount(j) == i - 1) for (int l = 0; l < i; l++) {
            if (!s[i]) {
                for (int k = 1; k <= n; k++) if (!(j >> k - 1 & 1)) {
                    ad(dp[j | 1 << k - 1][l + 1], dp[j][l]);
                }
            } else {
                for (int k = 1; k <= n; k++) if (!(j >> k - 1 & 1)) {
                    // cerr << j << ' ' << ' ' << l << ' ' << k << ' ' << (j | 1 << k - 1) << ' ' << l + (l >= c[k]) << '\n';
                    ad(dp[j | 1 << k - 1][l + (l >= c[k])], dp[j][l]);
                }
            }
            // cerr << j << ' ' << l << ' ' << dp[j][l] << '\n';
        }
    }
    int rs(0);
    for (int i = m; i <= n; i++) ad(rs, dp[(1 << n) - 1][n - i]);
    cout << rs << '\n';
    return 0;
}

}

signed main() {
#ifdef LARRIX
    freopen("sample.in", "r", stdin);
    freopen("sample.out", "w", stdout);
#else
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        char x; cin >> x;
        s[i] = x ^ 48;
    }
    for (int i = 1; i <= n; i++) cin >> c[i];
    if (n <= 18) return Sub1::main();
    int rs(1);
    for (int i = 1; i <= n; i++) rs = (ll)rs * i % Mod;
    cout << rs << '\n';
    return 0;
}
/*
g++ -o employ employ.cpp -std=c++14 -O2 -DLARRIX ; if [ $? -eq 0 ]; then /usr/bin/time -f "%es, %MKB" ./employ ; fi
*/
/*
n 和 m 都这么小，肯定是 dp。
我们可以预处理出每个人可以面试的位置。个屁。
反正可以知道在第 i 个面试的时候 0 的数量一定 >= pr[i]。如果这个值已经 >= c[p[i]]，则 p[i] 一定不通过。
先考虑如果录用的人最多时能有多少种录法。
我们先贪心地填，填出来如果某一个位置的 c[p[i]] == 1
*/