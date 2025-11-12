#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD 998244353
int n, ans, a[5005], dp[5005][5005], qz[5005], qp[5005];
void init() {
    qp[0] = 1;
    for (int i = 1; i <= 5e3; i++) {
        qp[i] = qp[i - 1] * 2 % MOD;
    }
}
signed main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    init();
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    dp[0][0] = 1;
    for (int i = 0; i <= 5000; i++) {
        qz[i] = 1;
    }
    for (int i = 1; i <= n; i++) {
//        cout << "# " << i << " " << qp[i - 1] - qz[a[i]] << "\n";
        ans = (ans + qp[i - 1] - qz[a[i]] + MOD) % MOD;
        for (int j = 0; j <= 5e3; j++) {
            dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
            if (j + a[i] <= 5e3) {
                dp[i][j + a[i]] = (dp[i][j + a[i]] + dp[i - 1][j]) % MOD;
            }
        }
        qz[0] = dp[i][0];
        for (int j = 1; j <= 5e3; j++) {
            qz[j] = (qz[j - 1] + dp[i][j]) % MOD;
        }
    }
    cout << ans << "\n";
    return 0;
}
