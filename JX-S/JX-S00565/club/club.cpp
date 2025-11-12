#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
struct node{
	pair<int, int> t[3];
	int s[2];
}a[100005];
bool pp(pair<int, int> x, pair<int, int> y) {
	return x.fi < y.fi;
}
bool cmp(pair<int, int> x, pair<int, int> y) {
	int t1, t2, t3, t4;
	if (x.se == 2) t1 = a[x.fi].s[1], t3 = t1 + a[x.fi].s[0];
	else t3 = t1 = a[x.fi].s[0];
	if (y.se == 2) t2 = a[y.fi].s[1], t4 = t2 + a[y.fi].s[0];
	else t4 = t2 = a[y.fi].s[0];
	if (t1 != t2) {
		return t1 < t2;
	}
	return t3 < t4;
}
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			vector<pair<int, int> > A(3);
			cin >> A[0].fi >> A[1].fi >> A[2].fi;
			A[0].se = 0;
			A[1].se = 1;
			A[2].se = 2;
			sort(A.begin(), A.end(), pp);
			a[i].t[0] = A[0];
			a[i].t[1] = A[1];
			a[i].t[2] = A[2];
			a[i].s[1] = a[i].t[2].fi - a[i].t[1].fi;
			a[i].s[0] = a[i].t[1].fi - a[i].t[0].fi;
//			cout << i << " : \n";
//			cout << "0 : " << a[i].t[0].fi << " " << a[i].t[0].se << "\n";
//			cout << "1 : " << a[i].t[1].fi << " " << a[i].t[1].se << "\n";
//			cout << "2 : " << a[i].t[2].fi << " " << a[i].t[2].se << "\n";
			
		}
//		cout << "\n";
		vector<pair<int, int> > c1, c2, c3;
		for (int i = 1; i <= n; i++) {
			if (a[i].t[2].se == 0) {
				c1.push_back({i, 2});
			}
			if (a[i].t[2].se == 1) {
				c2.push_back({i, 2});
			}
			if (a[i].t[2].se == 2) {
				c3.push_back({i, 2});
			}

		}
		int ans = 0, c1s = 0, c2s = 0, c3s = 0;
//		cout << "c1 size: " << c1.size() << "\n";
//		cout << "c2 size: " << c2.size() << "\n";
//		cout << "c3 size: " << c3.size() << "\n";
		if (c1.size() > n / 2) {
			sort(c1.begin(), c1.end(), cmp);
			for (int i = c1s; i < c1.size(); i++) {
				if (c1.size() - i <= n / 2) {
					c1s = i;
					break;
				}
//				cout << i << " : " << a[c1[i].fi].t[c1[i].se - 1].se << "\n";
				if (a[c1[i].fi].t[c1[i].se - 1].se == 1) {
					c2.push_back({c1[i].fi, c1[i].se - 1});
				}
				if (a[c1[i].fi].t[c1[i].se - 1].se == 2) {
					c3.push_back({c1[i].fi, c1[i].se - 1});
				}
			}
		}
		if (c2.size() > n / 2) {
			sort(c2.begin(), c2.end(), cmp);
			for (int i = c2s; i < c2.size(); i++) {
				if (c2.size() - i <= n / 2) {
					c2s = i;
					break;
				}
				if (a[c2[i].fi].t[c2[i].se - 1].se == 0) {
					c1.push_back({c2[i].fi, c2[i].se - 1});
				}
				if (a[c2[i].fi].t[c2[i].se - 1].se == 2) {
					c3.push_back({c2[i].fi, c2[i].se - 1});
				}
			}
		}
		if (c3.size() > n / 2) {
			sort(c3.begin(), c3.end(), cmp);
			for (int i = c3s; i < c3.size(); i++) {
				if (c3.size() - i <= n / 2) {
					c3s = i;
					break;
				}
				if (a[c3[i].fi].t[c3[i].se - 1].se == 0) {
					c1.push_back({c3[i].fi, c3[i].se - 1});
				}
				if (a[c3[i].fi].t[c3[i].se - 1].se == 1) {
					c2.push_back({c3[i].fi, c3[i].se - 1});
				}
			}
		}
//		cout << t << " : \n";
		for (int i = c1s; i < c1.size(); i++) {
			ans += a[c1[i].fi].t[c1[i].se].fi;
		}
//		cout << "1 : " << ans << "\n";
		for (int i = c2s; i < c2.size(); i++) {
			ans += a[c2[i].fi].t[c2[i].se].fi;
		}
//		cout << "2 : " << ans << "\n";
		for (int i = c3s; i < c3.size(); i++) {
			ans += a[c3[i].fi].t[c3[i].se].fi;
		}
		cout << ans << "\n";
	}
	return 0;
}
// luogu uid: 1277793
// shift!
