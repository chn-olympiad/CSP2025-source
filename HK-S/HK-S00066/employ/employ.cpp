#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 998244353;
int32_t main(){
    ifstream cin("employ.in");
    ofstream cout("employ.out");
    int n, m;
    string s;
    cin >> n >> m >> s;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    bool subA = false;
    if (s.find('0') == string::npos) subA = true;
    if (n == m) {
        if (!subA || *min_element(arr, arr + n) == 0) {
            cout << 0 << "\n";
            return 0;
        }
        int ans = 1;
        for (int i = 1; i <= n; i++) ans = ans * i % MOD;
        cout << ans << "\n";
        return 0;
    }

    if (n <= 20) {
        // no need mod
        int dp[1 << n][n + 1];
        for (int i = 0; i < (1 << n); i++) for (int j = 0; j <= n; j++) dp[i][j] = 0;
        dp[0][0] = 1;
        for (int i = 0; i < (1 << n); i++) for (int j = 0; j <= n; j++) {
            for (int k = 0; k < n; k++) if (((i >> k) & 1) == 0) {
                if (s[__builtin_popcount(i)] == '0' || arr[k] <= j) dp[i | (1 << k)][j + 1] += dp[i][j];
                else dp[i | (1 << k)][j] += dp[i][j];
            }
        }
        int ans = 0;
        for (int i = 0; i <= n - m; i++) ans += dp[(1 << n) - 1][i];
        cout << ans << "\n";
        return 0;
    }
    cout << 0 << "\n";
}