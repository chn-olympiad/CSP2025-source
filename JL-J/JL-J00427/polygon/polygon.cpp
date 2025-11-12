#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
int n , a[5010] , sum[5010] , dp[5010][10010] , mp[10010];
signed main()
{
    freopen("polygon.in" , "r" , stdin);
    // freopen("date.in" , "r" , stdin);
    freopen("polygon.out" , "w" , stdout);
    scanf("%lld" , &n);
    for(int i = 1 ; i <= n ; i ++) scanf("%lld" , &a[i]);
    sort(a + 1 , a + n + 1);
    for(int i = 1 ; i <= n ; i ++) sum[i] = sum[i - 1] + a[i];
    int MX = a[n];
    // dp[0][0] = 1;
    for(int i = 0 ; i <= 10000 ; i ++) dp[0][i] = 1;
    for(int i = 1 ; i <= n ; i ++)
    {
        for(int j = a[i - 1] ; j <= min(2 * MX + 1 , sum[i - 1]) ; j ++) mp[j] += dp[i - 1][j] , mp[j] %= mod;
        for(int j = a[i] ; j <= min(2 * MX , sum[i]) ; j ++)
        {
            dp[i][j] = mp[j - a[i]];
            // mp[j] += dp[i][j];
            // printf("dp[%lld][%lld]=%lld\n" , i , j , dp[i][j]);
        }
        int j = 2 * MX + 1;
        dp[i][j] += mp[j] , dp[i][j] %= mod;
        for(int qwq = 2 * MX - a[i] + 1 ; qwq <= 2 * MX ; qwq ++) dp[i][j] += mp[qwq] , dp[i][j] %= mod;
        // printf("****dp[%lld][%lld]=%lld\n" , i , j , dp[i][j]);
        // {
        //     if()
        // }
    }
    int ans = 0;
    for(int i = 3 ; i <= n - 1 ; i ++)
    {
        for(int j = a[i] * 2 + 1 ; j <= min(2 * MX , sum[i]) ; j ++) ans += dp[i][j] , ans %= mod;
        ans += dp[i][2 * MX + 1] , ans %= mod;
    }
    ans += dp[n][2 * MX + 1];
    printf("%lld" , ans % mod);
    return 0;
}