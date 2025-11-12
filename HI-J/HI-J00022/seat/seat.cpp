#include <bits/stdc++.h>
using namespace std;

int n, m, a[5050];

bool cmp(const int &x, const int &y) {
	return x > y;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	scanf ("%d%d", &n, &m);
	for (int i = 1; i <= n * m; i++) {
		scanf ("%d", &a[i]);
	}
	int x = a[1];
	sort(a + 1, a + (n * m) + 1, cmp);
	
	for (int i = 1; i <= m; i++) {
		if (i % 2 == 1) {
			for (int j = 1; j <= n; j++) {
				if (x == a[(i - 1) * m + j]) {
					printf ("%d %d\n", i, j);
					return 0;
				}
			}
		} else {
			for (int j = 1, j1 = n; j <= n, j1 >= 1; j++, j1--) {
				if (x == a[(i - 1) * n + j]) {
					printf ("%d %d\n", i, j1);
					return 0;
				}
			}
		}
		
	}
	return 0;
}
