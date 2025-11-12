#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std ;
int sticks[6000] ;
int dp[9000] ;
const int mod = 998244353 ;
int tri[5105][5105] ;
int main()
{
    freopen("polygon.in" ,"r", stdin) ;
    freopen("polygon.out", "w", stdout) ;
    int n ;
    cin>>n ;
    for(int i=1;i<=n;i++)
    {
        cin>>sticks[i] ;
    }
    tri[1][1] = 1 ;
    //tri[2][1] = tri[1][2] = 1 ;
     for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            tri[i][j] = (0ll+tri[i-1][j] + tri[i-1][j-1])%mod;
        }
    }
    long long ans =0;
    sort(sticks+1, sticks+1+n) ;
    dp[0] = 1 ;
    for(int i=1;i<=2;i++)
    {
        for(int j=sticks[n] ; j >= sticks[i]; --j)
        {
            dp[j] += dp[j - sticks[i]] ;
            dp[j] %= mod ;
        }
    }
    ans = 4 ;
    for(int i=0;i<=sticks[3] ;i++ )
    {
        ans -= dp[i] ;
        ans = (ans + mod) % mod ;
    }
    for(int i=3;i<n;i++)
    {
        for(int j = sticks[n] ; j >= sticks[i] ; j--)
        {
            dp[j] += dp[j - sticks[i]]%mod ;
            dp[j] %= mod ;
        }
        long long Tmp = 0 ;
        for(int j=0;j<=sticks[i+1];j++)
        {
            Tmp += dp[j] ;
            Tmp %= mod ;
        }
        long long DSUM = 0;
        for(int j=1;j<=i+1;j++)
        {
            DSUM += tri[i+1][j] ;
            DSUM %= mod ;
        }
        ans += (DSUM - Tmp+mod+mod) % mod ;
        ans %= mod ;
    }
    cout << ans ;
}
