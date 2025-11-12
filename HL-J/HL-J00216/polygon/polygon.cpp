#include <bits/stdc++.h>

using namespace std;

constexpr int N = 5000;
constexpr int A = 5000;
constexpr int P = 998244353;

int n, a[N + 1];
int f[N + 1][A + 1];

int my_pow(int num, int by) {
	int ret = 1, now = num;
	for (int i = 0; i <= 30; i++) {
		if (by >> i & 1)
			ret = ret * 1LL * now % P;
		now = now * 1LL * now % P;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + 1 + n);
	f[0][0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= A; j++) {
			f[i][j] = f[i - 1][j];
			if (j >= a[i])
				f[i][j] = (f[i][j] + f[i - 1][j - a[i]]) % P;
		}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= A; j++)
			f[i - 1][j] = (f[i - 1][j - 1] + f[i - 1][j]) % P;
//		cerr << i << ": " << f[i - 1][a[i]] << '\n';
		ans = ((ans + my_pow(2, i - 1)) % P + P - f[i - 1][a[i]]) % P;
	}
	cout << ans << '\n';
	return 0;
}