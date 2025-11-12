#include<bits/stdc++.h>
using namespace std;
int n,m,k,x,y,z,ans;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++) cin>>x>>y>>z;
    for(int i=1;i<=k;i++) for(int j=1;j<=n+1;j++) cin>>x,ans+=x;
    cout<<ans<<endl;
    return 0;
}
