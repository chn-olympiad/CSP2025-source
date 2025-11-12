# include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int a[N][4];
int n;
int cnt[4],col[N];
int mx;
int dp[210][210][210];  
int b[N];
int tot;
void dfs(int dep)
{
    if(dep == n+1)
    {
        // for(int i = 1;i <= n;i++) cout << col[i] << " ";
        // cout << endl;
        for(int i = 1;i <= 3;i++) cnt[i] = 0;
        for(int i = 1;i <= n;i++)
        {
            cnt[col[i]]++;
        }
        // for(int i = 1;i <= 3;i++) cout << cnt[i] << " ";
        // cout << endl;
        int flag = 1;
        for(int i = 1;i <= 3;i++)
        {
            if(cnt[i] > n/2)
            {
                // cout << cnt[i]
                flag = 0;
                break;
            }
        }
        if(flag == 1)
        {
            // cout << "true" << endl;
            int ans = 0;
            for(int i = 1;i <= n;i++)
            {
                ans += a[i][col[i]];
            }
            mx = max(ans,mx);
        }
        return ;
    }
    col[dep] = 1;
    dfs(dep+1);
    col[dep] = 2;
    dfs(dep+1);
    col[dep] = 3;
    dfs(dep+1);
}
bool cmp(int x,int y)
{
    return x > y;
}
int main (){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int flag = 0;
        for(int i = 1;i <= n;i++)
        {
            scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);        
            if(a[i][2] != 0 || a[i][3] != 0) flag = 1;
        }
        if(n <= 10)
        {
            mx = 0;
            dfs(1);
            printf("%d\n",mx);
        }else if(n <= 200)
        {
            memset(dp,0,sizeof(dp));
            dp[1][1][0] = a[1][1];
            dp[1][0][1] = a[1][2];
            dp[1][0][0] = a[1][3];
            for(int i = 2;i <= n;i++)
            {
                for(int j = 0;j <= i;j++)
                {
                    for(int k = 0;k <= i-j;k++)
                    {
                        if(j > 0)
                        {
                            dp[i][j][k] = max(dp[i][j][k],dp[i-1][j-1][k]+a[i][1]);
                        }
                        if(k > 0)
                        {
                            dp[i][j][k] = max(dp[i][j][k],dp[i-1][j][k-1]+a[i][2]);
                        }
                        dp[i][j][k] = max(dp[i-1][j][k]+a[i][3],dp[i][j][k]);
                        // cout << i << " " << j << " " << k << " " << dp[i][j][k] << endl;
                    }
                }
            }
            int ans = 0;
            for(int i = 1;i <= n/2;i++)
            {
                for(int j = 1;j <= n/2;j++)
                {
                    int pp = n-i-j;
                    if(pp <= n/2)ans = max(ans,dp[n][i][j]);
                }
            }
            printf("%d\n",ans);
        }
        else if(flag == 0)
        {
            for(int i = 1;i <= n;i++)
            {
                b[++tot] = a[i][1];
            }
            int ans = 0;
            sort(b+1,b+tot+1,cmp);
            for(int i = 1;i <= n/2;i++)
            {
                ans += b[i];
            }
            printf("%d\n",ans);
        }
    }
    return 0;   
}
/*
1
4
4 2 1
3 2 4
5 3 4
3 5 1
*/