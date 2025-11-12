// Xue_Zhoujun_RhF6 AK IOI!!!!!!!!!!!!!!!!!!!!!!!!!!!
// If you CE, check "; " 
#include <bits/stdc++.h>
#include <bits/extc++.h>
#define LP(i, n) for (int i=1; i<=n; ++i)
#define FR(i, n) for (int i=0; i<n;  ++i)
#define LOP(i, d, n) for (int i=d; i<=n; ++i)
#define FOR(i, d, n) for (int i=d; i<n;  ++i)
#define il inline
#define gc getchar
#define pc putchar
#define qw qwrite
#define qr qread
// #define DBG
using namespace std; 
using ll=long long; 
using vi=vector<int>; 
using vll=vector<ll>; 
ll qread() {
    ll sum=0; 
    char c, e=1; 
    while (!isdigit(c=getchar())) if (c=='-') e=-1; else if (c==EOF) return 0; 
    while (isdigit(c)) sum=(sum<<3)+(sum<<1)+(c^48), c=gc(); 
    return e*sum; 
}
void qwrite(ll x) {
    if (x<0) pc('-'), x=-x; 
    if (x>9) qwrite(x/10); 
    pc(x%10+'0'); 
}
const ll MOD=998244353, MAXL=5555; 
int qpow(int base, int power) {
    ll prod=1; 
    while (power) {
        if (power&1) prod*=base, prod%=MOD; 
        base*=base, power>>=1, base%=MOD; 
    }
    return prod; 
}

ll n, a[MAXL];
ll pre[MAXL], dp[MAXL][MAXL]; 
ll solve1to3() {
    ll mx=max({a[1], a[2], a[3]}); 
    if (pre[3]-mx>mx) return 1; 
    else return 0; 
}
ll solve4to6() {
    ll mx=0; 
    LP(i, n) mx=max(mx, a[i]); 
    return 0; 
    // dfs(); 
    // bu hui !!!!!!!!!!
}
bool check15to20() {
    LP(i, n) if (a[i]!=1) return 0; 
    return 1; 
}
ll solve15to20() {
    // cout << "15--20\n"; 
    // C_n^3+C_n^4+...+C_n^n
    dp[0][0]=1; LP(i, n) dp[i][0]=1; 
    LP(i, n) LP(j, i) dp[i][j]=(dp[i-1][j]+dp[i-1][j-1])%MOD;
    ll ans=0; 
    LOP(i, 3, n) ans=(ans+dp[n][i])%MOD; 
    return ans; 
}
ll solve() {
    if (n<=3) return solve1to3(); 
    // if (n<=10) return solve4to6(); 
    if (check15to20()) return solve15to20(); 
    return 0; 
}
int main() {
#ifndef DBG
    freopen("polygon.in", "r", stdin); 
    freopen("polygon.out", "w", stdout); 
#endif 
    cin>>n; 
    LP(i, n) cin>>a[i], pre[i]=pre[i-1]+a[i];
    // dp[0][0]=1; 
    // LP(i, n) dp[0][i]=0;
    // LP(i, n) dp[i][0]=1; 
    // LP(i, n) {
    //     int mx=pre[n]/2; 
    //     LP(j, i) {
            
    //     }
    // } 
    cout << solve() << '\n'; 
    return 0;  
}