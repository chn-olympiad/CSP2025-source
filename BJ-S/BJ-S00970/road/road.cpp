#include<bits/stdc++.h>
using namespace std;
int n,m,k,c[1000010];
vector <int> g[10010],b[10010];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int ans=0;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        ans+=w;
        g[u].push_back(v);
        g[v].push_back(u);
        b[u].push_back(w);
        b[v].push_back(w);
    }
    for(int i=1;i<=k;i++)
    {
        cin>>c[n+i];
        int x;
        cin>>x;
        g[n+i].push_back(i);
        g[i].push_back(n+i);
        b[n+i].push_back(x);
        b[i].push_back(x);
    }
    cout<<ans;
    return 0;
}
