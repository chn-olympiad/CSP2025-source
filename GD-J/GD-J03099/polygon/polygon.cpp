#include <bits/stdc++.h>
using namespace std;
long long a[100010], b[100010], cnt;
int n;
bool check() {
	for (int i = 1; i <= n; i++) if (a[i] != 1) return false;
	return true;
}
long long c(int n, int m) {
	long long sum = 1;
	if (m > n / 2) m = n - m;
	for (int i = n, j = 1; j <= m; i--, j++) sum = sum * i / j % 998244353;
	return sum;
}
void dfs(int x) {
	if (x == n + 1) {
		long long sum = 0, ma = 0;
		for (int i = 1; i <= n; i++) if (b[i]) sum += a[i], ma = max(ma, a[i]);
		if (sum > ma * 2) cnt++;
		return ;
	}
	b[x] = 1;
	dfs(x + 1);
	b[x] = 0;
	dfs(x + 1);
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	if (check()) {
		long long sum = 0;
		for (int i = 3; i <= n; i++) sum = (sum + c(n, i)) % 998244353;
		cout << sum;
		return 0;
	}
	dfs(1);
	cout << cnt;
}
