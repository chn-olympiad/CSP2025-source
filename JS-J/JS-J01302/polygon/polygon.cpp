#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
ll n,a[5005],ans=0,mx=0;
ll ksm(ll x,ll y){
    if(y==1)
        return x;
    ll z=1;
    while(y){
        if(y&1)
            z*=x,z%=mod;
        x*=x,x%=mod,y/=2;
    }
    return z;
}
ll fd(ll i,ll x,ll mx,ll z){
    if(i>x)return (z>mx);
    if(z>mx)return ksm(2,x-i+1);
    return (fd(i+1,x,mx,z+a[i])+fd(i+1,x,mx,z))%mod;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(ll i=1;i<=n;i++)
        cin>>a[i],mx=max(mx,a[i]);
    if(mx==1&&n>=500){
        for(ll i=3;i<=n;i++){
            ll cnt=0;
            for(ll j=2,x=1;j<i;j++){
                for(ll k=1;k<=j;k++)
                    x*=i-k;
                cnt+=x;
            }
            ans+=cnt,ans%=mod;
        }
        cout<<ans<<"\n";
        return 0;
    }
    sort(a+1,a+n+1);
    for(ll i=3;i<=n;i++)
        ans+=fd(1,i-1,a[i],0),ans%=mod;
    cout<<ans<<"\n";
    return 0;
}
