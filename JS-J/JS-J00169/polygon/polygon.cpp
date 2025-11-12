#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    int n, cnt=0;
    cin >> n;
    int a[n+5] = {0};
    for(int i=1; i<=n; i++)
        cin >> a[i];
    int g[n+5][n+5] = {0};
    int dp[n+5][n+5] = {0};
    for(int i=1; i<=n; i++)
    {
        for(int j=i+1; j<=n; j++)
        {
            dp[i][j] = a[i] + a[j];
        }
    }
    for(int i=3; i<=n; i++)
    {
        for(int j=i; j<=n; j++)
        {
            for(int k=1; k<j; k++)
            {
                for(int l=k+1; l<j; l++)
                {
                    if(dp[k][l] < a[j])
                    {
                        g[i][j]++;
                        cnt++;
                    }
                    if(k!=j && l!=j) g[i][j] += a[j];
                }
            }
        }
    }
    cout << cnt+1;
    return 0;
}
