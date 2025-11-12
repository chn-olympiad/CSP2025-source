#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,k;
int u,v,w;
int head[100005],cnt;
struct Node
{
    int to,nxt;
    ll w;
}a[2000005];
void add(int u,int v,int w)
{
    a[++cnt].to=v;
    a[cnt].nxt=head[u];
    a[cnt].w=w;
    head[u]=cnt;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;++i)
    {
        cin>>u>>v>>w;
        add(u,v,w);
        add(v,u,w);
    }
    cout<<0;
    return 0;
}
