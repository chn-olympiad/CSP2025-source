#include<bits/stdc++.h>
using namespace std;
struct node{
    int u,v,w;
}a[1100010];
int b[10030][10030];
int f[10030];
bool cmp(node x,node y)
{
    return x.w<y.w;
}
int find(int x)
{
    if(f[x]==x) return f[x];
    else return f[x]=find(f[x]);
}
int ans=0;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        f[i]=i;
    }
    for(int i=1;i<=m;i++)
    {
       cin>>a[i].u>>a[i].v>>a[i].w;
       b[a[i].u][a[i].v]=a[i].w;
       b[a[i].v][a[i].u]=a[i].w;
    }
    for(int i=1;i<=k;i++)
    {
        int c;
        cin>>c;
        for(int j=1;j<=n;j++)
        {
            int llll;
            cin>>llll;
        }
    }
    sort(a+1,a+1+m,cmp);
    for(int i=1;i<=m;i++)
    {
        if(find(a[i].u)!=find(a[i].v))
        {
            f[find(a[i].u)]=f[find(a[i].v)];
            ans+=b[a[i].u][a[i].v];
        }
    }
    cout<<ans;
    return 0;
}
