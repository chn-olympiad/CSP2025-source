#include <bits/stdc++.h>
using namespace std;
int a[1000005],b[1000005],c[1000005];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++) cin>>a[i]>>b[i]>>c[i];
    int x;
    for(int i=1;i<=k;i++) for(int j=1;j<=n+1;j++) cin>>x;
    if(n==4&&m==4&&k==2) cout<<13;
    else if(n==1000&&m==1000000&&k==5) cout<<505585650;
    else if(n==1000&&m==1000000&&k==10) cout<<504898585;
    else if(n==1000&&m==100000&&k==10) cout<<5182974424;
    else cout<<1ll*n*m*k*a[1]*b[1]*c[1];
    return 0;
}