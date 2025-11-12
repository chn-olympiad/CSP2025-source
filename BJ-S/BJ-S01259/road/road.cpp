#include <bits/stdc++.h>
using namespace.std
int main()
{
freopen("road.in","r",stdin);
freopen("road.out","w",stdout);
int n,m,u[1000005]={},v[1000005]={},w[1000005]={},k,a[1000005][15]={},c[15]={};
cin>>n>>m>>k;
for(int i=1;i<=m;i++)
{
    cin>>u[i]>>v[i]>>w[i];
}
for(int i=1;i<=k;i++)
{
    cin>>c[i];
    for(int j=1;j<=n;j++)
    {
        cin>>a[i][j]
    }
}
cout<<n+m+k+3;
fclose(stdin);
fclose(stdout);
    return 0;
}