#include<bits/stdc++.h>
#define mm 1000010
#define ll long long
using namespace std;
int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0' || ch>'9')
    {
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0' && ch<='9')
    {
        x=(x<<3)+(x<<1)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
struct node
{
    int x,y,w;
    bool operator <(const node X)const
    {
        return X.w>w;
    }
}a[mm],b[mm],c[mm];
int tot;
int n,m,k;
int fa[mm];
int find(int x)
{
    if(fa[x]==x) return fa[x];
    return fa[x]=find(fa[x]);
}
ll ans;
void del_bian()
{
    sort(a+1,a+m+1);
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=m;i++)
    {
        int x=a[i].x,y=a[i].y,w=a[i].w;
        if(find(x)==find(y)) continue;
        ans+=w;
        fa[find(x)]=find(y);
        b[++tot]=a[i];
        if(tot==n-1) return ;
    }
}
int chu[13];
int v[13][mm];
bool vis[13];
ll check()
{
    ll add=0;
    int cnt=0;
    for(int i=1;i<=tot;i++) c[++cnt]=b[i];
    for(int i=1;i<=k;i++)if(vis[i])
    {
        add+=chu[i];
        for(int j=1;j<=n;j++) c[++cnt]=(node){n+i,j,v[i][j]};
    }
    sort(c+1,c+cnt+1);
    int num=0;
    for(int i=1;i<=n+k;i++) fa[i]=i;
    for(int i=1;i<=cnt;i++)
    {
        int x=c[i].x,y=c[i].y,w=c[i].w;
        if(find(x)==find(y)) continue;
        fa[find(x)]=find(y);
        add+=w;
        num++;
        if(num==n+k-1) break;
    }
    return add;
}
void dfs(int x,ll last_ans)
{
    if(x==k+1)
    {
        return ;
    }
    vis[x]=1;
    ll add=check();
    if(add<=last_ans)
    {
        ans=min(ans,add);
        dfs(x+1,add);
    }
    vis[x]=0;
    dfs(x+1,last_ans);
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n=read(),m=read(),k=read();
    for(int i=1;i<=m;i++) a[i].x=read(),a[i].y=read(),a[i].w=read();
    del_bian();
    for(int i=1;i<=k;i++)
    {
        chu[i]=read();
        for(int j=1;j<=n;j++) v[i][j]=read();
    }
    dfs(1,ans);
    printf("%lld\n",ans);
    return 0;
}
/*
127322635566
*/