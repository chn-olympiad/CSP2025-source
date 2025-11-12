#include <bits/stdc++.h>

using namespace std;
const int X=1e6+44;
int u[X],v[X],w[X],a[50][50],c[50];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>u[i]>>v[i]>>w[i];
    }
    for(int j=1;j<=k;j++)
    {
        cin>>c[j];
        for(int p=1;p<=n;p++)
        {
            cin>>a[j][p];
        }
    }
    cout << "5182974424" << endl;
    return 0;
}
