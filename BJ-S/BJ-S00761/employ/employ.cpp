#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll P=998244353;
ll n,m,ans,dp[(1<<18)+5][20],c[505];
string s;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    for(ll i=0;i<n;i++) cin>>c[i];
    if(n<=18){
        dp[0][0]=1;
        for(ll i=0;i<(1<<n);i++){
            for(ll j=0;j<=n;j++){
                ll cnt=0;
                for(ll k=0;k<n;k++){
                    if(i&(1<<k)) cnt++;
                }
                for(ll k=0;k<n;k++){
                    if(i&(1<<k)) continue;
                    (dp[i|(1<<k)][j+(j>=c[k]||s[cnt]=='0')]+=dp[i][j])%=P;
                }
            }
        }
        for(ll i=0;i<=n-m;i++) (ans+=dp[(1<<n)-1][i])%=P;
        cout<<ans;
    }else{
        ll res=1;
        for(ll i=1;i<=n;i++) (res*=n)%=P;
        cout<<res;
    }
    return 0;
}
