#include <bits/stdc++.h>
using namespace std;

long long ans;
int n, m, c[510], p[510];
bool is[510], s[510];
string ss;
void dfs(int qs, int sum, int d) {
	cout << sum << endl;
	if (d >= n) {
		for (int i = 1; i <= n; i++) {
			cout << p[i] << ends;
		}
		cout << endl;
		if (sum >= m) {
			ans = (ans + 1) % 998244353;
		}
		return ;
	}
	for (int i = 1; i <= n; i++) {
		if (is[i]) continue;
		p[d] = i;
		if (c[i] < d - 1 && c[i] < qs) {
			is[i] = true;
			dfs(qs + 1, sum, d + 1);
			is[i] = false;
			continue;
		}
		if (s[i]) {
			is[i] = true;
			dfs(qs, sum + 1, d + 1);
			is[i] = false;
		} else {
			is[i] = true;
			dfs(qs + 1, sum, d + 1);
			is[i] = false;
		}
	}
	return ;
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> ss;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		s[i] = (ss[i - 1] == '0');
	}
	dfs(0, 0, 0);
	cout << ans;
	fclose(stdin);
	fclose(stdin);
	return 0;
}
