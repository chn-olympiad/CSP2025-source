#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
ll n,a[100005],ans,f[1000005];
ll mx(int l,int r){
    ll res=0;
    for(ll i=l;i<=r;++i)res=max(res,f[i]);
    return res;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;++i)cin>>a[i];
    sort(a+1,a+n+1);
    if(n==3){
        cout<<(a[1]+a[2]>a[3]);
        return 0;
    }
    for(ll i=3;i<=n;++i){
        for(ll j=1;j<i;++j){
            for(ll b=j+1;b<i;++b){
                if(j==b)continue;
                if(j+b>a[i])ans=(ans+1)%mod;
            }
        }
    }
    cout<<ans;
    return 0;
}
