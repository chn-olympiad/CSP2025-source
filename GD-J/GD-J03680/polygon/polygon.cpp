#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define out() cout << "sb\n";

const int N = 10005, mod = 998244353;

int n, a[N], up;
ll p[N], f[N << 1], g[N << 1], ans[N], res; //´æ´¢ 

ll mo(ll x) {
	return x < mod ? x : x - mod;
}

ll qpow(ll x, ll y) {
	ll ans = 1;
	for (; y; y >>= 1) {
		if (y & 1) ans = ans * x % mod;
		x = x * x % mod;
	}
	return ans;
}

int main() {
//	system("fc polygon.out polygon.ans");
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	IOS;
	cin >> n;
	p[0] = 1;
	for (int i = 1; i <= n; i++) p[i] = (p[i - 1] << 1) % mod;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	up = a[n] << 1;
	for (int i = 2; i <= n; i++) {
		ll sum = 0;
		for (int j = 1; j <= a[i]; j++) 
			if (f[j]) sum = mo(sum + f[j]);
		ans[i] = (p[i - 1] - i + mod) % mod;
//		cout << ans[i] << ' ';
		ans[i] = (ans[i] - sum + mod) % mod;
		res = mo(res + ans[i]);
//		cout << sum << ' ' << ans[i] << "\n"; 
//		for (int j = 1; j <= up; j++) cout << f[j] << " \n"[j == up];
		for (int j = 1; j <= up - a[i]; j++) g[j] = f[j];
		for (int j = 1; j <= up - a[i]; j++) {	
			g[j + a[i]] = mo(g[j + a[i]] + f[j]);
		}
		for (int j = 1; j <= up - a[i]; j++) f[j] = g[j];
//		for (int j = 1; j <= up; j++) cout << f[j] << " \n"[j == up];
		for (int j = 1; j < i; j++) f[a[j] + a[i]] = mo(f[a[j] + a[i]] + 1); 
//		for (int j = 1; j <= up; j++) cout << f[j] << " \n"[j == up];
	} 
	cout << res << "\n";
	return 0;
}

