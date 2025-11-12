#include<bits/stdc++.h>
#define ll long long
#define fr first
#define sc second
#define pii pair<ll,ll>
using namespace std;
const int N = 5010, mod2 = 998244353;
int n, dp[11451][2], a[N];
ll qpow(ll x, int y){
    ll res = 1;
    while(y){
        if(y & 1) res *= x, res %= mod2;
        y >>= 1;
        x = x * x % mod2;
    }
    return res;
}
void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a+1, a+n+1);
    ll ans = 0;
    for(int i = 1; i <= n; ++i){
        ll sum = qpow(2, i-1);
        for(int j = 1; j <= a[i]; ++j) sum -= dp[j][1], sum = (sum % mod2 + mod2) % mod2;
        for(int j = a[n]; j >= 0; --j) dp[j+a[i]][1] += dp[j][0] + dp[j][1], dp[j+a[i]][1] %= mod2;
        sum -= i;
        dp[a[i]][0]++;
        ans += sum;  ans %= mod2;
    }
    cout << (ans % mod2 + mod2) % mod2 << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    solve();
    return 0;
}