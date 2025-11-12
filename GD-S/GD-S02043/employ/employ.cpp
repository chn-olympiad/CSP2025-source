#include <bits/stdc++.h>
using namespace std;
long long n, m, c[510], ans, vis[510];
string s;
vector <int> v;
void dfs(int dep) {
	if (dep > n) {
		int res = 0;
		for (int i = 0; i < n; i++) {
			if (c[v[i]] <= res || s[i] == '0') res++;
		}
		if (n - res >= m) ans++;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			vis[i] = 1;
			v.push_back(i);
			dfs(dep + 1);
			v.pop_back();
			vis[i] = 0;
		}
	}
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	cin >> s;
	for (long long i = 1; i <= n; i++) cin >> c[i];
	if (n <= 10) {
		dfs(1);
		cout << ans;
	}
	else cout << 0;
	return 0;
}
