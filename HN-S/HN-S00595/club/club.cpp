#include<bits/stdc++.h>
#define int long long
using namespace std;
int t;
struct KD {
	int a, b, c;
	int xz1, xz2, xz3;
	int maxx = -1;
}k[100015];
bool cmp (KD x, KD y) {
	if (x.xz1 > y.xz1) return true;
	if (x.xz1 < y.xz1) return false;
	if (x.xz2 > y.xz2) return true;
	if (x.xz2 < y.xz2) return false;
	if (x.xz3 > y.xz3) return true;
	if (x.xz3 < y.xz3) return false;
	return true;
}

signed main () {
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	cin >> t;
	for (int i = 1;i <= t;i ++) {
		int club1 = 0, club2 = 0, club3 = 0, ans = 0;
		memset (k, 0, sizeof(k));
		int n;
		cin >> n;
		for (int j = 1;j <= n;j ++) {
			cin >> k[j].a >> k[j].b >> k[j].c;
			k[j].maxx = max (k[j].a, max (k[j].b, k[j].c));
			if (k[j].a >= k[j].b && k[j].a >= k[j].c) {
				k[j].xz1 = 1;
				if (k[j].b >= k[j].c) k[j].xz2 = 2, k[j].xz3 = 3;
				else k[j].xz2 = 3, k[j].xz3 = 2;
			}
			else if (k[j].b >= k[j].a && k[j].b >= k[j].c) {
				k[j].xz1 = 2;
				if (k[j].a >= k[j].c) k[j].xz2 = 1, k[j].xz3 = 3;
				else k[j].xz2 = 3, k[j].xz3 = 1;
			}
			else if (k[j].c >= k[j].b && k[j].c >= k[j].a) {
				k[j].xz1 = 3;
				if (k[j].a >= k[j].b) k[j].xz2 = 1, k[j].xz3 = 2;
				else k[j].xz2 = 2, k[j].xz3 = 1;
			}
		}
		sort (k + 1, k + 1 + n, cmp);
		for (int j = 1;j <= n;j ++) {
			if (k[j].xz1 == 1) {
				if (club1 + 1 <= n / 2) {
					club1 ++, ans += k[j].a;
					continue;
				}
				else {
					if (k[j].xz2 == 2) {
						if (club2 + 1 <= n /2) {
							club2 ++, ans += k[j].b;
							continue;
						}
						else {
							club3 ++, ans += k[j].c;
							continue;
						}
					}
					else {
						if (club3 + 1 <= n / 2) {
							club3 ++, ans += k[j].c;
							continue;
						}
						else {
							club2 ++, ans += k[j].b;
							continue;
						}
					}
				}
			}
			if (k[j].xz1 == 2) {
				if (club2 + 1 <= n / 2) {
					club2 ++, ans += k[j].b;
					continue;
				}
				else {
					if (k[j].xz2 == 1) {
						if (club1 + 1 <= n / 2) {
							club1 ++, ans += k[j].a;
							continue;
						}
						else {
							club3 ++, ans += k[j].c;
							continue;
						}
					}
					else {
						if (club3 + 1 <= n / 2) {
							club3 ++, ans += k[j].c;
							continue;
						}
						else {
							club1 ++, ans += k[j].a;
							continue;
						}
					}
				}
			}
			else {
				if (club3 + 1 <= n / 2) {
					club3 ++, ans += k[j].c;
					continue;
				}
				else {
					if (k[j].xz2 == 1) {
						if (club1 + 1 <= n /2) {
							club1 ++, ans += k[j].a;
							continue;
						}
						else {
							club2 ++, ans += k[j].b;
						}
					}
					else {
						if (club2 + 1 <= n / 2) {
							club2 ++, ans += k[j].b;
							continue;
						}
						else {
							club1 ++, ans += k[j].a;
							continue;
						}
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
} 
