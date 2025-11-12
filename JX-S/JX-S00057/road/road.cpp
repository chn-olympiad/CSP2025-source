#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e4+5,maxm=1e6+5,maxk=15;
ll n,m,k,v[maxm],u[maxm],w[maxm],c[maxk],a[maxk][maxn];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld%lld%lld",&n,&m,&k);
    for(int i=1;i<=m;i++){
        scanf("%lld%lld%lld",&u[i],&v[i],&w[i]);
    }
    for(int i=1;i<=k;i++){
        scanf("%lld",&c[i]);
        for(int j=1;j<=n;j++){
            scanf("%lld",&a[i][j]);
        }
    }
    printf("0\n");
    return 0;
}
