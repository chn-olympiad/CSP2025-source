#include <bits/stdc++.h>
using namespace std;
const int MAX = 5005, MOD = 998244353;
int a[MAX], n;
long long ans = 0;
bool flag = 0;
void dfs(long long &ans, const int x, int i, int cnt, int sum) {
	if (i == n + 1) {
		if (cnt >= 3 && sum > x) {
			if (flag) {
				ans++;
			}
			flag = !flag;
		}
		return;
	}
	dfs(ans, x, i + 1, cnt + 1, sum + a[i + 1]);
	dfs(ans, x, i + 1, cnt, sum);
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
	}
	sort(a + 1, a + 1 + n, greater<int>());
	for (int i = 1; i <= n; i++) {
		dfs(ans, a[i], i, 1, 0);
	}
	printf("%lld", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
