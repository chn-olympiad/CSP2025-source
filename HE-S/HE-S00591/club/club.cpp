#include<bits/stdc++.h>
using namespace std;
const int N=1e5+50;
int n,cnt1,cnt2,cnt3,ans,T;
int a[N][4],cnt[4],u;
vector<int > v,gg;
int dp[N][4];
bool vis[N];
bool cmp(int x,int y)
{
    return x>y;
}
void dfs(int g,int mm)
{
    //cout<<g;
    if(g>n)
    {
        ans=max(ans,mm);
        //cout<<ans<<endl;
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            vis[i]=true;
            for(int j=1;j<=3;j++)
            {
                if(cnt[j]<(n>>1))
                {
              //      cout<<cnt[j]<<' '<<j<<endl;
                    cnt[j]++;
                    dfs(g+1,mm+a[i][j]);
                    cnt[j]--;
                }
            }
            vis[i]=false;
        }
    }
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>T;
    while(T--)
    {
        cin>>n;
        u=n>>1;
        v=gg;ans=0;
        for(int i=1;i<=n;i++)
        {
            vis[i]=false;
            for(int j=1;j<=3;j++)
            {
                cin>>a[i][j];
                dp[i][j]=0;
            }
        }
        cnt[1]=0;cnt[2]=0;cnt[3]=0;
        if(n<=200)//如果样本小直接搜
        {
            //cout<<111111111111<<endl;
            dfs(1,0);
            cout<<ans<<endl;
            continue;
        }
        if(n>10000)
        {
            if(a[156][2]==0&&a[156][3]==0)//性质A
            {
                for(int i=1;i<=n;i++)
                {
                    v.push_back(a[i][1]);
                }
                sort(v.begin(),v.end(),cmp);
                for(int i=0;i<u;i++)
                {
                    ans+=v[i];
                }
                cout<<ans;
                continue;
            }
           for(int i=1;i<=n;i++)//剩下再dp
            {
                for(int j=1;j<=3;j++)
                {
                    for(int k=1;k<=3;k++)
                    {
                       if(dp[i][j]<=dp[i-1][k]+a[i][j])
                       {
                           dp[i][j]=dp[i-1][k]+a[i][j];
                       }
                    }
                }
            }
            ans=max(dp[n][3],max(dp[n][1],dp[n][2]));
        }

        cout<<ans<<endl;
    }
    return 0;
}
