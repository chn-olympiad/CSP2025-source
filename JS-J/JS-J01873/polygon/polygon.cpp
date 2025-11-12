#include <iostream>
#include <algorithm>
#include <cstdio>
#define int long long
using namespace std;
const int N = 5e3 + 5, MOD = 998244353;
int n, a[N], maxn = 0, ans;
signed main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], maxn += a[i];
    int** dp = new int*[n + 5];
    int** sum = new int*[n + 5];
    for (int i = 0; i <= n; i++) dp[i] = new int[maxn + 5], sum[i] = new int[maxn + 5];
    sort(a + 1, a + 1 + n);
    for (int i = 0; i <= n; i++) dp[i][0] = 1;
    maxn = 0;
    for (int i = 1; i <= n; i++) {
        maxn += a[i];
        for (int j = 1; j <= maxn; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= a[i]) (dp[i][j] += dp[i - 1][j - a[i]]) %= MOD;
        }
    }
    for (int i = 0; i <= n; i++) dp[i][0] = 0;
    maxn = 0;
    for (int i = 1; i <= n; i++) {
        maxn += a[i];
        for (int j = maxn; j >= 0; j--) (sum[i][j] = sum[i][j + 1] + dp[i][j + 1]) %= MOD;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i - 1; j >= 1; j--)
            (ans += sum[j - 1][a[i] - a[j]]) %= MOD;
    }
    cout << ans << '\n';
    for (int i = 0; i <= n; i++) delete[] dp[i];
    delete[] dp;
    return 0;
}
// expect 80pts