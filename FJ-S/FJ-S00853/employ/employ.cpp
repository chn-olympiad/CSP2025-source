#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 505;
const int mod = 998244353;

int n, m, c[N], vis[N], ans = 0;
char s[N];

void DFS(int now, int lu, int cnt) {
	if (now > n) {
		if (lu >= m) ans ++;
		return;
	}
	
	for (int i = 1; i <= n; i ++) {
		if (vis[i])
			continue;
			
		bool b = 1;
		if (cnt >= c[i] || s[now] == '0') b = 0;
		
		vis[i] = 1;
		DFS(now + 1, lu + (b == 1), cnt + (b == 0));
		vis[i] = 0;
	}
}

void subtask15() {
	bool flg = 1;
	for (int i = 1; i <= n; i ++)
		if (c[i] == 0 || s[i] == '0')
			flg = 0;
			
	if (!flg)
		printf("%lld\n", 0ll);
	else {
		int ans = 1;
		for (int i = 1; i <= n; i ++)
			ans = ans * i % mod;
		printf("%lld\n", ans);
	}
}

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	scanf("%lld%lld", &n, &m);
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i ++)
		scanf("%lld", &c[i]);
		
	if (n == m) {
		subtask15();
		return 0;
	}
	
	DFS(1, 0, 0);
	
	printf("%lld\n", ans);

	return 0;
}
