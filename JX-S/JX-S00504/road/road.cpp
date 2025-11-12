#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n,m,k,u[1000010],v[1000010],w[1000010],c[11],a[11][10010];
int main()
{
    freopen("road.in","w",stdin);
    freopen("road.out","r",stdout);
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
            cin>>a[i][j];
        }
    }
    int d=0;
    for(int i=1;i<=k;i++)
    {
        if(c[i]==1)
        {
            d=1;
        }
            for(int j=1;j<=n;j++)
            {
                if(a[i][j]==1)
                    d=1;
            }
    }
    if(d==0)
        cout<<0;
}
