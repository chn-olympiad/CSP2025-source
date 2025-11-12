#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N =5005;
const ll mod = 998244353;
int a[N], n;
ll dp[N][N];
int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);
    int m = a[n-1];
    for (int s = 0; s <= m; s++){
        if (a[0] > s) dp[0][s] = 1;
        else          dp[0][s] = 0;
        for (int i = 1; i < n; i++){
            // if (s <= a[i+1])
            {if (a[i] > s)
                dp[i][s] = dp[i-1][s] + dp[i-1][0] + 1;
            else
                dp[i][s] = dp[i-1][s-a[i]] + dp[i-1][s]; 
            dp[i][s] %= mod;}
        }
    }
    ll ans = 0;
    for (int i = 1; i < n; i++){
        ans += dp[i-1][a[i]];
        ans %= mod;
    }
    cout << ans << '\n';
    return 0;
}