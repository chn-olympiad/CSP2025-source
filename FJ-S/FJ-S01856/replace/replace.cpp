#include <bits/stdc++.h>
#define ll long long
#define inf 2147483647 //9223372036854775807
#define mod 1000000007
using namespace std;
/*
inline ll rd() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') { if(ch == '-') f = -1; ch = getchar(); }
	while(ch >= '0' && ch <= '9') x = x * 10 + ch - 48, ch = getchar();
	return x * f;
}
*/

ll pw[5000006], inv[5000006], p[200005], q[200005];
ll f[200005], g[200005], L[200005], R[200005];

ll Pow(ll x, ll y) {
	ll res = 1;
	for(; y; y >>= 1, x = x * x % mod) if(y & 1) res = res * x % mod;
	return res;
}
ll fd(ll k, ll l, ll r) {
	if(l == 0) return k ? f[r] : g[r];
	if(k) return (f[r] - f[l - 1] + mod) * inv[l] % mod;
	return (g[r] - g[l - 1] + mod) * inv[l] % mod;
}
signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll n, Q; cin >> n >> Q;
	pw[0] = inv[0] = 1;
	for(ll i = 1; i <= 5000000; i++) pw[i] = pw[i - 1] * 29 % mod;
	inv[5000000] = Pow(pw[5000000], mod - 2);
	for(ll i = 4999999; i; i--) inv[i] = inv[i + 1] * 29 % mod;
	for(ll i = 1; i <= n; i++) {
		string s, t; cin >> s >> t;
		ll len = s.size(), l = 0, r = len - 1;
		while(s[l] == t[l]) l++;
		while(s[r] == t[r]) r--;
		L[i] = -l, R[i] = len - r - 1;
		for(ll j = 0; j < len; j++) {
			p[i] = (p[i] + pw[j] * (s[j] - 96) % mod) % mod;
			q[i] = (q[i] + pw[j] * (t[j] - 96) % mod) % mod;
		}
	}
	while(Q--) {
		string s, t; cin >> s >> t;
		ll len = s.size(), l = 0, r = len - 1;
		while(s[l] == t[l]) l++;
		while(s[r] == t[r]) r--;
		for(ll i = 0; i < len; i++) {
			f[i] = pw[i] * (s[i] - 96) % mod;
			g[i] = pw[i] * (t[i] - 96) % mod;
			if(i > 0) {
				f[i] = (f[i] + f[i - 1]) % mod;
				g[i] = (g[i] + g[i - 1]) % mod;
			}
		}
		ll ft = fd(1, l, r), gt = fd(0, l, r), ans = 0;
		for(ll i = 1; i <= n; i++) {
			ll tl = l + L[i], tr = r + R[i];
			if(tl < 0 || tr >= len) continue;
			if(fd(1, tl, tr) == p[i] && fd(0, tl, tr) == q[i]) ans++; 
		}
		cout << ans << '\n';
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/

