#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    long long sum=0,n,m,k,a[100000],b[100000],c[100000],d[100000],e[100000];
    long long u[100000],v[100000],w[100000];
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>u[i]>>v[i]>>w[i];
    }
    for(int i=1;i<=k;i++)
    {
        cin>>a[i]>>b[i]>>c[i]>>d[i]>>e[i];
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=m-1;j++)
        {
            if(w[j]>w[j+1])
            {
                swap(w[j],w[j+1]);
            }//
        }
    }
    for(int i=1;i<=m/2;i++)
    {
        sum+=w[i];
    }
    for(int i=1;i<=k/2;i++)
    {
        sum+=a[i];
        sum+=b[i];
    }
    cout<<sum;
    return 0;
}
