#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=998244353;
ll n,a[5005],ans=0;
void dfs(ll i,ll sum,ll tot){
    if(i>n) return ;
    dfs(i+1,sum,tot);
    if(tot+1>=3){
        if(sum+a[i]>a[i]*2){
            ans=(ans+1)%mod;
        }
    }
    dfs(i+1,sum+a[i],tot+1);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n-2;i++){
        dfs(i+1,a[i],1);
    }
    printf("%lld",ans%mod);
    return 0;
}
