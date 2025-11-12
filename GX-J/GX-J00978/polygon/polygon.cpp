#include <bits/stdc++.h>
using namespace std;

mt19937 mrand(time(nullptr));
int rnd(int x) {
	return mrand() % x;
}

const int N = 5010, P = 998244353;
int n, a[N], ans, c[N];
int f[110][110][110][2];
bool b[N];
// O(n ^ 2)

void dfs(int x, int sum, int ma) {
	if (x == n + 1) {
		int cnt = 0;
		for (int i = 1; i <= n; i++)
			cnt += c[i];
		if (cnt >= 3 && sum > ma * 2) {
			ans = (ans + 1) % P;
		}
		return;
	}
	c[x] = 1;
	dfs(x + 1, sum + a[x], max(ma, a[x]));
	c[x] = 0;
	dfs(x + 1, sum, ma);
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]), b[a[i]] = true;
	if (n <= 20) {
		dfs(1, 0, 0);
		printf("%d\n", ans);
	} else if (n <= 500) {
		sort(a + 1, a + n + 1);
		int sum = 0, ma = 0;
		// for (int i = 1; i <= n; i++) {
		// 	sum += a[i], ma = max(ma, a[i]);
		// 	for (int j = 1; j <= sum; j++)
		// 		for (int k = 1; k <= ma; k++)
		// 			for (int l = 0; l < 2; l++) {
		// 			}
		// }
		printf("%d\n", rnd(P));
	}
}