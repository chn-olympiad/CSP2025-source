#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
const int MAXN = 1e5 + 8;
int T,n,lmt,ans,a[MAXN][4];
void dfs(int lyr1,int lyr2,int lyr3,int step,int sum)
{
    if(step == n+1)
    {
        ans = max(ans,sum);
        return ;
    }
    if(lyr1 == lmt)
    {
        dfs(lyr1,lyr2+1,lyr3,step+1,sum + a[step][2]);
        dfs(lyr1,lyr2,lyr3+1,step+1,sum + a[step][3]);
    }
    else if(lyr2 == lmt)
    {
        dfs(lyr1+1,lyr2,lyr3,step+1,sum + a[step][1]);
        dfs(lyr1,lyr2,lyr3+1,step+1,sum + a[step][3]);
    }
    else if(lyr3 == lmt)
    {
        dfs(lyr1+1,lyr2,lyr3,step+1,sum + a[step][1]);
        dfs(lyr1,lyr2+1,lyr3,step+1,sum + a[step][2]);
    }
    else
    {
        dfs(lyr1+1,lyr2,lyr3,step+1,sum + a[step][1]);
        dfs(lyr1,lyr2+1,lyr3,step+1,sum + a[step][2]);
        dfs(lyr1,lyr2,lyr3+1,step+1,sum + a[step][3]);
    }
    return ;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> T;
    while(T--)
    {
        cin >> n;
        lmt = n/2,ans = 0;
        memset(a,0,sizeof(a));
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= 3;j++)
            {
                cin >> a[i][j];
            }
        }
        dfs(0,0,0,1,0);
        cout << ans << "\n";
    }
    return 0;
}
