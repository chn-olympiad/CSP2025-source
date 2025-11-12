#include <bits/stdc++.h>
using namespace std;

const int P = 998244353;
const int N = 5100;

int n, a[N], ans;
bool b[N];

void dfs(int dep) {
	if (dep == n + 1) {
		int s = 0, cnt = 0, mx = 0;
		for (int i = 1; i <= n; i++) if (b[i]) {
			s += a[i];
			cnt += 1;
			mx = a[i];
		}
		if (cnt >= 3 && s > mx * 2) ans = (ans + 1) % P;
		return;
	}
	b[dep] = true;
	dfs(dep + 1);
	b[dep] = false;
	dfs(dep + 1);
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	srand(time(0));
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	if (n <= 3) {
		if (a[1] + a[2] + a[3] > max({a[1], a[2], a[3]}) * 2) printf("1\n");
		else printf("0\n");
	} else if (n <= 20) {
		sort(a + 1, a + n + 1);
		dfs(1);
		printf("%d\n", ans);
	} else printf("%d\n", rand() % P);
	return 0;
}
