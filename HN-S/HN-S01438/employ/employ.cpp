#include <bits/stdc++.h>
#define int long long

using namespace std;

const int kMaxN = 203, mod = 998244353;

int n, m;

int a[kMaxN], c[kMaxN];

string s;

int o[kMaxN];

bool vis[kMaxN];

int ans = 0;

bool C() {
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		if (sum >= c[o[i]]) ++sum;
		else if (a[i] == 0) ++sum;
	} 
	return n - sum >= m;
}
void dfs (int u) {
	if (u == n + 1) {
		if (C()) ++ans;
		return ;
	}
	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		vis[i] = true;
		o[u] = i;
		dfs (u + 1);
		o[u] = 0;
		vis[i] = false;
	}
}
signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> m >> s;
	s = ' ' + s;
	for (int i = 1; i <= n; i++) {
		a[i] = s[i] - '0';
	}
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	dfs (1);
	cout << ans << "\n";
	return 0;
}
