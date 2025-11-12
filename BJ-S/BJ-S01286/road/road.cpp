#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
struct node
{
    int v,w;
    bool operator <(const node& a) const
    {
        return a.w<w;
    }
};
int n,m,k;
int a[N];
vector<node> e[N];
int dist[N];
bool vis[N];
int ans;
void dij()
{
    priority_queue<node> q;
    memset(dist,0x3f,sizeof(dist));
    q.push({1,0});
    dist[1]=0;
    while(!q.empty())
    {
        int u=q.top().v;
        q.pop();
        if(vis[u]) continue;
        vis[u]=true;
        for(auto i:e[u])
        {
            int v=i.v,w=i.w;
            if(dist[v]>dist[u]+w)
            {
                ans+=w;
                dist[v]=dist[u]+w;
                q.push({v,dist[v]});
            }
        }
    }
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
    if(k==0) dij();
    else
    {
        for(int p=1;p<=k;p++)
        {
            int c;
            cin>>c;
            for(int i=1;i<=n;i++)
                cin>>a[i];
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                    if(i!=j)
                    {
                        e[i].push_back({j,a[i]+a[j]});
                        e[j].push_back({i,a[i]+a[j]});
                    }
        }
        dij();
    }
    cout<<ans<<"\n";
    return 0;
}
