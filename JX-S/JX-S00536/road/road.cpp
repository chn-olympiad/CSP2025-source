#include <bits/stdc++.h>
using namespace std;
#define  int long long
const int N = 1000000+100000+10+10010;
const int inf = 0x3f3f3f3f;
int n,m,q,u,v,w,c,x,fa[N],cnt[11];
int find(int x)
{
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
struct egde
{
    int nxt,to,w;
} e[100000];
struct node
{
    int u,v,w;
} e2[N];
bool cmp(node a,node b)
{
    return a.w<b.w;
}
int tot,head[N],dist[10010+10+10];
int vis[10011];
void add(int u,int v,int w)
{
    e[++tot].nxt=head[u];
    e[head[u]=tot].to = v;
    e[tot].w = w;
}
void bfs()
{
    for(int i = 1; i<=n+q; i++) dist[i]=inf;
    for(int i = n+1; i<=n+q; i++) vis[i]=i;
    queue<int> que;
    que.push(0);
    while(que.size())
    {
        int u = que.front();
        que.pop();
        for(int i = head[u]; i; i = e[i].nxt)
        {
            int v = e[i].to;
            if(dist[v]>e[i].w)
            {
                dist[v]=e[i].w;
                vis[v]=vis[u];
                que.push(v);
            }
        }
    }
}
void pre()
{
    ios::sync_with_stdio();
    cin.tie(0),cout.tie(0);
    if(true)
    {
        freopen("road.in","r",stdin);
        freopen("road.out","w",stdout);
    }
}
void clear()
{


}
void readmeta()
{
    cin>>n>>m>>q;
    for(int i = 1; i<=n; i++) fa[i]=i;
    for(int i= 1; i<=m; i++)
    {
        cin>>u>>v>>w;
        e2[++tot]= {u,v,w};
    }

    for(int i = 1; i<=q; i++)
    {
        cin>>c;
        add(0,i+n,c);
        for(int j = 1; j<=n; j++)
        {
            cin>>x;
            add(i+n,j,c);
        }
    }
}
int solve1()
{
    sort(e2+1,e2+1+m,cmp);
    int ans = 0,cnt = 0;
    for(int i = 1; i<=m; i++)
    {
        int u = find(e2[i].u),v = find(e2[i].v);
        if(u==v) continue;
        ans+=e2[i].w;
        swap(e2[++cnt],e2[i]);
        if(cnt==n-1) break;
    }
    return ans;
}
void solve()
{
    if(!q) cout<<solve1()<<endl;
    else
    {
        solve1();
        bfs();
        for(int i = 1; i<n; i++)
        {
            int u = e2[i].u,v= e2[i].v,w = e2[i].w;
            if(dist[u]>w)
            {
                dist[u]=w;
                vis[u]=vis[v];
            }
            else if(dist[v]>w)
            {
                dist[v]=w;
                vis[v]=vis[u];
            }
        }
        int ans = 0;
        for(int i = 1;i<=n;i++){
            if(cnt[vis[i]-n]){
                ans+=dist[vis[i]-n];
                cnt[vis[i]-n]=1;
            }
            ans+=dist[i];
        }
        cout<<ans<<endl;
    }

}
signed main()
{
    pre();
    int t = 1;
//    cin>>t;
    while(t--)
    {
        clear();
        readmeta();
        solve();
    }
    return 0;
}
