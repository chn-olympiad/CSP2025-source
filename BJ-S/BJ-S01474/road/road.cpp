#include<bits/stdc++.h>
using namespace std;
#define int long long
//kruskal,ke xi bu hui xie
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,k,ans=0;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        ans+=w;
    }
    cout<<ans;
    return 0;
}

