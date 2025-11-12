#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
using namespace std;
const int N=1e4+20,M=1e6+10;
int n,m,k,c[20];
ll res[1<<10],ans=inf;
int fa[N],h[N];
int fi(int x){return (fa[x]==x)?x:fa[x]=fi(fa[x]);}
void merg(int x,int y)
{
    x=fi(x),y=fi(y);
    if(x==y)return;
    if(h[x]<h[y])swap(x,y);
    fa[y]=x;
    h[x]=max(h[x],h[y]+1);
    h[y]=0;
}
struct node
{
    int u,v,w;
    bool operator <(const node &x)const
    {
        return w<x.w;
    }
}e[M],a[20][N];
node G[1<<10][N];
int len[1<<10];
ll min(ll x,ll y)
{
    return (x>y)?y:x;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        e[i]={u,v,w};
    }
    for(int i=1;i<=k;i++)
    {
        cin>>c[i];
        for(int j=1;j<=n;j++)cin>>a[i][j].w,a[i][j].u=j;
        sort(a[i]+1,a[i]+n+1);
    }
    sort(e+1,e+m+1);
    for(int i=1;i<=n;i++)fa[i]=i,h[i]=1;
    for(int i=1;i<=m;i++)
    {
        if(fi(e[i].u)==fi(e[i].v))continue;
        fa[fi(e[i].u)]=fi(e[i].v);
        G[0][++len[0]]=((node){e[i].u,e[i].v,e[i].w});
        res[0]+=e[i].w;
    }
    ans=res[0];
    for(int i=1;i<(1<<k);i++)
    {
        for(int j=0;j<k;j++)if(i&(1<<j))res[i]+=c[j+1];
        int lb=(i&(-i));
        int x=log2(lb)+1,j=i^lb;
        m=0;
        int tot=1;
        for(int s=1;s<=len[j];s++)
        {
            while(a[x][tot].w<=G[j][s].w)
            {
                e[++m]={x+n,a[x][tot].u,a[x][tot].w};
                tot++;
            }
            e[++m]=G[j][s];
        }
        while(tot<=n)
        {
            e[++m]={x+n,a[x][tot].u,a[x][tot].w};
            tot++;
        }
        for(int s=1;s<=n+k;s++)fa[s]=s,h[s]=1;
        for(int s=1;s<=m;s++)
        {
            if(fi(e[s].u)==fi(e[s].v))continue;
            merg(e[s].u,e[s].v);
            G[i][++len[i]]=((node){e[s].u,e[s].v,e[s].w});
            res[i]+=e[s].w;
        }
        ans=min(ans,res[i]);
    }
    cout<<ans<<"\n";
    return 0;
}
