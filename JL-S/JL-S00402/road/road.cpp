#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
struct Node
{
    int u,v,w;
};
int n,k;
int m;
int ans;int f[N];
Node e[N];
int find(int x)
{
    return (f[x]==x? x:f[x]=find(f[x]));
}
bool cmp(Node x,Node y)
{
    return x.w<y.w;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>e[i].u;
        cin>>e[i].v;
        cin>>e[i].w;
    }
    sort(e+1,e+n+1,cmp);
    for(int i=1;i<=n;i++) f[i]=i;
    for(int i=1;i<=n;i++)
    {
        int u=find(e[i].u);
        int v=find(e[i].v);
        if(u!=v)
        {
            ans+=e[i].w;
            f[u]=v;
        }
    }
    cout<<ans;
}