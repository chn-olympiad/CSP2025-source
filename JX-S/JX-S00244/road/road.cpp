#include<bits/stdc++.h>
using namespace std;
long long  n,m,k,u,v,w,JJ,c;
long long  a[20][10010];
long long ans=0;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        scanf("%lld%lld%lld",&u,&v,&w);
        ans+=w;
    }
    for(int j=1;j<=k;j++){
        scanf("%lld",&c);
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[j][i]);
        }
    }
    cout<<ans;
    return 0;
}
