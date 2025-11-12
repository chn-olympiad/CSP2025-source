#include<bits/stdc++.h>
using namespace std;
#define int long long
#define min(x,y) ((x)<(y)?(x):(y))
#define max(x,y) ((x)>(y)?(x):(y))
#define updl(x,y) ((x)<(y)?(x):(x = y))
#define updg(x,y) ((x)>(y)?(x):(x = y))
#define rep(i,s,t,step) for(int i = s;i<=t;i+=step)
#define per(i,s,t,step) for(int i = s;i>=t;i-=step)
#define pii pair<int,int>
#define fir first
#define sec second
#define pb push_back
#define eb emplace_back
#define maxn 5005
#define maxm 5005
#define mod 998244353
// #define debug
int qmi(int a,int k,int p){
    int res = 1;
    while(k){
        if(k&1) res = res*a%p;
        a = a*a%p;
        k>>=1;
    }
    return res;
}
int n_,n,a[maxn],cnt[maxn],dp[4][maxm] = {{1}},fact[maxn],invfact[maxn];

signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int __T__ = 1;
#ifdef debug
    cin >> __T__;
#endif // debug
    fact[0] = 1;
    rep(i,1,5000,1) fact[i] = fact[i-1]*i%mod;
    invfact[5000] = qmi(fact[5000],mod-2,mod);
    per(i,4999,0,1) invfact[i] = invfact[i+1]*(i+1)%mod;
    while(__T__--){
        cin >> n_;
        rep(i,1,n_,1) cin >> a[i];
        sort(a+1,a+1+n_);
        rep(i,1,n_,1){
            if(a[i]==a[n]) cnt[n]++;
            else a[++n] = a[i],cnt[n] = 1;
        }
        int ans = cnt[1]*(cnt[1]-1)/2+cnt[1];
        rep(i,2,n,1){
            per(j,3,1,1)
                per(k,5000,1,1)
                    rep(c,1,cnt[i-1],1)
                        if(c*a[i-1]+k<=5000)
                            dp[min(3,j+c)][c*a[i-1]+k] = (dp[min(3,j+c)][c*a[i-1]+k]+dp[j][k]*fact[cnt[i-1]]%mod*invfact[c]%mod*invfact[cnt[i-1]-c]%mod)%mod;
            //j = 0,k = 0
            rep(c,1,cnt[i-1],1)
                if(c*a[i-1]<=5000)
                    dp[min(3,c)][c*a[i-1]] = (dp[min(3,c)][c*a[i-1]]+fact[cnt[i-1]]%mod*invfact[c]%mod*invfact[cnt[i-1]-c]%mod)%mod;
            ans = (ans+cnt[i]*(cnt[i]-1)/2+cnt[i])%mod;
            rep(j,1,3,1)
                rep(k,1,a[i],1)
                    ans = (ans+dp[j][k]*cnt[i])%mod;
        }
        ans = ((qmi(2,n_,mod)-1-ans)%mod+mod)%mod;
        cout << ans << '\n';
    }
    return 0;
}
/*
A little too easy bruh.
Solved the first three problems in only 53 minutes qwq.
Solved the fourth problem in my head in 57 minutes.
Snoozing_QwQ=>Happy_QwQ
^this is me qwq.
luoguid:548300/703919
                         --/
10:15                  -/ /
Finished! Snoozing...zZ/-/__
*/
