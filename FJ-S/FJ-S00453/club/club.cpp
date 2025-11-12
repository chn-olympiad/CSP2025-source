#include<bits/stdc++.h>
using namespace std;
int t, n;
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		long long a[n][4], ans = 0, gs[4], js, d = 0, ds;
		long long jp1[n + 1], jp2[n + 1], jp3[n + 1];
		for (int i = 1; i <= 3; i++) gs[i] = 0;
		for (int i = 1; i <= n; i++) {
			int kd;
			for (int j = 1; j <= 3; j++) {
				scanf("%d", &kd);
				a[i][j] = kd;
			}
			js = 1;
			if (a[i][2] > a[i][1])js = 2;
			if (a[i][3] > a[i][js])js = 3;
			ans += a[i][js];
			int bj1 = 0;
			for (int j = 1; j <= 3; j++) {
				if (j != js) {
					if (a[i][j] > bj1) {
						bj1 = a[i][j];
					}
				}
			}
			if (js == 1) {
				gs[1]++;
				jp1[gs[1]] = a[i][1] - bj1;
				continue;
			}
			if (js == 2) {
				gs[2]++;
				jp2[gs[2]] = a[i][2] - bj1;
				continue;
			}
			if (js == 3) {
				gs[3]++;
				jp3[gs[3]] = a[i][3] - bj1;
				continue;
			}
		}
		for (int i = 1; i <= 3; i++) {
			if (gs[i] > (n / 2)) {
				d = i;
				ds = gs[i] - (n / 2);
				break;
			}
		}
		if (d == 0) {
			cout << ans << endl;
			continue;
		}
		if (d == 1) {
			sort(jp1 + 1, jp1 + gs[1] + 1);
			for (int i = 1; i <= ds; i++) ans -= jp1[i];
			cout << ans << endl;
			continue;
		}
		if (d == 2) {
			sort(jp2 + 1, jp2 + gs[2] + 1);
			for (int i = 1; i <= ds; i++) ans -= jp2[i];
			cout << ans << endl;
			continue;
		}
		if (d == 3) {
			sort(jp3 + 1, jp3 + gs[3] + 1);
			for (int i = 1; i <= ds; i++) ans -= jp3[i];
			cout << ans << endl;
			continue;
		}
	}
	return 0;
}
