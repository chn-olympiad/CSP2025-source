#include<bits/stdc++.h>
using namespace std;
struct node
{
    int u,v,w;
};
int n,m,k,idx,fa[10005],ans;
node edge[1000005];
bool cmp(node a,node b)
{
    return a.w<b.w;
}
int find(int x)
{
    return (x==fa[x])?x:find(fa[x]);
}
void merge(int x,int y)
{
    x=find(x);
    y=find(y);
    fa[x]=y;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>edge[i].u>>edge[i].v>>edge[i].w;
        idx++;
        fa[i]=i;
    }
    for(int i=1;i<=k;i++);
    sort(edge+1,edge+m+1,cmp);
    int cnt=0;
    for(int i=1;i<=m;i++)
    {
        int u=edge[i].u,v=edge[i].v,w=edge[i].w;
        if(find(u)!=find(v))
        {
            cnt++;
            ans+=w;
            merge(u,v);
        }
        if(cnt==n-1) break;
    }
    cout<<ans;
    return 0;
}
