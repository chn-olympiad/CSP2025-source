#include<bits/stdc++.h>
using namespace std;
bool enableA = true,enableB = true;
int t,n;
long long ans = 0ll;
int a[100005][5] = {{0}};
bool cmp(int a,int b)
{
    return a > b;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t;
    while(t--)
    {
        enableA = enableB = true;
        ans = 0ll;
        cin >> n;
        for(int i = 1;i <= n;i++)
        {
            cin >> a[i][1] >> a[i][2] >> a[i][3];
            if(a[i][2] || a[i][3])
            {
                enableA = false;
            }
            if(a[i][3])
            {
                enableB = false;
            }
        }
        const int lim = int(n / 2 + 1);
        if(enableA)
        {
            int temp[lim] = {0};
            for(int i = 1;i <= n;i++)
            {
                temp[i] = a[i][1];
            }
            sort(temp + 1,temp + n + 1,cmp);
            for(int i = 1;i <= n / 2;i++)
            {
                ans += temp[i];
            }
        }
        else if(enableB)
        {
            int temp[lim] = {0};
            for(int i = 1;i <= n;i++)
            {
                temp[i] = max(a[i][1],a[i][2]);
            }
            sort(temp + 1,temp + n + 1,cmp);
            for(int i = 1;i <= n / 2;i++)
            {
                ans += temp[i];
            }
        }
        else
        {
            long long dp[lim][lim][lim];
            memset(dp,0,sizeof(dp));
            for(int i = 1;i <= n;i++)
            {
                for(int j = 0;j <= min(i - 1,lim);j++)
                {
                    for(int k = 0;k <= min(i - j - 1,lim);k++)
                    {
                        int l = min(i - j - k - 1,lim);
                        const int temp = dp[j][k][l];
                        if(j + 1 < lim)
                        {
                            dp[j + 1][k][l] = max(dp[j + 1][k][l],(long long)temp + a[i][1]);
                        }
                        if(k + 1 < lim)
                        {
                            dp[j][k + 1][l] = max(dp[j][k + 1][l],(long long)temp + a[i][2]);
                        }
                        if(l + 1 < lim)
                        {
                            dp[j][k][l + 1] = max(dp[j][k][l + 1],(long long)temp + a[i][3]);
                        }
                    }
                }
            }
            for(int i = 0;i < lim;i++)
            {
                for(int j = 0;j < lim - i;j++)
                {
                    int k = n - i - j;
                    if(k < lim)
                    {
                        ans = max(ans,dp[i][j][k]);
                    }
                }
            }
        }
        cout << ans << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
