#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 10;
ll n, k;
ll a[N];
ll f[N], g[N], s[N];
int main () {
	freopen ("xor.in", "r", stdin);
	freopen ("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; ++ i) {
		cin >> a[i];
	} 
	for (int i = 1; i <= n; ++ i) {
		s[i] = s[i - 1] ^ a[i];
	}
	memset (g, -1, sizeof g);
	g[0] = 0;
	for (int i = 1; i <= n; ++ i) {
		f[i] = max (f[i - 1], g[s[i] ^ k] + 1);
		g[s[i]] = max (g[s[i]], f[i]);
	}
	cout << f[n] << '\n';	
	return 0;
}
