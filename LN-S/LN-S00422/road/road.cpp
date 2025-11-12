#include<bits/stdc++.h>
using namespace std;
int n,m,k;
using pii=pair<int,int>;
vector<pii>g[10009];
int dist[10009],ans;
bool st[10009];
void bfs()
{
    queue<int>q;
    q.push(1);
    while(q.size())
    {
        int ver=q.front();
        q.pop();
        int cnt=0x3f;
        if(st[ver])break;
        st[ver]=1;
        for(auto p:g[ver])
        {
            int u=p.first,w=p.second;
            //st[u]=1;
            if(st[u])continue;
            cnt=min(cnt,w);
            q.push(u);
        }
        if(cnt!=0x3f)ans+=cnt;
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
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    for(int i=1;i<=k;i++)
    {
        int l;
        cin>>l;
        for(int j=1;j<=n;j++)
        {
            int p;
            cin>>p;
        }
    }
    bfs();
    cout<<ans;
    return 0;
}
