#include <bits/stdc++.h>
//#define int long long

const int N = 1e2 + 7;

int a[N * N];
int n, m, A;

signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n * m; i ++) scanf("%d", &a[i]);
	A = a[1];
	std::sort(a + 1, a + n * m + 1, [](const int L, const int R) { return L > R; });
	for (int i = 1, cnt = 1; i <= n; i ++)
		if (i & 1) for (int j = 1; j <= m; j ++, cnt ++) {
			if (a[cnt] == A) return printf("%d %d", i, j), 0;
		}
		else for (int j = m; j; j --, cnt ++) {
			if (a[cnt] == A) return printf("%d %d", i, j), 0;
		}
	
	return 0;
}
