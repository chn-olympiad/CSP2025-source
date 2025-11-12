#include<iostream>
using namespace std ;
long long arr[700000] ;
long long qz[700000] ;
int dp[700000] ;
int mxn[700000] ;
int main()
{
    freopen("xor.in", "r", stdin) ;
    freopen("xor.out", "w", stdout) ;
    int n ;
    long long tar ;
    cin>>n>>tar ;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i] ;
        qz[i] = qz[i-1] ^ arr[i] ;
    }
    for(int i=1;i<=n;i++)
    {
        dp[i] = 0;
    }
    dp[0] = 0 ;
    for(int i=1;i<=n;i++)
    {
        mxn[i] = mxn[i - 1] ;
        for(int j=i ;j >= 1 ; j--)
        {
           // d ^= arr[i] ;
            long long now = qz[i] ^ qz[j-1] ;
            if(now == tar)
            {
            ///    cout << "OK\n" ;
                dp[i] = max(mxn[j-1]+1, dp[i]) ;
                break ;
            }
        }

        mxn[i] = max(mxn[i], dp[i]) ;
    }
    int ans = 0 ;
    for(int i=1;i<=n;i++)
    {
        ans = max(ans, dp[i]) ;
    }
    cout << ans ;
}
