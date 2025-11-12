#include <bits/stdc++.h>
using namespace std ;
const int N = 100005 ;
int T,n ;
int a[N],b[N],c[N],dp[150][70][70][70] ;
int main ()
{
    freopen("club.in","r",stdin) ;
    freopen("club.out","w",stdout) ;
    cin >> T ;
    while (T--)
    {
        cin >> n ;
        for (int i = 1 ; i <= n ; i++) cin >> a[i] >> b[i] >> c[i] ;
        for (int w = 1 ; w <= n ; w++)
        {
            for (int i = 0 ; i <= n / 2 && i <= w ; i++)
            {
                for (int j = (w - i * 2) / 2 ; j <= n / 2 && j <= w - i ; j++)
                {
                    int k = w - i - j ;
                    if (i == 0)
                    {
                        if (j == 0) dp[w][i][j][k] = dp[w - 1][i][j][k - 1] + c[w] ;
                        else if (k == 0) dp[w][i][j][k] = dp[w - 1][i][j - 1][k] + b[w] ;
                        else dp[w][i][j][k] = max(dp[w - 1][i][j - 1][k] + b[w],dp[w - 1][i][j][k - 1] + c[w]) ;
                    }
                    else if (j == 0)
                    {
                        if (k == 0) dp[w][i][j][k] = dp[w - 1][i - 1][j][k] + a[w] ;
                        else dp[w][i][j][k] = max(dp[w - 1][i - 1][j][k] + a[w],dp[w - 1][i][j][k - 1] + c[w]) ;
                    }
                    else if (k == 0) dp[w][i][j][k] = max(dp[w - 1][i - 1][j][k] + a[w],dp[w - 1][i][j - 1][k] + b[w]) ;
                    else dp[w][i][j][k] = max({dp[w - 1][i - 1][j][k] + a[w],dp[w - 1][i][j - 1][k] + b[w],dp[w - 1][i][j][k - 1] + c[w]}) ;
                }
            }
        }
        int ans = 0 ;
        for (int i = 0 ; i <= n / 2 ; i++)
        {
            for (int j = (n - i * 2) / 2 ; j <= n / 2 ; j++)
            {
                int k = n - i - j ;
                ans = max(ans,dp[n][i][j][k]) ;
            }
        }
        cout << ans << "\n" ;
    }
    return 0 ;
}
