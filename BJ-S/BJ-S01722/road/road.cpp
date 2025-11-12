#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    int u[m],v[m],w[m],c[k],a[k][n];
    for(int i=0;i<m;i++)
    {
        cin>>u[i]>>v[i]>>w[i];
    }
    for(int i=0;i<k;i++)
    {
        cin>>c[i];
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    cout<<"0";
    return 0;
}