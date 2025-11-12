#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
int n, a[5005], ans, dp[10005], sm, mul;
signed main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    dp[0] = 1;
    for (int i = 2; i <= n; i++){
        for (int j = 10000; j >= a[i - 1]; j--) dp[j] += dp[j - a[i - 1]], dp[j] %= mod;
        sm = 0, mul = 1;
        for (int j = 0; j <= a[i]; j++) sm += dp[j], sm %= mod;
        for (int j = 1; j <= i - 1; j++) mul *= 2, mul %= mod;
        ans += (mul + mod - sm) % mod, ans %= mod;
    }
    cout << ans;
    return 0;
}
/*

bu shi zhe chang zen me zhe me jian dan???

/bx

gan jue yi deng xian dei shang 300

//freopen("polygon.in", "r", stdin);
//freopen("polygon.out", "w", stdout);

*/
