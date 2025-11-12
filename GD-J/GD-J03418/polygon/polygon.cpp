#include<bits/stdc++.h>
using namespace std;

const int P = 998244353;
int n, a[5010], ans, sum, s, x;

void dfs(int i, int sum, int s) {
	if (i == n + 1) {
		if (sum > a[s] * 2 && x >= 3)
			ans++, ans % P;
		return;
	}
	int t = s;
	x++, s = i;
	dfs(i + 1, sum + a[i], s);
	x--, s = t;
	dfs(i + 1, sum, s);
}

int main() {
	//freopen("polygon.in", "r", stdin);
	//freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	dfs(1, 0, 0);
	printf("%d\n", ans);
	return 0;
}
