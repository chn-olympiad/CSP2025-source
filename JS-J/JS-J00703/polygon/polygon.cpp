#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int N = 5009;
constexpr int INF = 1e9;
constexpr ll mod = 998244353;
constexpr ll inv2 = 499122177;
int a[N];
int n, ans, mx = 0;

namespace sub1{
    void solve(){
        for(int i = 1; i < (1 << n); i++){
            int mx = -INF, s = 0;
            for(int j = 1; j <= n; j++) if(i & (1 << (j - 1))){
                mx = max(mx, a[j]);
                s += a[j];
            }
            if(s > 2 * mx) ans++;
        }
        cout << ans << '\n';
    }
}

namespace sub2{
    ll fp(ll a, int n){
        ll res = 1ll;
        while(n){
            if(n & 1) res = res * a % mod;
            a = a * a % mod;
            n >>= 1;
        }
        return res;
    }

    void solve(){
        ll a = (fp(2ll, n) - 1ll + mod) % mod;
        a = (a - n + mod) % mod;
        ll b = 1ll * n * (n - 1) % mod * inv2 % mod;
        ll ans = (a - b + mod) % mod;
        cout << ans << '\n';
    }
}

int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        mx = max(mx, a[i]);
    }

    if(n <= 20){
        sub1::solve();
        return 0;
    }
    if(mx == 1){
        sub2::solve();
        return 0;
    }
    return 0;
}
/*
5
1 2 3 4 5

5
2 2 3 8 10


*/