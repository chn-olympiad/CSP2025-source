// GZ-S00419 华东师范大学附属贵阳学校 贺舜 
#include <bits/stdc++.h>

using namespace std;

int t, a[100001][4], l[100001];

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		int n;
		scanf("%d", &n);
		for (int j = 1; j <= n; j++) {
			scanf("%d%d%d", &a[j][1], &a[j][2], &a[j][3]);
			l[j] = a[j][1];
		}
		if (n == 2) {
			int ans = 0;
			for (int j = 1; j <= 2; j++) {
				for (int k = j + 1; k <= 3; k++) {
					ans = max(ans, max(a[1][j] + a[2][k], a[1][k] + a[2][j]));
				}
			}
			printf("%d", ans);
		}else {
			sort(l + 1, l + n + 1);
			int ans = 0;
			for (int j = n; j > n / 2; j--) {
				ans += l[j];
			}
			printf("%d\n", ans);
		}
	}
	
	return 0;
}
