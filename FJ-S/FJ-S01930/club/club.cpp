#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Student {
	int a1, a2, a3;
};

struct node {
	int d;
	int id, to;
	bool operator < (const node &b) const {
		return d > b.d;
	}
};

void solve() {
	int n;
	cin >> n;
	vector<Student> a(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i].a1 >> a[i].a2 >> a[i].a3;
	}
	priority_queue<node> q1, q2, q3;
	int cnt1 = 0, cnt2 = 0, cnt3 = 0;
	int val1 = 0, val2 = 0, val3 = 0;
//	sort(a.begin() + 1, a.end());
	for (int i = 1; i <= n; ++i) {
		int ma = max({a[i].a1, a[i].a2, a[i].a3});
		if (ma == a[i].a1) { // 1
			if (cnt1 < n / 2) {
				val1 += ma, cnt1++;
				if (ma - a[i].a2 < ma - a[i].a3)
					q1.push({ma - a[i].a2, i, 2});
				else
					q1.push({ma - a[i].a3, i, 3});
			} else if (ma - a[i].a2 < ma - a[i].a3) {
				// a3 < a2 < a1
				int d = ma - a[i].a2;
				if (q1.top().d < d) {
					val1 += ma;
					int id = q1.top().id;
					val1 -= a[id].a1;
					if (q1.top().to == 2) {
						val2 += a[id].a2, cnt2++;
					} else {
						val3 += a[id].a3, cnt3++;
					}
					q1.pop();
					q1.push({d, i, 2});
				} else {
					val2 += a[i].a2, cnt2++;
					q2.push({-d, i, 1});
				}
			} else {
				int d = ma - a[i].a3;
				if (q1.top().d < d) {
					val1 += ma;
					int id = q1.top().id;
					val1 -= a[id].a1;
					if (q1.top().to == 2) {
						val2 += a[id].a2, cnt2++;
					} else {
						val3 += a[id].a3, cnt3++;
					}
					q1.pop();
					q1.push({d, i, 3});
				} else {
					val3 += a[i].a3, cnt3++;
					q3.push({-d, i, 1});
				}
			}
		} else if (ma == a[i].a2) { // 2
		
			if (cnt2 < n / 2) {
//			cerr << "OKK" << endl;
				val2 += ma, cnt2++;
				if (ma - a[i].a1 < ma - a[i].a3)
					q2.push({ma - a[i].a1, i, 1});
				else
					q2.push({ma - a[i].a3, i, 3});
			} else if (ma - a[i].a1 < ma - a[i].a3) {
				int d = ma - a[i].a1;
				if (q2.top().d < d) {
					val2 += ma;
					int id = q2.top().id;
					val2 -= a[id].a2;
					if (q2.top().to == 1) {
						val1 += a[id].a1, cnt1++;
					} else {
						val3 += a[id].a3, cnt3++;
					}
					q2.pop();
					q2.push({d, i, 1});
				} else {
					val1 += a[i].a1, cnt1++;
					q1.push({-d, i, 2});
				}
			} else {
				int d = ma - a[i].a3;
				if (q2.top().d < d) {
					val2 += ma;
					int id = q2.top().id;
					val2 -= a[id].a2;
					if (q2.top().to == 1) {
						val1 += a[id].a1, cnt1++;
					} else {
						val3 += a[id].a3, cnt3++;
					}
					q2.pop();
					q2.push({d, i, 3});
				} else {
					val3 += a[i].a3, cnt3++;
					q3.push({-d, i, 2});
				}
			}
		} else { // 3
			if (cnt3 < n / 2) {
//				cerr << ma << endl;
				val3 += ma, cnt3++;
				if (ma - a[i].a1 < ma - a[i].a2)
					q3.push({ma - a[i].a1, i, 1});
				else
					q3.push({ma - a[i].a2, i, 2});
			} else if (ma - a[i].a1 < ma - a[i].a2) {
				int d = ma - a[i].a1;
				if (q3.top().d < d) {
					val3 += ma;
					int id = q3.top().id;
					val3 -= a[id].a3;
					if (q3.top().to == 1) {
						val1 += a[id].a1, cnt1++;
					} else {
						val2 += a[id].a2, cnt2++;
					}
					q3.pop();
					q3.push({d, i, 1});
				} else {
					val1 += a[i].a1, cnt1++;
					q1.push({-d, i, 3});
				}
			} else {
				int d = ma - a[i].a2;
				if (q3.top().d < d) {
					val3 += ma;
					int id = q3.top().id;
					val3 -= a[id].a3;
					if (q3.top().to == 1) {
						val1 += a[id].a1, cnt1++;
					} else {
						val2 += a[id].a2, cnt2++;
					}
					q3.pop();
					q3.push({d, i, 2});
				} else {
					val2 += a[i].a2, cnt2++;
					q2.push({-d, i, 3});
				}
			}
		}
	}
//	while (!q3.empty()) {
//		cerr << q3.top().id << '\n';
//		q3.pop();
//	}
	cout << val1 + val2 + val3 << "\n";
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}

