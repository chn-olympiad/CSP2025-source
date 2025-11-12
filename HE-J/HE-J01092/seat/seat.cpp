#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[200];
int ans[15][15];

bool cmp(const int &a, const int &b) {
	return a > b;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n * m; i++)
		scanf("%d", &a[i]);
	int t = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	int l = 0;
	for (int j = 1; j <= m; j++) {
		if (j % 2 == 1) {
			for (int i = 1; i <= n; i++) {
				ans[i][j] = a[++l];
			}
		} else {
			for (int i = n; i >= 1; i--) {
				ans[i][j] = a[++l];
			}
		}
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			if (ans[i][j] == t) {
				printf("%d %d\n", j, i);
				return 0;
			}
		}
	return 0;
}
