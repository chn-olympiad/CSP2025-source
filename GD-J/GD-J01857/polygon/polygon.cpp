#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

constexpr int mod = 998244353, V = 10000;
int add(int x, int y) {
	return (x + y) % mod;
}

int sub(int x, int y) {
	return (x - y + mod) % mod;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);

	int n;
	cin >> n;
	
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	
	
	int ans = 0;
	for (int S = 0; S < (1 << n); S++) {
		int T = 0, A = 0;
		for (int i = 0; i < n; i++) {
			if (S >> i & 1) T += a[i], A = max(A, a[i]);
		}
		ans += (T > 2 * A);
	}
	cout << ans;

	return 0;
}
