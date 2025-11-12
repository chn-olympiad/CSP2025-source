#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int N=2001100;

inline int read()
{
    int f=1,x=0; char ch=getchar();
    while(!isdigit(ch)) {  if(ch=='-') f=-1; ch=getchar(); }
    while(isdigit(ch))  {  x=x*10+ch-'0';    ch=getchar(); }
    return f*x;
}

struct edge
{
    int u,v,w;
    bool operator < (const edge &t)const
    { return w<t.w; }
}e[N<<1];
int tot;
int n,m,k;
long long ans;

int dad[N],siz[N],maxn;
int cst[N],vis[N];

int findset(int x)
{
    if(dad[x]==x) return x;
    return dad[x]=findset(dad[x]);
}

inline bool mergeset(int u,int v)
{
    u=findset(u),v=findset(v);
    if(u==v) return false;
    dad[v]=u,siz[u]+=siz[v];
    maxn=max(maxn,siz[u]);
    return true;
}

signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n=read(),m=read(),k=read();
    for(int i=1;i<=m;i++)
    { tot++;e[tot].u=read(),e[tot].v=read(),e[tot].w=read(); }
    for(int i=1;i<=k;i++)
    {
        int cst=read();
        for(int j=1;j<=n;j++)
        {
            int w=read();tot++;
            e[tot].u=j,e[tot].v=i+n;e[tot].w=w;
        }
    }
    sort(e+1,e+tot+1);
    for(int i=1;i<=n+k;i++) dad[i]=i;
    for(int i=1;i<=n;i++) siz[i]=1;
    for(int i=1;i<=tot;i++)
    {
        int u=e[i].u,v=e[i].v;
        if(!mergeset(u,v)) continue;
        ans+=1LL*e[i].w;
        if(v>n && !vis[v-n]) cst[v-n]=e[i].w,vis[v-n]=1;
        else if(v>n && vis[v-n])  vis[v-n]=-1;
        if(maxn==n) break;
    }
    for(int i=1;i<=k;i++)
      if(~vis[i]) ans-=cst[i];
    printf("%lld\n",ans);
    return 0;
}

