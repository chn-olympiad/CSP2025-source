#include<bits/stdc++.h>
#define int long long
#define inf 1e18
using namespace std;
inline int read()
{
    char ch=getchar();
    int w=0,c=1;
    while(ch>'9'||ch<'0')
    {
        if(ch=='-')c=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        w=(w<<1)+(w<<3)+ch-48;
        ch=getchar();
    }
    return w*c;
}
#define maxn 11111
int n,m,k;
struct node{int u,v,w;}edge[maxn],edge1[maxn];
bool cmp(node s,node p){return s.w<p.w;}
int c[maxn];
int a[maxn][maxn];
int fa[maxn],fnl=inf;
int fnd(int x)
{
    if(fa[x]==x)return x;
    else return fa[x]=fnd(fa[x]);
}
int prim(int nm)
{
    sort(edge+1,edge+nm+1,cmp);
    int ans=0;
    for(int i=1;i<=nm;i++)
    {
        int u=edge[i].u,v=edge[i].v,w=edge[i].w;
        if(fnd(u)!=fnd(v))fa[fnd(u)]=fnd(v),ans+=w;
    }
    return ans;
}
bool vis[11];
void dfs(int pos)
{
    if(pos==k+1)
    {
        int cnt=0;
        for(int i=1;i<=n;i++)fa[i]=i;
        int nm=m;
        for(int i=1;i<=m;i++)edge1[i]=edge[i];
        for(int i=1;i<=k;i++)
        {
            if(vis[i])
            {
                cnt+=c[i]+a[i][i];
                for(int j=1;j<=n;j++)edge[++nm]={i,j,a[i][j]};
            }
        }
        fnl=min(fnl,cnt+prim(nm));
        //for(int i=1;i<=nm;i++)cout<<edge[i].u<<" "<<edge[i].v<<" "<<edge[i].w<<endl;
        for(int i=1;i<=m;i++)edge[i]=edge1[i];
        return;
    }
    vis[pos]=1;
    dfs(pos+1);
    vis[pos]=0;
    dfs(pos+1);
}
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n=read(),m=read(),k=read();
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=m;i++)
    {
        int u=read(),v=read(),w=read();
        edge[i]={u,v,w};
    }
    int acd=0;
    for(int i=1;i<=k;i++)
    {
        c[i]=read();acd+=c[i];
        for(int j=1;j<=n;j++)a[i][j]=read(),acd+=a[i][j];
    }
    if(acd==0)
    {
        for(int i=1;i<=k;i++)
            for(int j=1;j<=n;j++)fa[fnd(i)]=fnd(j);
        sort(edge+1,edge+m+1,cmp);
        int ans=0;
        for(int i=1;i<=m;i++)
        {
            int u=edge[i].u,v=edge[i].v,w=edge[i].w;
            if(fnd(u)!=fnd(v))fa[fnd(u)]=fnd(v),ans+=w;
        }
        printf("%lld",ans);
        return 0;
    }
    if(k==0)printf("%lld",prim(m));
    else dfs(1),printf("%lld",fnl);
    return 0;
}
