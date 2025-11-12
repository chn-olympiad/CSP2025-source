#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <set>
#include <map>
using namespace std;

#define mod 998244353
#define MAX_N 500
int n, m, a[MAX_N + 5], ans, tmp[MAX_N + 5], nxt[MAX_N + 5], sum;
char c[MAX_N + 5];
struct Lian {
	int lst, nxt;
} lian[MAX_N + 5];

void dfs(int u) {
	if (u > n) {
		if (sum >= m) {
			ans++;
			ans %= mod;
		}
//		printf("\n");
		return;
	}
	for (int i = lian[0].nxt; i != 0; i = lian[i].nxt) {
//		printf("%d ", i);
		lian[lian[i].lst].nxt = lian[i].nxt;
		lian[lian[i].nxt].lst = lian[i].lst;
		if (a[i] >= tmp[u] && c[u] == '1') {
			sum++;
			dfs(u + 1);
			sum--;
		} else dfs(u + 1);
		lian[lian[i].lst].nxt = i;
		lian[lian[i].nxt].lst = i;
	}
	return;
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		c[i] = '0' - 1;
		while (c[i] < '0' || c[i] > '9') c[i] = getchar();
	}
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) {
		lian[i].lst = i - 1;
		lian[i].nxt = i + 1;
	}
	lian[n].nxt = 0;
	lian[0].lst = n;
	lian[0].nxt = 1;
	tmp[0] = 1;
	for (int i = 1; i <= n; i++) {
		tmp[i] = tmp[i - 1];
		if (c[i] == '0') tmp[i]++;
	}
	dfs(1);
	printf("%d", ans);
	return 0;
}

