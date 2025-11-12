#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10, MOD = 998244353;

int n, m, c[N];
char s[N];

int Tot, p[N], b[N];

bool judge0() { // is all 0
	for (int i = 1; i <= n; i++) {
		if (s[i] == '1') return false;
	}
	return true;
}

bool judge1() { // is all 1
	for (int i = 1; i <= n; i++) {
		if (s[i] == '0') return false;
	}
	return true;
}

void dfs(int dep, int cnt) {
	if (cnt > n - m) {
		return;
	}
	
	if (dep > n) {
		Tot++;
		return;
	}
	
	for (int i = 1; i <= n; i++) {
		if (b[i] == 0) {
			p[dep] = i;
			b[i] = 1;
			if (s[dep] == '0') {
				dfs(dep + 1, cnt + 1);
			}
			else if (cnt >= c[i]) {
				dfs(dep + 1, cnt + 1);
			}
			else {
				dfs(dep + 1, cnt);
			}
			b[i] = p[dep] = 0;
		}
	}
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	scanf("%d %d", &n, &m);
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &c[i]);
	}
	
	if (judge0()) {
		printf("0");
	}
	else if(judge1()) {
		int ans = 1;
		for (int i = n; i >= 1; i--) {
			ans = 1LL * ans * i % MOD;
		}
		printf("%d", ans);
	}
	else {
		dfs(1, 0);
		printf("%d", Tot);
	}
	return 0;
}
