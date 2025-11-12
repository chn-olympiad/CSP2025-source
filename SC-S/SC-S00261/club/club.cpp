#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int t, n;
struct node {
	int a, b, c, m1, m2, m3, mm1, mm2, mm3;
}d[N];
bool cmp (node x, node y) {
	if ((x.mm1 - x.mm2) == (y.mm1 - y.mm2)) {
		return x.mm1 > y.mm1;
	}
	return (x.mm1 - x.mm2) > (y.mm1 - y.mm2);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0); 
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		cin >> n;
		int m = n / 2, aa = 0, bb = 0, cc = 0, ans = 0;
		for (int i = 1; i <= n; i++) {
			cin >> d[i].a >> d[i].b >> d[i].c;
			if (d[i].a > d[i].b && d[i].a > d[i].c) {
				d[i].mm1 = d[i].a;
				d[i].m1 = 1;
				if (d[i].b > d[i].c) {
					d[i].m2 = 2;
					d[i].m3 = 3;
					d[i].mm2 = d[i].b;
					d[i].mm3 = d[i].c;
				}
				else {
					d[i].m3 = 2;
					d[i].m2 = 3;
					d[i].mm2 = d[i].c;
					d[i].mm3 = d[i].b;
				}
			}
			else if (d[i].b > d[i].c && d[i].b > d[i].c) {
				d[i].m1 = 2;
				d[i].mm1 = d[i].b;
				if (d[i].a > d[i].c) {
					d[i].m2 = 1;
					d[i].m3 = 3;
					d[i].mm2 = d[i].a;
					d[i].mm3 = d[i].c;
				}
				else {
					d[i].m3 = 1;
					d[i].m2 = 3;
					d[i].mm2 = d[i].c;
					d[i].mm3 = d[i].a;
				}
			}
			else {
				d[i].m1 = 3;
				d[i].mm1 = d[i].c;
				if (d[i].a > d[i].b) {
					d[i].m2 = 1;
					d[i].m3 = 2;
					d[i].mm2 = d[i].a;
					d[i].mm3 = d[i].b;
				}
				else {
					d[i].m3 = 1;
					d[i].m2 = 2;
					d[i].mm2 = d[i].b;
					d[i].mm3 = d[i].a;
				}
			}
		}
		sort(d + 1, d + n + 1, cmp);
		for (int i = 1; i <= n; i++) {
			if (d[i].m1 == 1) {
				if (aa != m) {
					ans += d[i].a;
					aa++;
				}
				else {
					if (d[i].m2 == 2) {
						ans += d[i].b;
						bb++;
					}
					else {
						ans += d[i].c;
						cc++;
					}
				}
			}
			else if (d[i].m1 == 2) {
				if (bb != m) {
					ans += d[i].b;
					bb++;
				}
				else {
					if (d[i].m2 == 1) {
						ans += d[i].a;
						aa++;
					}
					else {
						ans += d[i].c;
						cc++;
					}
				}
			}
			else if (d[i].m1 == 3) {
				if (cc != m) {
					ans += d[i].c;
					cc++;
				}
				else {
					if (d[i].m2 == 1) {
						ans += d[i].a;
						aa++;
					}
					else {
						ans += d[i].b;
						bb++;
					}
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
} 