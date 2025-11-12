#include <bits/stdc++.h>
using namespace std;
int a[100005][2], b[100005][2], c[100005][2], d[100005][3];
int cnt[5];
int vis[100005][3];
bool cmp(int x, int y) {
	return x > y;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin >> T;
	for (int wb = 1; wb <= T; wb++) {
		int n;
		cin >> n;
		for (int i = 1; i <= n ; i++) {
			cin >> a[i][0] >> b[i][0] >> c[i][0];
			d[i][0] = a[i][0];
			d[i][1] = b[i][0];
			d[i][2] = c[i][0];
		}
		sort(a + 1,a + n + 1, cmp);
		sort(b + 1,b + n + 1, cmp);
		sort(c + 1,c + n + 1, cmp);
		if (n > 200 && b[n][0] = 0 && c[n][0] = 0) {
			for (int i = n ; i >= 1; i--) {
				cnt += a[i][0];
			}
		} else {
			for (int i = 0 ; i < 3; i++) {
				for (int j = 1; i <= n; j++) {
					if (i == 0) {
						if (d[j][0] == a[i][0]) {
							a[i][1] = j;
						}
					} else if (i == 1) {
						if (d[j][1] == b[i][0]) {
							b[i][1] = j;
						}
					} else {
						if (d[j][2] == c[i][0]) {
							c[i][1] = j;
						}
					}
				}
			}
			int ma, ji_a = n,ji_b = n,ji_c = n;
			int m1 = n,m2 = n,m3 = n;
			int gun_a = 0;
			int gun_b = 0;
			int gun_c = 0;
			for (int i = n; i >= 1; i--) {
				if (vis[m1][0] == 1) {
					m1--;
				} else if (vis[m2][1] == 1) {
					m2--;
				} else if (vis[m3][2] == 1) {
					m3--;
				}
				if (ji_a <= n / 2) {
					ma = max(b[m2][0],c[m3][0]);
				} else if (ji_b <= n / 2) {
					ma = max(a[m1][0],c[m3][0]);
				} else if (ji_c <= n / 2) {
					ma = max(a[m1][0],b[m2][0]);
				} else {
					ma = max(max(a[m1][0],b[m2][0]),c[m3][0]);
				}
				if (a[m1][0] == ma) {
					m1--;
					ji_a--;
					for (int j = 1; j <= n; j ++) {
						if (a[m1][1] == b[i][1]) {
							vis[i][1] = 1;
							int gun_b = 1;
						}
						if (a[m1][1] == c[i][1]) {
							vis[i][2] = 1;
							int gun_c = 1;
						}
						if (gun_b == 1&& gun_c == 1) {
							gun_b = 0, gun_c = 0;
							break;
						}
					}
				} else if (b[m2][0] == ma) {
					m2--;
					ji_b--;
					for (int j = 1; j <= n; j ++) {
						if (b[m2][1] == a[i][1]) {
							vis[i][0] = 1;
							int gun_a = 1;
						} else if (b[m2][1] == c[i][1]) {
							vis[i][2] = 1;
							int gun_c = 1;
						}
						if (gun_a == 1&& gun_c == 1) {
							gun_a = 0, gun_c = 0;
							break;
						}
					}
				} else if (c[m3][0] == ma) {
					m3--;
					ji_c--;
					for (int j = 1; j <= n; j ++) {
						if (c[m3][1] == b[i][1]) {
							vis[i][1] = 1;
							int gun_b = 1;
						} else if (c[m3][1] == a[i][1]) {
							vis[i][0] = 1;
							int gun_a = 1;
						}
						if (gun_b == 1&& gun_a == 1) {
							gun_b = 0, gun_a = 0;
							break;
						}
					}
				}
				cnt[wb] += ma;
			}
		}
	}
	for (int i = 1; i <= T; i++) {
		cout << cnt[i] << endl;
	}
	return 0;
}
