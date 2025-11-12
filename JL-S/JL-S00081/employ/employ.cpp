#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    ll cnt=0;
    for(int i=1;i<=n;++i){
        ll x;
        cin>>x;
        if(x!=0)++cnt;
    }
    ll ans=1;
    for(int i=1;i<=cnt;++i){
        ans*=i;
        ans%=mod;
    }
    cout<<ans;
    return 0;
}
