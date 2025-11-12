#include <bits/stdc++.h>

int n, m, a1;
int cnt1 = 0, cnt = 0;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	
	std::vector <int> a (n * m + 5, 0);
	std::vector <int> b (n * m + 5, 0);
	
	for (int i = 1; i <= n * m; i++) {
		scanf("%d", &a[i]);
	}
	a1 = a[1];
	std::sort(a.begin() + 1, a.begin() + 1 + n * m, std::greater <int> ());

	for (int i = 1; i <= m; i++) {
		if (cnt % 2 == 0) {
			for (int j = 1; j <= n; j++) {
				cnt1++;
				if (a[cnt1] == a1) {
					printf("%d %d", i, j);
					return 0;
				}
			}
		} else {
			for (int j = n; j >= 1; j--) {
				cnt1++;
				if (a[cnt1] == a1) {
					printf("%d %d", i, j);
					return 0;
				}
			}
		}
		cnt++;
	}
	return 0;
} 