#include<bits/stdc++.h>
using namespace std;
struct edge
{
    int u,v,w;
}e[100005];
int n,m,k,fa[100005];
bool cmp(edge a,edge b)
{
    return a.w<b.w;
}
int find(int x)
{
    if(x==fa[x])return x;
    return fa[x]=find(fa[x]);
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=m;i++)
    {
        cin>>e[i].u>>e[i].v>>e[i].w;
    }
    sort(e+1,e+m+1,cmp);
    int cnt=0,ans=0;
    for(int i=1;i<=m&&cnt<n-1;i++)
    {
        int x=e[i].u,y=e[i].v,val=e[i].w;
        int fx=find(x),fy=find(y);
        if(fx!=fy)
        {
            fa[fx]=fy;
            ans+=val;
            cnt++;
        }
    }
    cout<<ans;
    return 0;
}
