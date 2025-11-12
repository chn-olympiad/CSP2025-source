#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M=2e5+10;
ll a[3],b[3],c[3][M],t,n;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%lld",&t);
    while(t--){
        scanf("%lld",&n); ll s=0;
        memset(b,0,sizeof(b));
        memset(c,-1,sizeof(c));
        for(ll i=1;i<=n;i++){
            ll I=-1,J,K=-1;
            for(ll j=0;j<3;j++){
                scanf("%lld",&a[j]);
                if(a[j]>I) K=I,I=a[j],J=j;
                else K=max(K,a[j]);
            }
            s+=I,c[J][++b[J]]=I-K;
        }
        ll f=0;
        for(ll i=0;i<3;i++){
            sort(c[i],&c[i][b[i]+1]);
            for(ll j=1;j<=b[i]-(n>>1);j++)
            s-=c[i][j];
        }
        printf("%lld\n",s);
    }
    return 0;
}
