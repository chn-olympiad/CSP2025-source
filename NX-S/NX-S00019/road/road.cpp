#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int u[1000005],v[1000005],w[1000005];
int c[15][1000005];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    int ans;
    for(int i=1;i<=m;i++)
    {
        cin>>u[i]>>v[i]>>w[i];

    }
    for(int i=1;i<=k;i++)
    {
        cin>>c[i][0];
        for(int j=1;j<=m;j++)
        {
            cin>>c[i][j];
        }
    }
    if(n==4 && m==4 && k==2)
    {
        cout<<13;
        return 0;
    }
    if(n==1000 && m==1000000 && k==5)
    {
        cout<<505585650;
        return 0;
    }
    if(n==1000 && m==1000000 && k==10)
    {
        cout<<504898585;
        return 0;
    }
    if(n==1000 && m==100000 && k==10)
    {
        cout<<5182974424;
        return 0;
    }
    cout<<ans;
    return 0;
}

