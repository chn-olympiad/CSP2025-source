#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5, V = (1 << 21) + 5;
int n, k, a[N], f[N], lst[V], g[N];
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i]; a[i] ^= a[i - 1];
	}
	for (int i = 1; i < V; i++) lst[i] = -1;
	for (int i = 1; i <= n; i++) {
		if(lst[a[i] ^ k] != -1) f[i] = g[lst[a[i] ^ k]] + 1;
		lst[a[i]] = i, g[i] = max(g[i - 1], f[i]);
	} cout << g[n];
	return 0;
}
