#include<bits/stdc++.h>
using namespace std;
#define int long long
struct Edge
{
    int v,w,f;
    Edge(int vv=0,int ww=0,int ff=0)
    {
        v=vv;w=ww;f=ff;
    }
}e1,e2;
struct node
{
    int u,minl,f;
    node(int uu=0,int minll=0,int ff=0)
    {
        u=uu;minl=minll;f=ff;
    }
    friend bool operator <(node x,node y)
    {
        return x.minl<y.minl;
    }
}v1,v2;
int dis[10010][(1<<11)],n,m,k,u,v,w,f,ans[(1<<11)],c[15];
bool vis[10010][(1<<11)];
vector<Edge> g[10010];
priority_queue<node> q;
int get_plus(int x)
{
    int res=0;
    for(int i=1;x;i++)
    {
        res+=c[i]*(x&1);
        x>>=1;
    }
    return res;
}
signed main()
{
    freopen("road1.in","r",stdin);
    freopen("road.out","w",stdout);
    memset(dis,0x3f,sizeof(dis));
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v>>w;
        g[u].push_back(Edge(v,w,0));
        g[v].push_back(Edge(u,w,0));
    }
    for(int i=1;i<=k;i++)
    {
        cin>>c[i];
        for(int j=1;j<=n;j++)
        {
            cin>>w;
            g[i].push_back(Edge(j,w,(1<<i-1)));
            g[j].push_back(Edge(i,w,(1<<i-1)));
        }
    }
    for(int i=1;i<=(1<<k)-1;i++)
    {
        ans[i]=get_plus(i);
        //cout<<ans[i]<<' ';
    }
    //cout<<"\n";
    dis[1][0]=0;
    q.push(node(1,0,0));
    while(q.size())
    {
        v1=q.top();
        q.pop();
        u=v1.u;f=v1.f;
        if(vis[u][f])
            continue;
        vis[u][f]=1;
        ans[f]+=v1.minl;
        for(int i=0;i<g[u].size();i++)
        {
            v=g[u][i].v;w=g[u][i].w;
            int ef=g[u][i].f;
            if(!vis[v][(f|ef)]&&w<dis[v][(f|ef)])
            {
                dis[v][(f|ef)]=w;
                q.push(node(v,dis[v][(f|ef)],(f|ef)));
            }

        }
    }
    if(k==0)
        cout<<ans[0];
    else
    {
        int mins=1000000000000;
        for(int i=0;i<=(1<<k)-1;i++)
            mins=min(mins,ans[i]);
        cout<<mins;
    }
    return 0;
}
