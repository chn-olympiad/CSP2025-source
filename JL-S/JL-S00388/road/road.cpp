#include<bits/stdc++.h>
using namespace std;
int a[20000];
struct in
{
    int u,v,w;
};
in hc[2000000];
int f[20000];
int cmp(in x,in y)
{
    return x.w<y.w;
}
int xy(int x)
{
    if(f[x]==x)
    {
        return x;
    }
    return f[x]=xy(f[x]);
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k,zs=0;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>hc[i].u>>hc[i].v>>hc[i].w;
    }
    sort(hc+1,hc+m+1,cmp);
    for(int i=1;i<=n;i++)
    {
        f[i]=i;
    }
    for(int i=1;i<=m;i++)
    {
        int u=hc[i].u;
        int v=hc[i].v;
        int w=hc[i].w;
        if(xy(u)!=xy(v))
        {
            zs+=w;
            f[xy(v)]=xy(u);
        }
    }
    cout<<zs;
    return 0;
}
