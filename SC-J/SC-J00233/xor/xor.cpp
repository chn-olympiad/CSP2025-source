#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 500009, M = 1048579;
int n, k, a[N], b[N], c[M], f[N], lst, ans;
signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	memset(c, -1, sizeof c);
	c[0] = 0;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[i] = b[i - 1] ^ a[i];
		f[i] = c[b[i] ^ k] + 1;
		c[b[i]] = i;
	}
	for (int i = 1; i <= n; i++) if (f[i] > lst) ans++, lst = i;
	cout << ans;
}