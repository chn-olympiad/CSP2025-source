#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define endll " "
#define fre(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
#define pii pair<int,int>
#define pb push_back
#define eb emplace_back
#define lowbit(x) x&-x
#define it inline int
#define iv inline void
#define ib inline bool
using namespace std;
const int MAXN=1000050;
const int INF=0x3f3f3f3f;
const int MOD=998244353;
it gcd(int x,int y) {return y==0?x:gcd(y,x%y);}
it lcm(int x,int y) {return x/gcd(x,y)*y;}
it max(int x,int y) {return x>y?x:y;}
it min(int x,int y) {return x<y?x:y;}
it ksm(int x,int m,int mod)
{
    int res=1,bas=x%mod;
    while(m)
    {
        if(m&1)
            res=(res*bas)%mod;
        bas=(bas*bas)%mod;
        m >>= 1;
    }
    return res;
}
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());
int n,m,l,r,u,v,w,cnt,tot,ans,head[MAXN],k,val[12][MAXN],c[MAXN],dis[MAXN],fa[MAXN],cot[MAXN],valve,root;  //kruskal&ABC416E????
bool vis[MAXN];
it found(int x)
{
    if(x==fa[x])
        return x;
    return fa[x]=found(fa[x]);
}
struct edge
{
    int to,nxt,w;
}e[MAXN];
iv add_edge(int u,int v,int w)
{
    e[++tot].to=v;
    e[tot].w=w;
    e[tot].nxt=head[u];
    head[u]=tot;
}
iv kruskal(int u)
{
    vis[u]=1;
    for(int i=head[u];i;i=e[i].nxt)
    {
        int v=e[i].to,w=e[i].w;
        if(vis[v] && dis[v]>dis[u]+w)
        {
            ans-=dis[v]-dis[u]-w;
            dis[v]=dis[u]+w;
        }
        if(!vis[v])
        {
            dis[v]=dis[u]+w;
            ans+=dis[v];
            kruskal(v);
        }
    }
}
signed main()
{
    fre("road");
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    memset(dis,INF,sizeof(dis));
    for(int i=1;i<=n;i++)
        fa[i]=i;
    for(int i=1;i<=m;i++)
    {
        cin >> u >> v >> w;
        add_edge(u,v,w);
        add_edge(v,u,w);
        cot[u]++;
        cot[v]++;
    }
    for(int i=1;i<=k;i++)
    {
        cin >> c[i];
        for(int j=1;j<=n;j++)
            cin >> val[i][j];
    }
    for(int i=1;i<=n;i++)
    {
        valve=max(valve,cot[i]);
        if(valve==cot[i])
            root=i;
    }
    dis[root]=0;
    kruskal(root);
    cout<<ans;
    return 0;
}
/*
这可能是我oi生涯的最后一场比赛吧，今年什么都不会，只能写点部分分
或许我对oi再认真一点，结果就会有所不同吗？
但就算再怎么后悔，都已经结束了
只不过是个无名小卒尔尔
想必此时ZYPRESSN也如夜雨一般漆黑吧

祝学弟拿下校史第二个NOI-Au
*/
