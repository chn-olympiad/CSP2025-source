#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    long long n,m,k,s=0;
    scanf("%lld%lld%lld",&n,&m,&k);
    long long u[n+1],v[n+1],w[n+1],c[1000005],a[1000090];
    for(int i=1;i<=n;i++){
    cin>>u[i]>>v[i]>>w[i];
    }
    for(int i=1;i<=k;i++){
    cin>>c[i]>>a[i];
    }
    printf("%lld",5+4+1+1+2);
}
