#include <bits/stdc++.h>

using namespace std;
int a[110];
bool cmp(int a, int b) { return a > b; }
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n * m; i++) scanf("%d", &a[i]);
	int x = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[(i-1)*m+j] == x) printf("%d %d", i, (i & 1 ? j : m - j + 1));
		}
	}
	return 0;
}

