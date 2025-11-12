#include <bits/stdc++.h>
using namespace std;

int ls[5001];

long long ans = 0;

long long dp[2001][20005], f[2001][50005];

int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> ls[i];
    }
    sort(ls + 1, ls + 1 + n);
    f[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 20000; j >= 0; j--) {
            if (j >= ls[i]) {
                dp[i][j] = f[i - 1][j - ls[i]];
            }
            dp[i][j] %= 998244353;
            f[i][j] = f[i - 1][j] + dp[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 2 * ls[i] + 1; j <= 20000; j++) {
            ans += dp[i][j];
            ans %= 998244353;
        }
    }
    cout << ans;
}
