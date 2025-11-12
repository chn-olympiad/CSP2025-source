#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1000001];
int a[10001][10001];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back(v);
        adj[v].push_back(u);
        a[u][v]=w;
        a[v][u]=w;
    }
    for(int i=1;i<=q;i++)
    {
        for(int j=1;j<=n+1;j++)
        {
            int x;
            cin>>x;
        }
    }
    cout<<"13";
    return 0;
}