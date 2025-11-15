#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN=505, MOD=998244353;
ll dp[(1<<18)+5][19], n, m, a[MAXN], ans;
string s;
int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin>>n>>m>>s;
    for(ll i=0; i<n; i++){
        cin>>a[i];
    }
    dp[0][0]=1;
    for(ll i=0; i<(1<<n); i++){
        ll l=__builtin_popcount(i);
        for(ll j=0; j<=n; j++){
            for(ll k=0; k<n; k++){
                if(!(i>>k&1)){
                    dp[i^(1<<k)][j+(s[l]=='1'&&l-j<a[k])]=(dp[i^(1<<k)][j+(s[l]=='1'&&l-j<a[k])]+dp[i][j])%MOD;
                }
            }
        }
    }
    for(ll i=m; i<=n; i++){
        ans=(ans+dp[(1<<n)-1][i])%MOD;
    }
    cout<<ans;
    return 0;
}