#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 10;
int t, n, ans = 0;
struct node {
	int a, b, c;
} a[N];
bool cmp1(node x, node y) {
	return x.a > y.a;
}
bool cmp2(node x, node y) {
	return x.a - x.b > y.a - y.b;
}
void dfs(int x, int y, int z, int p, int sum) {
	if (x > n / 2 || y > n / 2 || z > n / 2) return;
	if (p > n) {
		ans = max(ans, sum);
		return;
	}
	dfs(x + 1, y, z, p + 1, sum + a[p].a);
	dfs(x, y + 1, z, p + 1, sum + a[p].b);
	dfs(x, y, z + 1, p + 1, sum + a[p].c);
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while (t--) {
		bool t1 = 0, t2 = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d%d%d", &a[i].a, &a[i].b, &a[i].c);
			if (a[i].b) t1 = 1;
			if (a[i].c) t1 = t2 = 1;
		}
		ans = 0;
		if (!t1) {
			sort(a + 1, a + n + 1, cmp1);
			for (int i = 1; i <= n / 2; i++) {
				ans += a[i].a;
			}
			printf("%d\n", ans);
			continue;
		}
		if (!t2) {
			sort(a + 1, a + n + 1, cmp2);
			for (int i = 1; i <= n / 2; i++) {
				ans += a[i].a;
			}
			for (int i = n / 2 + 1; i <= n; i++) {
				ans += a[i].b;
			}
			printf("%d\n", ans);
			continue;
		}
		dfs(0, 0, 0, 1, 0);
		printf("%d\n", ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
