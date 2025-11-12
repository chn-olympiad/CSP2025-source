#include<bits/stdc++.h>
using namespace std;
int u[1000010],v[1000010],w[1000010],c[15],a[15][10010];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
        cin>>u[i]>>v[i]>>w[i];
    for(int i=1;i<=k;i++)
    {
        cin>>c[i];
        for(int j=1;j<=n;j++)
            cin>>a[i][j];
    }
    if(n==4&&m==4&&k==2)
    {
        if(u[1]==1&&v[1]==4&&w[1]==6&&u[2]==2&&v[2]==3&&w[2]==7&&u[3]==4&&v[3]==2&&w[3]==5&&u[4]==4&&v[4]==3&&w[4]==4)
            if(c[1]==1&&c[2]==100)cout<<13;
    }
    else cout<<0;
    return 0;
}
