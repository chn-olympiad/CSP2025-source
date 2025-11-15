#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
string s;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    bool allpass=1;
    for(ll i=0;i<n;i++){
        if(s[i]!='1'){
            allpass=0; break;
        }
    }
    if(allpass){
        ll ans=1;
        for(ll i=1;i<=n;i++){
            ans=(ans*i)%998244353;
        }
        cout<<ans<<endl;
    }
return 0;
}