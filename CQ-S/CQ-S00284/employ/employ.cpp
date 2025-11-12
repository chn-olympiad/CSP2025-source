#include<bits/stdc++.h>
#define N1 18
#define ll long long
#define N 505
#define mod 998244353
using namespace std;
int dp[(1<<N1)+5][N1+5],n,cnt,p[N],m;
string s;
inline void solve1(){
    dp[0][0]=1;
    for(int msk=0;msk<(1<<n);msk++){
        int cnt=__builtin_popcount(msk);
        for(int i=0;i<n;i++){
            if(!(msk>>i&1)){
                int fmsk=msk|(1<<i);
                for(int j=0;j<=cnt;j++){
                    if(cnt-j<p[i]&&s[cnt+1]=='1'){
                        (dp[fmsk][j+1]+=dp[msk][j])%=mod;
                    }else{
                        (dp[fmsk][j]+=dp[msk][j])%=mod;
                    }
                }
            }
        }
    }int Ans=0;
    for(int i=m;i<=n;i++){
        (Ans+=dp[(1<<n)-1][i])%=mod;
    }cout<<Ans<<endl;
}
inline ll fastpow(ll a,ll b){
    ll ret=1;
    while(b){
        if(b&1){
            (ret*=a)%=mod;
        }(a*=a)%=mod;b>>=1;
    }return ret;
}
inline void solve2(){
    int ok=0;
    for(int i=0;i<n;i++){
        ok+=(p[i]!=0);
    }
    if(ok>=m){
        ll fac=1;
        for(int i=1;i<=n;i++){
            (fac*=1ll*i)%=mod;
        }cout<<fac<<endl;
    }else{
        cout<<0<<endl;
    }
}
bool opa=1;
signed main(){
    freopen("employ.in","r",stdin);freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    cin>>s;s=" "+s;
    for(int i=1;i<=n;i++){
        opa&=(s[i]=='1');
    }
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    if(n<=18){
        solve1();
    }else if(opa){
        solve2();
    }
}