#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
struct node
{
    int x,y;
};
bool operator < (node x,node y)
{
    return x.y>y.y;
}
vector<node> e[10004];
int n,m,k;
long long dis[10004];
int vis[10004],ct[12][10004],kt[12],ktf[12];
long long fi()
{
    long long ans=0;
    memset(vis,0,sizeof(vis));
    memset(dis,0x3f,sizeof(dis));
    dis[1]=0;
    priority_queue<node> q;
    q.push({1,0});
    while(q.size())
    {
        int x=q.top().x;
        q.pop();
        if(vis[x]==1)continue;
        vis[x]=1;
        ans+=dis[x];
        for(node y:e[x])
        {
            if(dis[y.x]>y.y)
            {
                dis[y.x]=y.y;
                q.push({y.x,y.y});
            }
        }
        for(int i=1;i<=k;i++)
        {
            if(!kt[i])continue;
            for(int j=1;j<=n;j++)
            {
                if(ct[i][j]+ct[i][x]<dis[j])
                {
                    dis[j]=ct[i][j]+ct[i][x];
                    q.push({j,dis[j]});
                }
            }
        }
    }
    return ans;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        e[u].push_back({v,w});
        e[v].push_back({u,w});
    }
    for(int i=1;i<=k;i++)
    {
        cin>>ktf[i];
        for(int j=1;j<=n;j++)
        {
            cin>>ct[i][j];
        }
    }
    long long ans[13][15],minans=1e18;
    for(int i=1;i<=k;i++)
    {
        ans[i][0]=1e9;
        ans[i][11]=1e9;
    }
    ans[0][0]=fi();
    ans[0][11]=0;
    for(int i=1;i<=k;i++)
    {
        for(int j=k;j>=1;j--)
        {
            for(int l=1;l<=k;l++)
            {
                kt[l]=ans[j-1][l];
            }
            kt[i]=1;
            long long sum=fi();
            if(ans[j-1][11]+sum+ktf[i]<ans[j][0]+ans[j][11])
            {
                ans[j][0]=sum;
                ans[j][11]=ktf[i]+ans[j-1][11];
                ans[j][i]=1;
                minans=min(minans,ans[j][0]+ans[j][11]);
            }
        }
    }
    cout<<minans;
    return 0;
}