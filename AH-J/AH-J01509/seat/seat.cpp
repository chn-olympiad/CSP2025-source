#include<bits/stdc++.h>
using namespace std;

int n, m, a[110];

int main () {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n * m; i++) {
		scanf("%d", &a[i]);
	}
	int t = a[1];
	sort(a + 1, a + n * m + 1);
	for (int i = n * m; i >= 1; i--) {
		if (a[i] == t) {
			int k = 0;
			if (i % n == 0)
				k = i / n;
			else {
				k = i / n + 1;
			}
			if (k % 2 == 1)
				printf("%d %d", k, i % n + 1);
			else {
				printf("%d %d", k, m - i % n + 1);
			}
			return 0;
		}
	}
	return 0;
}
