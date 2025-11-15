/*
162834 ok why is d easier
170622 i lied
172053 gg dp
*/

#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353
#define ll long long

ll fact(ll n) {
    ll ans = 1;
    for (ll i = 1; i <= n; i++) {
        ans *= i; ans %= MOD;
    }
    return ans;
}

ll inv(ll n) {
    ll p = MOD - 2;
    ll ans = 1;
    while (p > 0) {
        if (p & 1) {
            ans *= n; ans %= MOD;
        }
        p >>= 1;
        n *= n; n %= MOD;
    }
    return ans;
}

ll ncr(ll n, ll r) {
    return (fact(n) * inv(fact(r)) % MOD) * inv(fact(n - r)) % MOD;
}

int main() {
    
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    
    ll n, m; cin >> n >> m;
    string s; cin >> s;
    vector<ll> acc(n);
    acc[0] = (s[0] == '0');
    for (ll i = 1; i < n; i++) {
        acc[i] = acc[i - 1] + (s[i] == '0');
    }

    if (n <= 10) {
        vector<int> pat(n);
        for (int i = 0; i < n; i++) {
            cin >> pat[i];
        }

        int ans = 0;
        vector<int> d(n);
        iota(d.begin(), d.end(), 0);
        do {
            int res = 0; int quits = 0;
            for (int i = 0; i < n; i++) {
                // cout << s[i] << " " << pat[d[i]] << " " << res << " " << quits << endl;
                if (s[i] == '1' && quits < pat[d[i]]) {
                    res++;
                } else {
                    quits++;
                }
            }
            if (res >= m) {
                ans++;
            }
        } while (next_permutation(d.begin(), d.end()));

        cout << ans << endl;
    }
}