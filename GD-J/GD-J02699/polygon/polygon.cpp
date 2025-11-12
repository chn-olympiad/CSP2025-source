#include <bits/stdc++.h>

using namespace std;

const int N = 5e3 + 10;
const int P = 998244353;

int n, a[N], f[N], g[N], pw[N];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	pw[0] = 1;
	int A = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		pw[i] = pw[i - 1] * 2LL % P;
		A = max(A, a[i]);
	}
	sort(a + 1, a + n + 1);
	int ans = 0;
	f[0] = 1;
	for (int i = 1; i <= n; i++) {
		if (i >= 3) {
			int now = ((pw[i-1]-1 - g[a[i]]) % P + P) % P;
			ans = (ans + now) % P;
		}
		for (int j = A; j >= a[i]; j--) {
			f[j] = (f[j] + f[j-a[i]]) % P;
		}
		for (int j = a[i]; j <= A; j++) {
			g[j] = (g[j-1] + f[j]) % P;
		}
	}
	cout << ans << "\n";
	return 0;
} 
