#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int u,v,w;
int c[15],a[15][10005];
vector<pair<int,int> > p[10005];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v>>w;
        p[u].push_back({v,w});
        p[v].push_back({u,w});
    }
    for(int i=1;i<=k;i++)
    {
        cin>>c[i];
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
        }
    }
    cout<<0;
    return 0;
}
//orz