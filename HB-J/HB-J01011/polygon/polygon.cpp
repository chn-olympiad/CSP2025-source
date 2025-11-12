#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
ll a[5005], f[5005];
int main() { 
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    ll n, mx = 0, p2 = 1, ans = 0; cin >> n;
    for(ll i = 1;i <= n;i++)
        cin >> a[i], mx = max(mx, a[i]);
    sort(a+1, a+n+1); f[0] = 1;
    for(ll i = 1;i <= n;i++) {
        ll sum = 0;
        for(ll j = 0;j <= a[i];j++)
            sum = (sum + f[j]) % mod;
        ll now = (p2 - sum + mod) % mod;
        ans = (ans + now) % mod; 
        p2 = (p2 * 2) % mod;
        for(ll j = mx;j >= a[i];j--)
            f[j] = (f[j] + f[j-a[i]]) % mod;
    } cout << ans << endl; 
    return 0;
}
//9: 08 AK le