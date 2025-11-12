#include <bits/stdc++.h>
using namespace std;

const int N = 510, P = 998244353;
int n, m, c[N], ans, p[N];
char s[N];
bool ok = true, b[N];

void dfs(int x) {
	if (x == n + 1) {
		int sum = 0, cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (!s[i] || p[c[i]] < sum) {
				++sum;
			} else ++cnt;
		}
		if (cnt >= m) ans = (ans + 1) % P;
	}
	for (int i = 1; i <= n; i++) if (!b[i]) {
		b[i] = true;
		p[x] = i;
		dfs(x + 1);
		b[i] = false;
	}
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);

	scanf("%d%d", &n, &m);
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &c[i]);
		if (s[i] != '1') ok = false;
	}
	dfs(1);
	printf("%d\n", ans);
}