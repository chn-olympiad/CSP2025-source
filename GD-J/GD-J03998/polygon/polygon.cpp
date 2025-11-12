#include <bits/stdc++.h>

using namespace std;

const int N = 5e3 + 10;
const int P = 998244353;
int n, a[N], b[N], ans;
long long fct[N], inv[N];

bool check(int x) {
	int tot = 0, mx = 0;
	for (int i = 1; i <= x; i++) {
		tot += b[i];
		mx = max(mx, b[i]);
	}
	return tot > mx * 2;
}

void dfs(int x, int y) {
	if (x > n) {
		if (y >= 3 && check(y))
			ans++;
		return;
	}
	dfs(x + 1, y);
	b[y + 1] = a[x];
	dfs(x + 1, y + 1);
}

long long calc(long long x, long long y) {
	long long res = 1;
	while (y) {
		if (y % 2 == 1)
			res = res * x % P;
		x = x * x % P;
		y >>= 1;
	}
	return res;
} 

long long solve(int x, int y) {
	return fct[x] % P * inv[x - y] % P;
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		if (a[i] == 1)
			cnt++;
	if (n <= 20) {
		dfs(1, 0);
		cout << ans;
	} else if (cnt == n) {
		fct[0] = 1;
		for (int i = 1; i <= n; i++)
			fct[i] = fct[i - 1] * i % P;
		inv[n] = calc(fct[n], P - 2) % P;
		for (int i = n - 1; i >= 1; i--)
			inv[i] = inv[i + 1] * (i + 1) % P;
		inv[0] = 1;
		long long ans = 0;
		for (int i = 3; i <= n; i++)
			ans = (ans + solve(n, i) % P) % P;
		cout << ans;
	}
	return 0;
}
