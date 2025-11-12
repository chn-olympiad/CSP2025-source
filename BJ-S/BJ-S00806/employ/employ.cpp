#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll mod=998244353;
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    ll cnt=0;
    for (int i=0;i<n;i++){
        if(s[i]=='1'){
            cnt++;
        }
    }
    ll ans=1;
    for (ll i=1;i<=n;i++){
        ans=(ans*i)%mod;
    }
    cout<<ans<<"\n";
    return 0;
}