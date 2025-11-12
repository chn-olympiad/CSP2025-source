#include<bits/stdc++.h>
using namespace std;
#define N 100010
int n,T,ip[3],f[N],in[N][4],sm[4],ans;
struct p{
    int val;
    int a1[3];
} dp[N][3];
void dfs(int p,int lst,int sum)
{
    if(p>=lst) ans=max(ans,sum);
    else
    {
        for(int i=1;i<=3;i++) if(sm[i]<int(n/2))
        {
            sm[i]++;
            dfs(p+1,lst,sum+in[p+1][i]);
            sm[i]--;
        }
    }
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--)
    {
        cin>>n;
        if(n<=20)
        {
            ans=0;
            for(int i=1;i<=n;i++) for(int j=1;j<=3;j++) cin>>in[i][j];
            dfs(0,n,0);
            cout<<ans<<endl;
            continue;
        }
        int sz=n/2;
        for(int i=1;i<=n;i++)
        {
            cin>>ip[0]>>ip[1]>>ip[2];
            dp[i][0].val=0,dp[i][1].val=0,dp[i][2].val=0;
            for(int j=0;j<3;j++) for(int k=0;k<3;k++) if(dp[i-1][j].a1[k]<sz)
            {
                if(dp[i][k].val<dp[i-1][j].val+ip[k])
                {
                    dp[i][k]=dp[i-1][j];
                    dp[i][k].val=dp[i-1][j].val+ip[k];
                    dp[i][k].a1[k]=dp[i-1][j].a1[k]+1;
                }
            }
        }
        cout<<max(dp[n][0].val,max(dp[n][1].val,dp[n][2].val))<<endl;
    }
    return 0;
}
/*
1
4
0 1 0
0 1 0
0 2 0
0 2 0
*/
