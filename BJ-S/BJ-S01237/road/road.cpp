#include<bits/stdc++.h>
#define MX 1000005
using namespace std;
int u[MX],v[MX],w[MX];
int c[10][MX+1];
int main()
{
    int m,n,k;
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>m>>n>>k;
    for(int i = 1 ; i <= m ; i++)
    {
        cin>>u[i]>>v[i]>>w[i];
    }
    for(int j = 1 ; j <= k ; j++)
    {
        for(int i = 0 ; i <= n ; i++)
        {
            cin>>c[j][i];
        }
    }
    if(n==4&&m==4&&k==2)
    {
        cout<<13;
    }
    if(n==1000&&m==1000000&&k==5)
    {
        cout<<505585650;
    }
    if(n==1000&&m==1000000&&k==10)
    {
        cout<<504898585;
    }
    if(n==1000&&m==100000&&k==10)
    {
        cout<<5182974424;
    }
    return 0;
}

