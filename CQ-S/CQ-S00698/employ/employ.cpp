#include <bits/stdc++.h>
using namespace std;
const int N = 505;
const int N2 = 18;
const int mod = 998244353;
int n, m, c[N], s[N], dp[1 << N2][N2 + 1];
bool spe1 = true;
string S;
int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m >> S;
    for (int i = 0;i < S.size();i++) {
        s[i + 1] = S[i] - '0';
        spe1 &= s[i + 1];
    }
    for (int i = 1;i <= n;i++)
        cin >> c[i];
    int pro = 1;
    for (int i = 1;i <= n;i++)
        pro = 1ll * pro * i % mod;
    if (m == n) {
        bool fail = false;
        for (int i = 1;i <= n;i++)
            fail |= ((!s[i]) || (!c[i]));
        if (fail)
            cout << 0 << "\n";
        else
            cout << pro << "\n";
    }
    else if (n <= 18) {
        dp[0][0] = 1;
        for (int i = 0;i < (1 << n) - 1;i++) {
            int p = __builtin_popcount(i);
            for (int j = 0;j <= n;j++)
                if (dp[i][j])
                    for (int k = 1;k <= n;k++)
                        if (!((i >> (k - 1)) & 1)) {
                            dp[i | (1 << (k - 1))][j + (s[p + 1] && (p - j < c[k]))] = (dp[i | (1 << (k - 1))][j + (s[p + 1] && (p - j < c[k]))] + dp[i][j]) % mod;
                        }
        }
        int sum = 0;
        for (int i = m;i <= n;i++)
            sum = (sum + dp[(1 << n) - 1][i]) % mod;
        cout << sum;
    }
    return 0;
}