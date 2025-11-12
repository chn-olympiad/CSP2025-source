#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int t,maxn=-1e9,n,r;
int a[100005][5],cnt[5];
bool vis[100005][5];

void dfs(int step)
{
    if(cnt[1]>r||cnt[2]>r||cnt[3]>r) return;

    if(step==n+1)
    {
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=3;j++)
            {

                if(vis[i][j])
                {
                    ans+=a[i][j];
                }
            }
        }
        maxn=max(ans,maxn);
        return;
    }
    for(int i=1;i<=n;i++)
    {

        if(vis[i][1]||vis[i][2]||vis[i][3]) continue;

        if(cnt[1]>=r) continue;
        vis[i][1]=1;
        cnt[1]++;
        dfs(step+1);
        vis[i][1]=0;
        cnt[1]--;
        dfs(step+1);

        if(cnt[2]>=r) continue;
        vis[i][2]=1;
        cnt[2]++;
        dfs(step+1);
        vis[i][2]=0;
        cnt[2]--;
        dfs(step+1);

        if(cnt[3]>=r) continue;
        vis[i][3]=1;
        cnt[3]++;
        dfs(step+1);
        vis[i][3]=0;
        cnt[3]--;
        dfs(step+1);
    }
}

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        maxn=-1;
        n=0;
        memset(vis,0,sizeof(vis));
        memset(a,0,sizeof(a));
        memset(cnt,0,sizeof(cnt));
        cin>>n;
        r=n/2;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=3;j++)
            {
                cin>>a[i][j];
            }
        }
        dfs(1);
        cout<<maxn<<endl;
    }
    return 0;
}
