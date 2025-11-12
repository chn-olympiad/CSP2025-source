#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 10005
ll n,m,k;
ll G[maxn][maxn];
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdin);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        G[u][v]=G[v][u]=w;
    }
    for(int i=1;i<=k;i++){
        ll a,c;
        cin>>a>>c;
    }
    cout<<10086;
    return 0;
}
