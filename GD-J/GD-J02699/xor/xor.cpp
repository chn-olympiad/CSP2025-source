#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10;
const int V = (1 << 20) + 10;

int n, k, x, y, buc[V], f[N], g[N];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> k;
	memset(buc, -1, sizeof(buc));
	buc[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> y;
		y ^= x;
		int j = buc[k ^ y];
		if (~j) f[i] = g[j] + 1;
		buc[x = y] = i, g[i] = max(g[i - 1], f[i]);
	}
	cout << g[n] << "\n";
	return 0;
} 
