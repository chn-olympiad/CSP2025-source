#include<bits/stdc++.h>
using namespace std;
long long n,m,k,ans=0,i;
long long u[1000005],v[1000005],w[1000005];
long long a[105][105];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(i=1;i<=m;i++)
    {
        cin>>u[i]>>v[i]>>w[i];
    }
    for(i=1;i<=k;i++)
    {
        cin>>a[i][1];
        for(long long j=2;j<=n+1;j++)
        {
            cin>>a[i][j];
        }
    }
    for(i=1;i<=m;i++)
    {
        ans += w[i];
    }
    cout<<ans<<endl;
    return 0;
}
