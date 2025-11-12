#include<bits/stdc++.h>
using namespace std;
struct node
{
    int u,v,w;
}edge[1919810];
int fa[1919810];
int m,n,k;
void inti()
{
    for(int i=1;i<=n;i++)fa[i]=i;
}
int find(int x)
{
    if(x==fa[x])return x;
    return fa[x]=find(fa[x]);
}
int merge(int x,int y)
{
    if(find(x)!=find(y))fa[find(x)]=find(y);
}
bool cmp(node a,node b)
{
    return a.w<b.w;
}
int cnt=0;
long long ans=0;
void minsc()
{
    for(int i=1;i<=m-1;i++)
    {
        int uu=edge[i].u,vv=edge[i].v,ww=edge[i].w;
        if(find(uu)!=find(vv))
        {
            merge(uu,vv);
            ans+=ww;
            cnt++;
        }
    }
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)cin>>edge[i].u>>edge[i].v>>edge[i].w;
    for(int i=1;i<=k;i++)
        for(int j=1;j<=n;j++)
    {
        int x;
        cin>>x;
        int a,b,c,d;
        cin>>a>>b>>c>>d;
    }
    inti();
    sort(edge+1,edge+m+1,cmp);
    minsc();
    cout<<ans;
    return 0;
}
