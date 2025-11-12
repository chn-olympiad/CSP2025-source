#include <bits/stdc++.h>
using namespace std;
long long n,m,k,i,j,u1,u2,u3,ans;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(i=1;i<=m;i++){
        cin>>u1>>u2>>u3;
        ans+=u3;
    }
    for(i=1;i<=k;i++){
        for(j=1;j<=n;j++) cin>>u1;
    }
    cout<<ans;
    return 0;
}
