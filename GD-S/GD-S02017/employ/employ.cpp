#include<bits/stdc++.h>
using namespace std;
const int N = 505;
int mod = 998244353;
int n, m;
string s;
int c[N];
bool usd[N];
long long ans = 0;
void dfs (int day, int peo) {
	if (day == n + 1) {
		if (peo >= m) {
			ans ++;
			ans %=mod;
		}
		return;
	}
	for (int i = 1; i <= n; i ++) {
		if (usd[i]) continue;
		int tag = 0;
		if (s[i-1] == '1' && day - peo - 1 < c[i]) tag = 1;
		usd[i] = 1;
		dfs (day + 1, peo + tag);
		usd[i] = 0;
	}
}
int main() {
	freopen ("employ.in", "r", stdin);
	freopen ("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> s;
	for (int i = 1; i <= n; i ++) {
		cin >> c[i];
	}
	dfs (1, 0);
	cout << ans << "\n";
	return 0;
}

