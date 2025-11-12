#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
// B
int T;
struct S {
	int a, b, c;
} p[N];
//pii: i1 : val ; i2: pos
bool check(int x) {
	priority_queue<pair<pair<int, int>, int>> pq; // p pii: i1: val, i2: ¼ÓÈë, i: i1: ±àºÅ 
	int n;
	bool vis[N];
	int ja, jb, jc;
	int sum = 0;
	ja = jb = jc = 0;
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> p[i].a >> p[i].b >> p[i].c;
		pq.push({{p[i].a, 1}, i});
		pq.push({{p[i].b, 2}, i});
		pq.push({{p[i].c, 3}, i});
	}
	while (ja + jb + jc < n) {
		pair<pair<int, int>, int> no = pq.top();
		pq.pop();
		int noi, noj, nov;
		nov = no.first.first;
		noj = no.first.second;
		noi = no.second;
//		cout << noi << ' ' << noj << ' ' << nov << endl; 
		if (!vis[noi]) {
			if (noj == 1 && ja < n / 2) {
				vis[noi] = true;
				sum += nov;
				ja ++;
			}
			if (noj == 2 && jb < n / 2) {
				vis[noi] = true;
				sum += nov;
				jb ++;
			}
			if (noj == 3 && jc < n / 2) {
				vis[noi] = true;
				sum += nov;
				jc ++;
			}
		}
	}
	cout << sum;
}
void solve() {
	check(0);
//	long long sum = 0;
//	int l, r;
//	while (l < r) {
//		int mid = l + r >> 1;
//		if (check(mid)) {
//			l = mid + 1;
//		} else {
//			r = mid;
//		}
//	}
//	cout << l;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while (T --) {
		solve();
	}
	return 0;
} 
/*
                                          yours
										kao sheng
*/
