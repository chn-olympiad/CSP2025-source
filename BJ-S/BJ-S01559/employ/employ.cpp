#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=998244353;
int n,m;
int f[262145][19];
string s;
void upd(int &x,int y){
    x=((long long)x+y)%mod;
}
int c[505];
int dp[505][505];
ll fac[505];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    cin>>s;
    fac[0]=1;
    for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
    s="#"+s;
    int cnt=0;
    for(int i=1;i<=n;i++) if(s[i]=='0') cnt++;
    int cnt0=0;
    for(int i=1;i<=n;i++){
        cin>>c[i];
        if(c[i]==0) cnt0++;
    }
    // if(cnt==0){
    //     if(n-cnt0>=m){
    //         cout<<fac[n]<<"\n";
    //     }else{
    //         cout<<0<<"\n";
    //     }
        
    //     return 0;
    // }
    f[0][0]=1;
    for(int S=0;S<(1<<n);S++){
        int now=0;
        for(int j=0;j<n;j++){
            if(S&(1<<j)) now++;
        }
        for(int i=0;i<=now;i++){
            int notin=now-i;
            for(int j=1;j<=n;j++){
                if(S&(1<<(j-1))) continue;
                int ns=S|(1<<(j-1));
                if(notin>=c[j]||s[now+1]=='0') upd(f[ns][i],f[S][i]);
                else upd(f[ns][i+1],f[S][i]);
            }
        }
    }
    ll ans=0;
    for(int i=m;i<=n;i++){
        upd(ans,f[(1<<n)-1][i]);
    }
    cout<<ans<<"\n";
}