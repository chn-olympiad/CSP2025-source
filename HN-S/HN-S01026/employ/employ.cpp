#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 505, M = 998244353;
int n, m, c[N], f[N], cnt, d[N];
bool st[N];
ll sum[N], ans;
string s;

bool check() {
	int t = 0, r = 0;
	for (int i = 1; i <= n; i++) {
		if (s[i - 1] == '0' || r >= c[d[i]]) {
			r++;
			continue;
		}
		t++;
	}
	return t >= m;
}

void dfs(int l) {
	if (l > n) {
		ans = (ans + check()) % M;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!st[i]) {
			d[l] = i;
			st[i] = 1;
			dfs(l + 1);
			st[i] = 0;
		}
	}
}

int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> s;
	sum[0] = 1;
	for (int i = 1; i <= 500; i++) sum[i] = (sum[i - 1] * i) % M;
	for (int i = 1; i <= n; i++) cin >> c[i];
	for (int i = 1; i <= n; i++) f[i + 1] = f[i] + (s[i - 1] == '0'), cnt += s[i - 1] == '1';
	if (cnt < m) {
		cout << 0;
		return 0;
	}
	if (m == 1) {
		ll ans1 = 0;
		cout << sum[n];
		return 0;
	}
	dfs(1);
	cout << ans;
	return 0;
}
