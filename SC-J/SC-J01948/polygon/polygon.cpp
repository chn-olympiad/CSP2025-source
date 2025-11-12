#include <bits/stdc++.h>
using namespace std;

const int N = 5005, M = 998244353;
int n;
int a[N], dp[N][N];

void modnum(int &x) {x = x < M ? x : x - M;}

int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)cin >> a[i];
    sort(a + 1, a + n + 1);
    dp[1][0] = 1;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j <= 5001; ++j) {
            if(!dp[i][j])continue;
            dp[i + 1][j] += dp[i][j];
            modnum(dp[i + 1][j]);
            dp[i + 1][min(j + a[i], 5001)] += dp[i][j];
            modnum(dp[i + 1][min(j + a[i], 5001)]);
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 5001; j >= 0; --j) {
            dp[i][j] += dp[i][j + 1];
            modnum(dp[i][j]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += dp[i][a[i] + 1];
        modnum(ans);
    }
    cout << ans;
    return 0;
}