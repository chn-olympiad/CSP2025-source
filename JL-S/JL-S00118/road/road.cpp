#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=1e6+5;
long long n,m,k,u[M],v[M], w[M],c[15],a[15][N];
long long ans;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++) cin>>u[i]>>v[i]>>w[i];
    for(int j=1;j<=k;j++) {
        cin>>c[j];
        for(int i=1;i<=n;i++) cin>>a[j][i];
    }
    for(int i=1;i<=m;i++) ans+=w[i];
    cout<<ans;
    return 0;
}
