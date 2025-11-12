#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=550;
const long long mod=998244353;
ll n,m;
ll C[N];
ll c[N];
ll a[N];
ll ans=0;
string s;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(ll i=1;i<=n;i++){
        cin>>C[i];
        a[i]=i;
    }
    do{
        ll cnt=0;
        for(ll i=1;i<=n;i++) c[i]=C[i];
        for(ll i=1;i<=n;i++){
            if(s[i-1]=='0'){
                for(ll j=1;j<=n;j++){
                    if(c[j]!=0) c[j]--;
                }
            }
            else if(c[a[i]]!=0){
                cnt++;
            }
        }

        if(cnt>=m){
            ans++;
            ans=ans%mod;
        }
    }
    while(next_permutation(a+1,a+1+n));
    cout<<ans;
    return 0;
}
