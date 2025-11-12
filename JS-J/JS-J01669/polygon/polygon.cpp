#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5005;
const int M = 500 * 100;
const int mod = 998244353;
int n;
int a[N];
int dp[M + 205][4][2];
signed main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    int mx = -1;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i], mx = max(mx, a[i]);
    mx *= n;
    sort(a + 1, a + 1 + n);
    dp[a[1]][1][0] = 1;
    for(int i = 2; i <= n; i++) {
        for(int k = mx; k >= 1; k--) {
            dp[a[i] + k][2][0] += dp[k][1][0];
            dp[a[i] + k][2][0] %= mod;
            if(k <= a[i]) {
                dp[a[i] + k][3][0] += dp[k][2][0];
                dp[a[i] + k][3][0] %= mod;
                dp[a[i] + k][3][0] += dp[k][3][0];
                dp[a[i] + k][3][0] %= mod;
                dp[a[i] + k][3][0] += dp[k][3][1]; 
                dp[a[i] + k][3][0] %= mod;
            } else {
                dp[a[i] + k][3][1] += dp[k][2][0];
                dp[a[i] + k][3][1] %= mod;
                dp[a[i] + k][3][1] += dp[k][3][0];
                dp[a[i] + k][3][1] %= mod;
                dp[a[i] + k][3][1] += dp[k][3][1]; 
                dp[a[i] + k][3][1] %= mod;
            }
        }
        dp[a[i]][1][0]++;          
        dp[a[i]][1][0] %= mod; 
    }
    int ans = 0;
    for(int i = 1; i <= mx; i++) {
        ans += dp[i][3][1] % mod;
        ans %= mod;
    }
    cout << ans;
}
/*
rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++
rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++
rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++
rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++
rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++
rp++ rp++ rp++ rp++ rp++ rp++ rp++ 
*/