#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define PII pair<int, int>
const int N = 1e5 + 2;
int n, a[N][3], f[202][102][102], t[N], res;
int judge() {
	int f = 1;
	for (int i = 1; i <= n; i++) {
		if (a[i][2] != 0) return 0;
		if (a[i][1] != 0) f = 2;
	}
	return f;
}
void sol() {
	cin >> n, res = 0;
	for (int i = 1; i <= n; i++) cin >> a[i][0] >> a[i][1] >> a[i][2];
	if (judge() == 1) {
		for (int i = 1; i <= n; i++) t[i] = a[i][0];
		sort(t + 1, t + n + 1, greater<int>());
		for (int i = 1; i <= n / 2; i++) res += t[i];
		cout << res << '\n';
		return;
	} else if (judge() == 2) {
		vector<int> d;
		for (int i = 1; i <= n; i++) d.push_back(a[i][0] - a[i][1]), res += a[i][0];
		sort(all(d));
		for (int i = 0; i < n / 2; i++) res -= d[i];
		cout << res << '\n';
		return;
	}
	for (int i = 1; i <= n; i++) 
		for (int j = 0; j <= n / 2; j++)
			for (int k = 0; k <= n / 2; k++) {
				if (k + j > i || i - j - k > n / 2) continue;
				f[i][j][k] = 0;
				if (j) f[i][j][k] = max(f[i][j][k], f[i - 1][j - 1][k] + a[i][0]);
				if (k) f[i][j][k] = max(f[i][j][k], f[i - 1][j][k - 1] + a[i][1]);
				if (k + j < i) f[i][j][k] = max(f[i][j][k], f[i - 1][j][k] + a[i][2]);
			}
	for (int i = 0; i <= n / 2; i++)
		for (int j = 0; j <= n / 2; j++)
			if (i + j <= n) res = max(res, f[n][i][j]);
	cout << res << '\n';
}
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--) sol();
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
