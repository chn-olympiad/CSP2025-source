#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=5e3+5,mod=998244353;
int n;
ll a[maxn];
ll ans;
ll qp(ll x,ll y){
    ll ans=1;
    while(y){
        if(y&1)ans=(ans*x)%mod;
        x=(x*x)%mod;
        y>>=1;
    }
    return ans%mod;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    if(n<=20){
        for(int i=0;i<(1<<n);i++){
            int x=i,pos=1,d=0;
            ll maxx=-1,sum=0;
            while(x){
                if(x&1){
                    d++;
                    sum+=a[pos];
                    maxx=max(maxx,a[pos]);
                }
                pos++;
                x>>=1;
            }
            if(sum>2ll*maxx&&d>=3)ans=(ans+1)%mod;
        }
    }
    else{
        ans=qp(2,n);
        ans-=1;
        ans-=n;
        ans+=mod;
        ans-=1ll*n*(n-1)/2;
    }
    printf("%lld\n",(ans+mod)%mod);
    return 0;
}
