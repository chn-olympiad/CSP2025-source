#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k,u[1005],v[1005],w[1005],c[1005],a[1005][1005],ans=0x3f3f3f3f;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    ll ans2=0;
    for(int i=1;i<=m;i++)
    {
        cin>>u[i]>>v[i]>>w[i];
        ans2+=w[i];
    }
    ans=min(ans,ans2);
    ll ans1=0;
    for(int i=1;i<=k;i++)
    {
        cin>>c[i];

        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
            ans1+=a[i][j];
        }
    }
    ans=min(ans,ans1);
    cout<<ans;
    return 0;
}
