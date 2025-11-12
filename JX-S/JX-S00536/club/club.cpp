#include <bits/stdc++.h>
using namespace std;
const int N = 100011;
const int inf = 0x3f3f3f3f;
int n,a[N][4];
struct egde
{
    int nxt,to,cap,w,Pre;
} e[8*N];
int tot,head[N],dist[N],now[N],Pre[N],Pree[N];
int add(int u,int v,int cap,int w)
{
    e[++tot].nxt=head[u];
    e[head[u]=tot].to = v;
    e[tot].cap = cap;
    e[tot].w = w;
    return tot;
}
void Add(int u,int v,int cap,int w)
{
    int a= add(u,v,cap,w);
    int b = add(v,u,0,-w);
    e[a].Pre = b,e[b].Pre = a;
}
bool bfs()
{
    for(int i = 0; i<=n+4; i++) dist[i]=-inf;
    dist[0]=0;
    queue<int> que;
    que.push(0);
    while(que.size())
    {
        int u = que.front();
        que.pop();
        for(int i = head[u]; i; i = e[i].nxt)
        {
            int v = e[i].to,w = e[i].w;
            if(e[i].cap&&dist[v]<dist[u]+w)
            {
                dist[v]=dist[u]+w;
                Pre[v]=u;
                Pree[v]=i;
                que.push(v);
            }
        }
    }
    return dist[n+4]!=-inf;
}
int dfs(int u)
{
    int t = u,flow=inf;
    while(t!=0)
    {
        int pv = Pre[t],pi = Pree[t];
        flow=min(flow,e[pi].cap);
        t = pv;
    }
    t = u;
    while(t!=0)
    {
        int pv = Pre[t],pi = Pree[t];
        e[pi].cap-=flow,e[e[pi].Pre].cap+=flow;
        t = pv;
    }
    return dist[u]*flow;
}
void pre()
{
    if(true)
    {
        freopen("club.in","r",stdin);
        freopen("club.out","w",stdout);
    }
}
void clear()
{
    tot = 0;
    memset(head,0,sizeof head);
}
void readmeta()
{
    scanf("%d",&n);
    for(int i = 1; i<=n; i++)
    {
        for(int j = 1; j<=3; j++)
           scanf("%d",&a[i][j]);
    }
}
void solve()
{
    Add(n+1,n+4,n/2,0);
    Add(n+2,n+4,n/2,0);
    Add(n+3,n+4,n/2,0);
    for(int i = 1; i<=n; i++)
    {
        Add(0,i,1,0);
        for(int j = 1; j<=3; j++)
            Add(i,n+j,1,a[i][j]);
    }
    int ans = 0;
    while(bfs())
        ans+=dfs(n+4);
    cout<<ans<<endl;
}
int main()
{
    pre();
    int t = 1;
   scanf("%d",&t);
    while(t--)
    {
        clear();
        readmeta();
        solve();
    }
    return 0;
}
