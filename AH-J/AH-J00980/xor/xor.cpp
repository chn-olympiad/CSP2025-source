#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+10;
struct Thing{
    ll l,r;
}t[N];
ll n,k,a[N],Xor[N],tot;
bool cmp(const Thing &x,const Thing &y){
    return x.r<y.r;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%lld%lld",&n,&k);
    for(ll i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        Xor[i]=Xor[i-1]^a[i];
    }
    for(ll i=1;i<=n;i++){
        ll Xorn,j=i;
        while(j<=n){
            Xorn=Xor[j]^Xor[i-1];
            if(Xorn==k) break;
            j++;
        }
        if(Xorn==k) t[++tot]={i,j};
    }
    sort(t+1,t+tot+1,cmp);
    ll R=0,ans=0;
    for(ll i=1;i<=tot;i++){
        if(t[i].l>R){
            ans++;
            R=t[i].r;
        }
    }
    printf("%lld",ans);
    return 0;
}
