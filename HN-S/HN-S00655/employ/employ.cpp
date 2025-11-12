#include <bits/stdc++.h>

using namespace std;

const int N = 510;
const int MOD = 998244353;

int c[N], a[N];
int f[N], pz[N];

int main () {
	freopen ("employ.in", "r", stdin);
	freopen ("employ.out", "w", stdout);
	
	int n, m;
	cin >> n >> m;
		
	string s;
	cin >> s;
	
	for (int i = 1; i <= n; i++) cin >> c[i];
	
	s += ' ';
	
	for (int i = 1; i <= n; i++) a[i] = (int)(s[i] - '0');
	
	for (int i = 1; i <= n; i++) pz[i] = pz[i - 1] + a[i];
	
	for (int i = 1; i <= n; i++) {
		for (int j = n; j >= 1; j--) {
			f[j] = max (f[i - 1], (a[j] + c[i] * a[i]) - pz[i] + m) % MOD;
		}
	}
	
	cout << f[n] - 1;
	
	return 0;
}
