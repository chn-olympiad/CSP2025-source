#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct node
{
    int id=0,v,w;
};
vector<node>e[1111];
long long road[1111][1111];
int dis[1111][1111],c[1111],f[1111];
bool vis[1111][1111];
long long ans=0;
int dj(int s,int ed)
{
    int cnt=1e9;
    for(auto [id,v,w]:e[s])
    {
        if(v=ed)
        {
            if(id==0)
            cnt=min(w,cnt);
            else
            {
                if(!f[id])
                cnt=min(w+c[id],cnt),f[id]++;
                else
                cnt=min(w,cnt);
            }
        }
    }
    return cnt;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    long long q=0;
    for(int u,v,w,i=1;i<=m;i++)
    {
        cin>>u>>v>>w;
        if(!dis[u][v])
        dis[u][v]=dis[v][u]=w;
        else dis[v][u]=dis[u][v]=min(w,dis[u][v]);
        e[u].push_back({0,v,w});
        e[v].push_back({0,u,w});
    }
    if(k==0)
    {
        for(int i=1;i<n;i++)
        {
            for(int j=i+1;j<=n;j++)q+=dis[i][j];
        }
        cout<<q;
        return 0;
    }
    for(int i=1;i<=k;i++)
    {
        cin>>c[i];
        for(int j=1;j<=n;j++)
        {
            int a;
            cin>>a;
            if(j!=i)
            {
                e[i].push_back({i,j,a});
                e[j].push_back({i,i,a});
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            ans+=dj(i,j);
        }
    }
    cout<<ans;
    return 0;
}
