#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using db = double;
using ldb = long double;

const int N = 5e5 + 5, V = 1 << 20;
int n, k, a[N], f[N], mx[V];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	memset(mx, -63, sizeof mx);
	int x = 0;
	mx[0] = 0;
	for (int i = 1; i <= n; ++i) {
		x ^= a[i];
		f[i] = max(mx[x ^ k] + 1, f[i - 1]);
		mx[x] = max(mx[x], f[i]);
	}
	cout << f[n];
	return 0;
}
/*
4 2
2 1 0 3
4 3
2 1 0 3
4 0
2 1 0 3
*/
