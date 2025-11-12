#include <bits/stdc++.h>

using namespace std;
 
struct clubInfo {
	long long aptm, mxDiff;
};

bool cmp(clubInfo a, clubInfo b) {
	return (a.mxDiff < b.mxDiff);
}

long long t, n, a, b, c, na, nb, nc, res, mxv;
clubInfo plan[100010], curr;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin >> t;
	while (t--) {
		cin >> n;
		mxv = n / 2;
		res = 0;
		na = 0;
		nb = 0;
		nc = 0;
		for (long long i = 0; i < n; i++) {
			cin >> a >> b >> c;
//			if (i == 174) {
//				cout << a[i][0] << ' ' << a[i][1] << ' ' << a[i][2] << endl;
//			}  // test
			if (a >= b && a >= c) {
				curr.aptm = 0;
				curr.mxDiff = a - max(b, c);
				res += a;
				na++; 
			}
			else if (b >= a && b >= c) {
				curr.aptm = 1;
				curr.mxDiff = b - max(a, c);
				res += b;
				nb++;
			}
			else {
				curr.aptm = 2;
				curr.mxDiff = c - max(a, b);
				res += c;
				nc++;
			}
			plan[i] = curr;
		}
		sort(plan, plan + n, cmp);
//		cout << plan[0].mxDiff << ' ' << plan[0].mx2 << ' ' << plan[0].aptm << ' ' << plan[0].id << endl;  // test
//		for (int i = 0; i < n; i++) {
//			cout << plan[i].mxDiff << ' ' << plan[i].mx2 << ' ' << plan[i].aptm << ' ' << plan[i].id << endl;
//		}  // test
		if (na > mxv) {
			for (long long i = 0; i < n; i++) {
				if (plan[i].aptm == 0) {
					res -= plan[i].mxDiff;
					if (--na <= mxv) {
						break;
					}
				}
			}
		}
		else if (nb > mxv) {
			for (long long i = 0; i < n; i++) {
				if (plan[i].aptm == 1) {
					res -= plan[i].mxDiff;
					if (--nb <= mxv) {
						break;
					}
				}
			}
		}
		else if (nc > mxv) {
			for (long long i = 0; i < n; i++) {
				if (plan[i].aptm == 2) {
					res -= plan[i].mxDiff;
					if (--nc <= mxv) {
						break;
					}
				}
			}
		}
		cout << res << endl;
	}
	return 0;
}
