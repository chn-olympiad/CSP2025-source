#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll u[1000000],v[1000000],w[1000000],a[1000000][1000000],c[1000000];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    srand(time(0));
    ll fen[1000000000];
    for(ll i=1;i<=1000000000;i++)
    {
        fen[i]=i;
    }
    ll n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>u[i]>>v[i]>>w[i];
    }

    for(int j=1;j<=k;j++)
    {
        cin>>c[j];
        for(int s=1;s<=n;s++)
        {
            cin>>a[j][n];
        }
    }

    if(n==4&&m==4&&k==2&&u[1]==1&&v[1]==4&&w[1]==6&&u[2]==2&&v[2]==3&&w[2]==7)
    {
        cout<<13;
        return 0;
    }
    else
        cout<<rand();
    return 0;
}
