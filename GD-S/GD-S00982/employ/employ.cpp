#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
#define N 505
int n, m, i, j, k, a[N], b[N], ans;
char w[N];
void dfs(int k, int c) {
	int i;
	if (k > n) {
		if (c <= n-m) ans++;
	}
	else {
		for (i=1; i<=n; i++) {
			if (b[i]) continue;
			b[i] = 1;
			dfs(k+1, c+(c >= a[i] || w[k] == '0'));
			b[i] = 0;
		}
	}
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d%s", &n, &m, w+1);
	for(i=1; i<=n; i++) scanf("%d", &a[i]);
	dfs(1, 0);
	printf("%d\n", ans);
	return 0;
}

