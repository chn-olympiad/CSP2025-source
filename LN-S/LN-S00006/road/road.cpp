#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,cnt=0,head[11451],dis[11451];
int sum=0;
bitset<11451>vis1;
bitset<11451>vis2;
struct E
{
    int to,nxt,from,w;
}e[2000300];

struct dd
{
    int dis,to;
    bool operator<(const dd& a)const
    {
        return dis>a.dis;
    }
}d;
priority_queue<dd>q;
void add(int u,int v,int w)
{
    e[++cnt].from=u;
    e[cnt].to=v;
    e[cnt].nxt=head[u];
    e[cnt].w=w;
    head[u]=cnt;
    return ;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    if(k)
    {
        cout<<0;
        return 0;
    }
    int u,v,w;
    for(int i=1;i<=n;i++)
    {
        dis[i]=114514191981000;
    }
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v>>w;
        add(u,v,w);
        add(v,u,w);
    }
    d.dis=0;
    d.to=1;
    q.push(d);
    vis2[1]=1;
    while(!q.empty())
    {
        d=q.top();
        q.pop();
        if(vis1[d.to])continue;
        vis1[d.to]=1;
        u=head[d.to];
        while(u)
        {
            if(!vis2[e[u].to])
            {
                sum+=w;
                dis[e[u].to]=dis[e[u].from]+e[u].w;
                vis2[e[u].to]=1;
                d.dis=dis[e[u].to];
                d.to=e[u].to;
                q.push(d);
            }
            else
            {
                if(dis[e[u].from]+e[u].w<dis[e[u].to])
                {
                    sum-=dis[e[u].to]-dis[e[u].from]-e[u].w;
                    dis[e[u].to]=dis[e[u].from]+e[u].w;
                    d.dis=dis[e[u].to];
                    d.to=e[u].to;
                    q.push(d);
                }
            }
            u=e[u].nxt;
        }
    }
    cout<<sum+1;
    return 0;
}