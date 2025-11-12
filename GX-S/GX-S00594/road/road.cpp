#include <bits/stdc++.h>
using namespace std;
long long n,m,k,fa[10005],c[15],town[15][10005];
struct node
{
    long long u,v,w;
}g[1000005];
bool cmp(node x,node y)
{
    return x.w<y.w;
};
long long get(long long x)
{
    if(fa[x]==x) return x;
    return fa[x]=get(fa[x]);
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(long long i=1;i<=m;i++) cin>>g[i].u>>g[i].v>>g[i].w;
    for(long long i=1;i<=k;i++)
    {
        cin>>c[i];
        for(long long j=1;j<=n;j++)
        {
            cin>>town[i][j];
            fa[j]=j;
        }
    }
    sort(g+1,g+1+m,cmp);
    long long ans=0,sum=0;
    for(long long i=1;i<=m&&sum<n-1;i++)
    {
        long long ru=get(g[i].u),rv=get(g[i].v);
        if(ru!=rv)
        {
            ans+=g[i].w;
            sum++;
        }
    }
    cout<<ans;
    return 0;
}
