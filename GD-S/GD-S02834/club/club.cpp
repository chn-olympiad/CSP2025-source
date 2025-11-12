#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

struct club{
	int a, b, c, cab, cbc, cac;
};

int cmp(const club x, const club y) {
	return max(x.cab, max(x.cbc, x.cac)) > max(y.cab, max(y.cbc, y.cac));
}

int am(const int a, const int b, const int c) {
	if (a > max(b, c)) {
		return 1;
	}
	else if (b > max(a, c)) {
		return 2;
	}
	if (c > max(a, b)) {
		return 3;
	}
}

int t, n;
club a[100001];
int ans[3];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t --) {
		int sum = 0;
		cin >> n;
		memset(ans, 0, sizeof(ans));
		for (int i = 1; i <= n; i ++) {
			cin >> a[i].a >> a[i].b >> a[i].c;
			a[i].cab = abs(a[i].a - a[i].b);
			a[i].cbc = abs(a[i].b - a[i].c);
			a[i].cac = abs(a[i].a - a[i].c);
		}
		sort(a + 1, a + n + 1, cmp);
		for (int i = 1; i <= n; i ++) {
			if (ans[am(a[i].a, a[i].b, a[i].c)] < n / 2) {
				ans[am(a[i].a, a[i].b, a[i].c)] ++;
				sum += max(a[i].a, max(a[i].b, a[i].c));
			}
			else {
				int s = min(a[i].cab, min(a[i].cbc, a[i].cac)), ss = max(a[i].a, max(a[i].b, a[i].c));
				if ((s == a[i].cab || s != a[i].cab) && ((ss == a[i].a || ss == a[i].b) && (a[i].a >= n / 2 || a[i].b >= n / 2))) {
					if (ss == a[i].a && ans[2] < n / 2) {
						ans[2] ++;
						sum += a[i].b;
					}
					if (ss == a[i].b && ans[1] < n / 2) {
						ans[1] ++;
						sum += a[i].a;
					}
				}
				if (s == a[i].cbc || (s != a[i].cbc && ((ss == a[i].b || ss == a[i].c) && (a[i].b >= n / 2 || a[i].c >= n / 2)))) {
					if (ss == a[i].b && ans[3] < n / 2) {
						ans[3] ++;
						sum += a[i].c;
					}
					if (ss == a[i].c && ans[2] < n / 2) {
						ans[2] ++;
						sum += a[i].b;
					}
				}
				if (s == a[i].cac || (s != a[i].cac && ((ss == a[i].a || ss == a[i].c) && (a[i].a >= n / 2 || a[i].c >= n / 2)))) {
					if (ss == a[i].a && ans[3] < n / 2) {
						ans[3] ++;
						sum += a[i].c;
					}
					if (ss == a[i].c && ans[1] < n / 2) {
						ans[1] ++;
						sum += a[i].a;
					}
				}
			}
		}
		cout << sum << endl;
	}
	return 0;
}
