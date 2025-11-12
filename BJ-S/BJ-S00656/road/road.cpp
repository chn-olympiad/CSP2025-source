#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+5;
int n,m,k,fa[N],pos,ans=0,tb[15],dtb[15];
struct Node
{
    int u,v,fl,w,f;
}e[200*N];
bool cmp(int x,int y)
{
    return x.w<y.w;
}
int find(int x)
{
    if(fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}
void merge(int u,int v)
{
    int x=find(u),y=find(v);
    if(u!=v) fa[u]=v;
}
void f(int x)
{
    for(int i=0;i<n;i++) e[x+i].w-=e[x+i].f;
}
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=k;i++) tb[i]=0,dtb[i]=1e9;
    for(int i=1;i<=m;i++) cin>>e[++pos].u>>e[pos].v>>e[pos].w;
    for(int i=1;i<=k;i++)
    {
        int fl;
        cin>>fl;
        for(int j=1;j<=n;j++)
        {
            int t;
            cin>>t;
            e[++pos].u=n+i,e[pos].v=j,e[pos].w=t+fl,e[pos].fl=pos-j+1,e[pos].f=fl;
            dtb[i]=min(dtb[i],t+fl);
        }
    }
    sort(e+1,e+pos+1,cmp);
    for(int i=1;i<=pos;i++)
    {
        int u=e[i].u,v=e[i].v;
        if(find(u)!=find(v))
        {
            merge(u,v),ans+=e[i].w;
            if(e[i].fl) f(e[i].fl),tb[max(u,v)-n]++;
        }
    }
    for(int i=1;i<=k;i++)
    {
        if(tb[i]==1) ans-=dtb[i];
    }
    cout<<ans;
    return 0;
}
