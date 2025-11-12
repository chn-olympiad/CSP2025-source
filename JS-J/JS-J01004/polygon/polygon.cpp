#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
long long n, a[5005], dp[5005][5005], ans;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        for (int k = i; k <= n; k++) {
            for (int j = 0; j <= a[i - 1]; j++) {
                dp[k][j] += 1;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= a[i]; j++) {
            for (int k = 1; k <= i - 1; k++) {
                dp[i][j] += dp[k][j - a[k]];
                dp[i][j] %= MOD;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        ans += dp[i][a[i]];
        ans %= MOD;
    }
    cout << ans;
	return 0;
}
