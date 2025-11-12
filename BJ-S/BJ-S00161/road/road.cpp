#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct node
{
    int u,v,w;
}a[1000010];
int fa[1000010];
int c[15];
int b[20][1000010];
long long ans;
int find(int x)
{
    if(fa[x])
        return x;
    return fa[x]=find(fa[x]);
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w"stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>a[i].u>>a[i].v>>a[i].w;
    }
    for(int i=1;i<=k;i++)
    {
        cin>>c[i];
        for(int j=1;j<=n;j++)
        {
            cin>>b[i][j];
        }
    }
    for(int i=1;i<=n;i++)fa[i]=i;
    if(k==0)
    {
        for(int i=1;i<=n;i++)
        {
            int u=a[i].u,v=a[i].v,w=a[i].w;
            if(find(u)==find(v))continue;
            fa[find(u)]=fa[find(v)];
            ans+=a[i].w;
        }
    }
    cout<<ans;
    return 0;
}
