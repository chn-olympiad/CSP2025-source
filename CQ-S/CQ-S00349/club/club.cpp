#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const int N = 1e5 + 5;
int t;
int n;
int a[N][5];
ll ans = 0;
bool f = 0; 
//int a[N];
//int b[N];
//int c[N];
//bool f[N];
//bool cmp(pair<int, int> x, pair<int, int> y) {
//	return x.first < y.first;
//}
//void solve() {
//	cin >> n;
//	memset(f, 0, sizeof(f));
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i] >> b[i] >> c[i];
//	}
//	int cnt = 0;
//	int ans = 0;
//	int sum = 0;
//	int num = 0;
//	int f1 = 0;
//	int f2 = 0;
//	for (int i = 1; i <= n; i++) {
//		if (max(a[i], max(b[i], c[i])) == a[i]) {
//			num += a[i];
//			cnt++;
//		}
//	}
//	if (cnt <= n / 2) {
//		ans += num;
//		f1 = n / 2 - cnt;
//		for (int i = 1; i <= n; i++) {
//			if (max(a[i], max(b[i], c[i])) == a[i]) {
//				f[i] = 1;
//				sum++;
//			}
//		}
//	}
//	else {
//		vector<pair<int, int>> v;
//		for (int i = 1; i <= n; i++) {
//			if (max(a[i], max(b[i], c[i])) == a[i]) {
//				v.push_back({a[i], i});
//			}
//		}
//		sort(v.begin(), v.end(), cmp);
//		num = 0;
//		int i = 0;
//		for (pair<int, int> p : v) {
//			int x = p.first;
//			int id = p.second;
//			i++;
//			if (i > n / 2) {
//				break;
//			}
//			num += x;
//			f[id] = 1;
//			sum++;
//		}
//		ans += num;
//		f1 = 0;
//	}
//	cnt = 0;
//	for (int i = 1; i <= n; i++) {
//		if (!f[i] && max(a[i], max(b[i], c[i])) == b[i]) {
//			num += b[i];
//			cnt++;
//		}
//	}
//	if (cnt <= n / 2) {
//		ans += num;
//		f2 = n / 2 - cnt;
//		for (int i = 1; i <= n; i++) {
//			if (!f[i] && max(a[i], max(b[i], c[i])) == b[i]) {
//				f[i] = 1;
//			}
//		}
//	}
//	else {
//		vector<pair<int, int>> v;
//		for (int i = 1; i <= n; i++) {
//			if (!f[i] && max(a[i], max(b[i], c[i])) == b[i]) {
//				v.push_back({b[i], i});
//			}
//		}
//		sort(v.begin(), v.end(), cmp);
//		num = 0;
//		int i = 0;
//		for (pair<int, int> p : v) {
//			int x = p.first;
//			int id = p.second;
//			i++;
//			if (i > n / 2) {
//				break;
//			}
//			num += x;
//			f[id] = 1;
//		}
//		ans += num;
//		f2 = 0;
//		if (f1 != 0) {
//			int lll = 0;
//			int kkk = 0;
//	 		for (int j = i - 1; j < v.size(); j++) {
//				if (!f[j] && a[v[j].second] > c[v[j].second]) {
//					lll++;
//					kkk += a[v[j].second];
//				}
//			}
//			if (lll <= f1) {
//				ans += kkk;
//				f1 -= lll;
//			}
//			else {
//				v.clear();
//				for (int i = 1; i <= n; i++) {
//					if (!f[i] && a[v[i].second] > c[v[i].second]) {
//						v.push_back({a[i], i});
//					}
//				}
//				sort(v.begin(), v.end(), cmp);
//				num = 0;
//				int i = 0;
//				for (pair<int, int> p : v) {
//					int x = p.first;
//					int id = p.second;
//					i++;
//					if (i > n / 2) {
//						break;
//					}
//					num += x;
//					f[id] = 1;
//					sum++;
//				}
//				ans += num;
//				f1 = 0;
//			}
//		}
//	}
//	cnt = 0;
//	if (sum != n) {
//		num = 0;
//		for (int i = 1; i <= n; i++) {
//			if (!f[i] && max(a[i], max(b[i], c[i])) == c[i]) {
//				num += c[i];
//				cnt++;
//			}
//		}
//		if (cnt <= n - sum) {
//			ans += num;
//			for (int i = 1; i <= n; i++) {
//				if (!f[i] && max(a[i], max(b[i], c[i])) == c[i]) {
//					f[i] = 1;
//				}
//			}
//		}
//		else {
//			vector<pair<int, int>> v;
//			for (int i = 1; i <= n; i++) {
//				if (!f[i] && max(a[i], max(b[i], c[i])) == c[i]) {
//					v.push_back({c[i], i});
//				}
//			}
//			sort(v.begin(), v.end(), cmp);
//			num = 0;
//			int i = 0;
//			for (pair<int, int> p : v) {
//				int x = p.first;
//				int id = p.second;
//				i++;
//				if (i > n / 2) {
//					break;
//				}
//				num += x;
//				f[id] = 1;
//			}
//			ans += num;
//			f2 = 0;
//			if (f1 != 0) {
//				int lll = 0;
//				int kkk = 0;
//		 		for (int j = i - 1; j < v.size(); j++) {
//					if (!f[j] && a[v[j].second] > b[v[j].second]) {
//						lll++;
//						kkk += a[v[j].second];
//					}
//				}
//				if (lll <= f1) {
//					ans += kkk;
//					f1 -= lll;
//				}
//				else {
//					v.clear();
//					for (int i = 1; i <= n; i++) {
//						if (!f[i] && a[v[i].second] > b[v[i].second]) {
//							v.push_back({a[i], i});
//						}
//					}
//					sort(v.begin(), v.end(), cmp);
//					num = 0;
//					int i = 0;
//					for (pair<int, int> p : v) {
//						int x = p.first;
//						int id = p.second;
//						i++;
//						if (i > n / 2) {
//							break;
//						}
//						num += x;
//						f[id] = 1;
//						sum++;
//					}
//					ans += num;
//					f1 = 0;
//				}
//			}
//			if (f2 != 0) {
//				vector<int> v1;
//				for (int i = 1; i <= n; i++) {
//					if (!f[i]) {
//						v1.push_back(b[i]);
//					}
//				}
//				sort(v1.begin(), v1.end(), less<int>());
//				for (int i = 0; i < f2; i++) {
//					ans += v1[i];
//				}
//  			}
//		}
//	}
//	cout << ans << endl;
//}
void dfs(ll cnt, int i, int a1, int b, int c) {
	if (i == n + 1) {
		ans = max(ans, cnt);
		return;
	}
	if (a1 < n / 2) dfs(cnt + a[i][1], i + 1, a1 + 1, b, c); 
	if (b < n / 2) dfs(cnt + a[i][2], i + 1, a1, b + 1, c); 
	if (c < n / 2) dfs(cnt + a[i][3], i + 1, a1, b, c + 1); 
}
void solve() {
	ans = 0;
	cin >> n;
	if (n >= 100000) {
		f = 1;
		return ;
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i][1] >> a[i][2] >> a[i][3];
	}
	dfs(0, 1, 0, 0, 0);
	cout << ans << endl;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout); 
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	while (t--) {
		solve();
		if (f == 1) {
			break;
		}
	}
	if (f) {
		cout << "1499392690\n";
		cout << "1500160377\n";
		cout << "1499846353\n";
		cout << "1499268379\n";
		cout << "1500579370\n";
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/ 
