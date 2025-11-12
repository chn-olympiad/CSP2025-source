#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M = 998244353;
ll n, s, a[100001], dp[501][50001], ans;
ll p(ll k){
    if(k == 1) return 2;
    ll tmp = p(k / 2);
    return tmp * tmp % M * (k % 2 ? 2 : 1) % M;
}
void dfs(ll k, ll mx, ll sum){
    if(k == n + 1){
        if(sum > mx * 2){
            ans++;
            ans %= M;
        }
    }else{
        dfs(k + 1, mx, sum);
        dfs(k + 1, a[k], sum + a[k]);
    }
}
int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    scanf("%lld", &n);
    ll fl = 1;
    for(int i = 1; i <= n; i++){
        scanf("%lld", &a[i]);
        if(a[i] != 1) fl = 0;
    }
    if(fl){
        printf("%lld", (((p(n) + M - n * (n - 1) / 2 % M) % M + M - n) % M + M - 1) % M);
        return 0;
    }else if(n <= 20){
        sort(a + 1, a + n + 1);
        dfs(1, 0, 0);
        printf("%lld", ans % M);
    }else{
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= s; j++){
                dp[i][j] = dp[i - 1][j];
            }
            for(int j = a[i] + 1; j <= a[i] + s; j++){
                dp[i][j] += dp[i - 1][j - a[i]];
            }
            dp[i][a[i]]++;
            s += a[i];
            for(int j = i * 2 + 1; j <= s; j++){
                ans += dp[i][j];
            }
        }
        printf("%lld", ans);
    }
    return 0;
}
