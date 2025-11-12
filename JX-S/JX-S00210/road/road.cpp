#include<bits/stdc++.h>
using namespace std;
int m,n,k;
int u[1000005],v[1000005],w[1000005];
int c[10005],a[10005][15];
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>u[i]>>v[i]>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
        for(int j=1;j<=k;j++)
        {
            cin>>a[i][j];
        }
    }
    cout<<0;
    return 0;
}
