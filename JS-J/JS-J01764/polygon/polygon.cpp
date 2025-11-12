#include<bits/stdc++.h>
using namespace std;
int a[100005];
long long dp[5005][5005];
int qzh[5005];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    for(int i = 3;i <= n;i++)
    {
        for(int j = i;j <= n;j++)
        {
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % 998244353;
        }
    }
    cout << dp[n][n];
    return 0;
}

