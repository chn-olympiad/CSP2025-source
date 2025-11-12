#include <bits/stdc++.h>
using namespace std;
int n,m,k,minn=0x3f;
int u[1000005],v[1000005],w[1000005];
int c[20],a[20][10005],fee,cost[10005][10005];
vector <int> e[10005];
void dfs(int u,int cs)
{
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m >> k;
    for (int i=1;i<=m;i++)
    {
        cin >> u[i] >> v[i] >> w[i];
        e[u[i]].push_back(v[i]);
        e[v[i]].push_back(u[i]);
        cost[u[i]][v[i]]=w[i];
    }
    for (int i=1;i<=k;i++)
    {
        cin >> c[i];
        if (c[i]<minn)minn=c[i];
        for (int j=1;j<=n;j++)
        {
            cin >> a[i][j];
        }
    }
    cout << minn;
}
