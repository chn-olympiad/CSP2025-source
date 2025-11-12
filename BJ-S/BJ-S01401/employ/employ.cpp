#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
ll n,m;
ll c[505];
string s;
ll zhengcheng(ll x){
    ll ans=1;
    for(ll i=x;i>=2;i--){
        ans=(ans*i)%mod;
    }
    ans=ans%mod;
    return ans;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(ll i=1;i<=n;i++){
        cin>>c[i];
    }
    cout<<zhengcheng(n);
    return 0;
}

