#include<bits/stdc++.h>
#define ll long long
const ll maxn=1000050;
using namespace std;
ll n,m,k,x,u[maxn],v[maxn],w[maxn],c[maxn],a[15][100050];
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>u[i]>>v[i]>>w[i];
        x+=w[i];
    }
    for(int i=1;i<=k;i++)
    {
        cin>>c[i];
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
        }
    }
    cout<<x;
    return 0;
}
