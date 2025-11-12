#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;

int n, a[5010], b[5010];
long long ans, mi[5010];

long long qmi(int x) {
	if (x > 5010) if (mi[x]) return mi[x];
	int o = 998244351;
	long long sum = 1, s = x;
	while (o) {
		if (o & 1) sum = (s * sum) % mod;
		s = (s * s) % mod;
		o >>= 1;
	}
	mi[x] = sum;
	return sum;
}

void dfs(int s, int j, int m) {
	if (j == n) {
		if (m > 2) {
			int sum = 0, maxai = 0;
			for (int i = 0; i < n; i++) {
				if (b[i]) sum += a[i], maxai = a[i];
			}
			if (sum > maxai * 2) ans += 1;
		}
		return;
	}
	b[j] = 1;
	dfs(s + a[j], j + 1, m + 1);
	b[j] = 0;
	dfs(s, j + 1, m);
}

long long c(int x, int b) {
	int a = min(b - x, x);
	long long sum = 1;
	for (int i = 1; i <= a; i++) {
		sum = ((b - i + 1) * sum) % mod;
		sum = (qmi(i) * sum) % mod;
	}
	return sum;
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	if (n > 50) {
		for (int i = 3; i <= n; i++) {
			ans = (c(i, n) + ans) % mod;
		}
		cout << ans << endl;
		return 0;
	}
	sort(a, a + n);
	dfs(0, 0, 0);
	cout << ans << endl;
	
	return 0;
}
