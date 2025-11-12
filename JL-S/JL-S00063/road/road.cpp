#include <bits/stdc++.h>
using namespace std;
int n,m,k,i,j,l;
int v[1000001],u[1000001],w[1000001],c[11],a[11][10001];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(i=0;i<m;i++)
    {
        cin>>u[i]>>v[i]>>w[i];
    }
    for(i=0;i<k;i++)
    {
        cin>>c[i];
        for(j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<m;j++)
        {
            if(w[i]>w[j])
              swap(w[i],w[j]);
        }
        l=l+w[i];
    }
    cout<<l;
    return 0;
}
