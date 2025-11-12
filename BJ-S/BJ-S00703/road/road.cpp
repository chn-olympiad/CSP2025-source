#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    int a[n+1][n+1]={0},w[m];
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v>>w[i-1];
        a[u][v]=i;
        a[v][u]=i;
    }
    int c[k],b[k][n];
    for(int i=1;i<=k;i++)
    {
        cin>>c[i-1];
        for(int j=0;j<n;j++)
            cin>>b[i-1][j];
    }
    int sum=0;
    for(int i=0;i<m;i++)
        sum+=w[i];
    cout<<sum<<endl;
    return 0;
}
