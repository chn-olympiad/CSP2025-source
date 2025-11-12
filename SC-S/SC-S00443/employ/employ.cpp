#include <bits/stdc++.h>
using namespace std;
const int maxn = 510, mod = 998244353;
char dif[maxn];
int st[maxn], p[maxn], n, m;
long long ans;
bool vis[maxn];
bool solve() {
	int g = 0, lv = 0;
	for (int i = 1; i <= n; i++) {
		while (i <= n && lv >= st[p[i]]) lv++, i++;
		if (i > n) break;
		if (dif[i] == '1') g++;
		else lv++;
	}
	return g >= m;
}
void dfs(int x) {
	if (x > n) {
		if (solve()) ans ++;
		return;
	}
	for (int i = 1; i <= n; i++) if (!vis[i]) {
		vis[i] = 1, p[x] = i;
		dfs(x + 1);
		vis[i] = 0;
	}	
	return;
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf(" %c", dif + i);
	for (int i = 1; i <= n; i++) scanf("%d", st + i);
	if (n <= 18) dfs(1);
	printf("%lld\n", ans);
	return 0;
}//这才是我考不过别人的原因吧 