#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 5005, p = 998244353;
ll n, a[maxn], V, f[maxn][maxn], ans, cnt[maxn], pw[maxn];
ll calc(ll i) {
	return (pw[i - 1] - f[i - 1][a[i]] + p) % p;
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n; pw[0] = 1;
	for (int i = 1; i <= n; i++) {
		pw[i] = pw[i - 1] * 2 % p;
		cin >> a[i];
		V = max(V, a[i]);
		cnt[a[i]]++;
	}
	for (int i = 1; i <= V; i++) {
		cnt[i] += cnt[i - 1];
	}
	sort(a + 1, a + n + 1);
	f[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= V; j++) {
			f[i][j] = f[i - 1][j];
			if (j >= a[i]) f[i][j] = (f[i][j] + f[i - 1][j - a[i]]) % p;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= V; j++) {
			f[i][j] = (f[i][j] + f[i][j - 1]) % p;
		}
	}
	for (int i = 3; i <= n; i++) {
		ans = (ans + calc(i)) % p;
	}
	cout << ans << '\n';
	return 0;
} 
