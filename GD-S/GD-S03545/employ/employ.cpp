#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const int N = 500;
const int MOD = 998244353;

int n, m, c[N], p[N];
bool vis[N];
ll ans = 0;
string s;

void dfs (int now) {
	if (now > n) {
		int cnt = 0, pre = 0;
		for (int i = 1;i <= n;i++) {
			if (s[i] == '0') pre++;
			else {
				if (pre < c[p[i]]) cnt++;
				else pre++;
			}
		}
		if (cnt >= m) ans = (ans + 1) % MOD;
		return;
	}
	for (int i = 1;i <= n;i++) {
		if (vis[i]) continue;
		p[now] = i;
		vis[i] = true;
		dfs(now+1);
		vis[i] = false;
	}
}

void solve () {
	scanf("%d%d", &n, &m);
	cin >> s;
	s = " "+s;
	bool flag = false, check = false;
	for (int i = 1;i <= n;i++) {
		scanf("%d", c+i);
		if (!c[i]) check = true;
	}
	for (int i = 1;i <= n;i++) 
		if (s[i] == '0') flag = true;
	if (m == n) {
		if (flag || check) {
			printf("0\n");
			return;
		}
	}
	if (!flag) {
		ans = 1;
		for (int i = 1;i <= n;i++) ans = (ans * i) % MOD;
		printf("%lld\n", ans);
	} else if (n <= 10) {
		dfs(1);
		printf("%lld\n", ans);
	} 
}

int main () {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int _ = 1;
	while(_--) solve();
	return 0;
}

