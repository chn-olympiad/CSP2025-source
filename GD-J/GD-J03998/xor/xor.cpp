#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10;
const int M = 1e6 + 10;
const int INF = 1e9;
int n, k, a[N], f[N], g[M];
long long s[N], t[M];
 
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	s[0] = 0;
	for (int i = 1; i <= n; i++)
		s[i] = s[i - 1] ^ a[i];
	int len = 0;
	for (int i = 1; i <= n; i++) {
		t[++len] = s[i];
		t[++len] = s[i] ^ k;
	}
	sort(t + 1, t + len + 1);
	len = unique(t + 1, t + len + 1) - t - 1;
	f[0] = 0;
	for (int i = 1; i <= len + 3; i++)
		g[i] = -INF;
	g[lower_bound(t + 1, t + len + 1, s[0]) - t] = f[0];
	for (int i = 1; i <= n; i++) {
		f[i] = f[i - 1];
		f[i] = max(f[i], g[lower_bound(t + 1, t + len + 1, s[i] ^ k) - t] + 1);
		int p = lower_bound(t + 1, t + len + 1, s[i]) - t;
		g[p] = max(g[p], f[i]);
	}
	cout << f[n];
	return 0;
}
