//40pts
//AWA
#include<bits/stdc++.h>
using namespace std;
struct node
{
    int want[4];
}data[100002];
int T,n,dp[102][102][102],ans,tans,cnt[4],mx[202];
vector<node>club[4];
bool cmp12(node a,node b)
{
    return a.want[1]-a.want[2]>b.want[1]-b.want[2];
}
bool cmp21(node a,node b)
{
    return a.want[2]-a.want[1]>b.want[2]-b.want[1];
}
void dfs(int x)
{
    //cout<<x<<' '<<tans<<'\n';
    if(tans+mx[x]<=ans)
        return;
    if(x==n+1)
    {
        ans=max(ans,tans);
        return;
    }
    for(int i=1;i<=3;i++)
    {
        if(cnt[i]==n/2)
            continue;
        cnt[i]++;
        tans+=data[x].want[i];
        dfs(x+1);
        tans-=data[x].want[i];
        cnt[i]--;
    }
    return;
}
signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>T;
    for(int o=1;o<=T;o++)
    {
        club[1].clear();
        club[2].clear();
        club[3].clear();
        cin>>n;
        bool specB=true;
        for(int i=1;i<=n;i++)
        {
            cin>>data[i].want[1]>>data[i].want[2]>>data[i].want[3];
            if(data[i].want[1]>data[i].want[2])
                club[1].push_back(data[i]);
            else
                club[2].push_back(data[i]);
            if(data[i].want[3]!=0)
                specB=false;
        }
        if(n<=200&&!specB)
        {
            /*
            int ans=0;
            memset(dp,0,sizeof(dp));
            for(int i=0;i<=n/2;i++)
            {
                for(int j=0;j<=n/2;j++)
                {
                    for(int k=0;k<=n/2;k++)
                    {
                        if(i==j&&j==k&&k==0)
                            continue;
                        if(i!=0)
                        {
                            for(int t=1;t<=n;t++)
                                dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+data[t].want[1]);
                        }
                        if(j!=0)
                        {
                            for(int t=1;t<=n;t++)
                                dp[i][j][k]=max(dp[i][j][k],dp[i][j-1][k]+data[t].want[2]);
                        }
                        if(k!=0)
                        {
                            for(int t=1;t<=n;t++)
                                dp[i][j][k]=max(dp[i][j][k],dp[i][j][k-1]+data[t].want[3]);
                        }
                        ans=max(ans,dp[i][j][k]);
                        if(o==1)
                            cout<<i<<' '<<j<<' '<<k<<' '<<dp[i][j][k]<<'\n';
                    }
                }
            }
            cout<<ans<<'\n';
            */
            for(int i=n;i>=1;i--)
                mx[i]=mx[i+1]+max(data[i].want[1],max(data[i].want[2],data[i].want[3]));
            tans=ans=0;
            dfs(1);
            cout<<ans<<'\n';
        }
        else
        {
            if(club[1].size()>n/2)
            {
                sort(club[1].begin(),club[1].end(),cmp12);
                while(club[1].size()>n/2)
                {
                    club[2].push_back(club[1][club[1].size()-1]);
                    club[1].pop_back();
                }
            }
            else if(club[2].size()>n/2)
            {
                sort(club[2].begin(),club[2].end(),cmp21);
                while(club[2].size()>n/2)
                {
                    club[1].push_back(club[2][club[2].size()-1]);
                    club[2].pop_back();
                }
            }
            tans=0;
            for(int i=1;i<=2;i++)
            {
                for(int j=0;j<club[i].size();j++)
                    tans+=club[i][j].want[i];
            }
            cout<<tans<<'\n';
        }
    }
    return 0;
}
//40+(0~60)+0+0=(40~100)
//Too hard.
//bye-bye, noip.
//farewell T-T
//sad sad sad
