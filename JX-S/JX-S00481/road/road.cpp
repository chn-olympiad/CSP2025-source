#include<bits/stdc++.h>
using namespace std;
/*

*/
struct FSI{
    template<typename T>
    FSI& operator >> (T &res){
        res=0;T f=1;char ch=getchar();
        while (!isdigit(ch)){if (ch=='-') f=-1;ch=getchar();}
        while (isdigit(ch)){res=res*10+ch-'0';ch=getchar();}
        res*=f;
        return *this;
    }
}scan;
typedef long long ll;
typedef pair<ll,int> pii;
const int N=2e4+10,M=2e6+10,K=20;
const ll inf=2e18+10;
int n,m,k,i,j,x,y;
ll co[N],f[K][N],z;
ll d[N],ans=inf;
bool ok[N],vis[N];
int last[N],c;
int cnt;
int fa[N];
priority_queue<pii,vector<pii>,greater<pii> > q;
struct Node{
    int to,nxt;
    ll len;
}a[M<<1];
struct Edge{
    int x,y;
    ll z;
}e[M],t[M];
inline void add(int u,int v,ll w)
{
    a[++c]={v,last[u],w};
    last[u]=c;
}
inline ll prim(int s)
{
    int i,x,to;
    ll res=0,len,val;
    for (i=1;i<=n+k;i++) d[i]=inf,vis[i]=false;
    while (!q.empty()) q.pop();
    d[s]=0;
    q.push({0,s});
    while (!q.empty())
    {
        val=q.top().first;
        x=q.top().second;
        q.pop();
        if (vis[x]) continue;
        vis[x]=true;
        res+=val;
        for (i=last[x];i;i=a[i].nxt)
        {
            to=a[i].to;
            len=a[i].len;
            if (len<d[to])
            {
                d[to]=len;
                q.push({d[to],to});
            }
        }
    }
    return res;
}
inline void calc(ll sum)
{
    int i,j;
    for (i=1;i<=n+k;i++) last[i]=0;
    c=0;
    for (i=1;i<=cnt;i++)
    {
        add(t[i].x,t[i].y,t[i].z);
        add(t[i].y,t[i].x,t[i].z);
    }
    for (i=1;i<=k;i++)
    {
        if (ok[i])
        {
            for (j=1;j<=n;j++)
            {
                add(n+i,j,f[i][j]);
                add(j,n+i,f[i][j]);
            }
        }
    }
    ans=min(ans,sum+prim(1));
}
void dfs(int dep,ll sum)
{
    if (dep>k)
    {
        calc(sum);
        return;
    }
    ok[dep]=true;
    dfs(dep+1,sum+co[dep]);
    ok[dep]=false;
    dfs(dep+1,sum);
}
int find(int x)
{
    if (fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}
bool merge(int x,int y)
{
    x=find(x);
    y=find(y);
    if (x==y) return false;
    fa[x]=y;
    return true;
}
bool cmp(Edge x,Edge y)
{
    return x.z<y.z;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scan>>n>>m>>k;
    for (i=1;i<=m;i++) scan>>e[i].x>>e[i].y>>e[i].z;
    sort(e+1,e+m+1,cmp);
    for (i=1;i<=n;i++) fa[i]=i;
    for (i=1;i<=m;i++)
    {
        if (merge(e[i].x,e[i].y)) t[++cnt]={e[i].x,e[i].y,e[i].z};
    }
    for (i=1;i<=k;i++)
    {
        scan>>co[i];
        for (j=1;j<=n;j++) scan>>f[i][j];
    }
    dfs(1,0);
    printf("%lld\n",ans);
    return 0;
}
