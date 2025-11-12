#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll a[5004];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ll n,ma=-200001;
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>a[i];
        ma=max(ma,a[i]);
    }
    sort(a,a+n);
    if(n==3){
        if(a[0]+a[1]>a[2]) cout<<1;
        else cout<<0;
        return 0;
    }else if(ma==1){
        ll sum=1,ans=0;
        for(ll i=n;i>=3;i--){
            ans+=sum;
            ans=ans%998244353;
            sum*=i;
            sum/=n-i+1;
            sum=sum%998244353;
        }
        cout<<ans<<endl;
    }else{
        cout<<n<<endl;
    }
    return 0;
}
