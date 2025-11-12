#include <bits/stdc++.h>
using namespace std;
const int N = 1 << 22;
long long hsh[N], n, k, a, ans, f[N], b;
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin.tie(nullptr) -> sync_with_stdio(false);
	cin >> n >> k;
	memset(hsh, 0x3f, sizeof hsh);
	hsh[0] = 0;
	for (int i = 1; i <= n; i ++) {
		cin >> a, b ^= a;
		if (hsh[b ^ k] < i)
			f[i] = f[hsh[b ^ k]] + 1;
		f[i] = max(f[i], f[i - 1]);
		hsh[b] = i;
	}
	cout << f[n];
	return 0;
}
