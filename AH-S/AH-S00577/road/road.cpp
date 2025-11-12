#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("road.in";"r";stdin);
    freopen("road.out";"w";stdout);
    int n,m,k,ans;
    cin>>n>>m>>k;
    int u[m+1],v[m+1],w[m+1],c[k+1],a[k+1][n+1];
    for(int i=1;i<=m;i++)
    {
        cin>>u[i]>>v[i]>>w[i];
    }
    for(int i=1;i<=k;i++)
    {
        cin>>c[i];
        fro(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
        }
    }
    return 0;
}
