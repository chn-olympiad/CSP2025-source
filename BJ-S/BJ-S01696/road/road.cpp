#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int u,v,w;
struct l
{
    int u,v,w;
    bool operator<(const l i)const
    {
        return w<i.w;
    }
}l[1100006];
int fa[10004];
int gf(int x)
{
    return (x==fa[x]?x:fa[x]=gf(fa[x]));
}
long long ans;
int c[15];
int a[15][10004];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n+10;i++)
        fa[i]=i;
    for(int i=1;i<=m;i++)
    {
        cin>>l[i].u>>l[i].v>>l[i].w;
    }
    for(int i=1;i<=k;i++)
    {
        cin>>c[i];
        for(int j=1;j<=n;j++)cin>>a[i][j];
    }
    if(k==0)
    {
        sort(l+1,l+m+1);
        for(int i=1;i<=m;i++)
        {
            u=l[i].u;
            v=l[i].v;
            w=l[i].w;
            if(gf(u)==gf(v))continue;
            fa[gf(u)]=gf(v);
            ans+=w;
        }
        cout<<ans;
    }
    else
    {
        for(int i=1;i<=k;i++)
        {
            for(int j=1;j<=n;j++)
            {
                l[++m]={j,i+n,a[i][j]};
            }
        }
        sort(l+1,l+m+1);
        for(int i=1;i<=m;i++)
        {
            u=l[i].u;
            v=l[i].v;
            w=l[i].w;
            if(gf(u)==gf(v))continue;
            fa[gf(u)]=gf(v);
            ans+=w;
        }
        cout<<ans;
    }
    return 0;
}
