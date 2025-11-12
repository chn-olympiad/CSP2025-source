#include<bits/stdc++.h>
using namespace std;
#define rep(i, j, k) for (int i = j; i <= k; ++i) 
const int N = 1e5 + 5;
int n;
int a[N], b[N], c[N];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		vector<int> cl[3];
		long long sum = 0;
		rep (i, 1, n) {
			cin >> a[i] >> b[i] >> c[i];
			if (a[i] > b[i] && a[i] > c[i]) cl[0].push_back(i);
			else if (b[i] > c[i] && b[i] > a[i]) cl[1].push_back(i);
			else cl[2].push_back(i);
			sum += max({a[i], b[i], c[i]});
		}
		if (max({cl[0].size(), cl[1].size(), cl[2].size()}) <= n / 2) {
			cout << sum << '\n';
		} else {
			vector<int> x;
			if (cl[0].size() > n / 2) {
				for (int i : cl[0]) {
					x.push_back(a[i] - max(b[i], c[i]));
				}
			}
			if (cl[1].size() > n / 2) {
				for (int i : cl[1]) {
					x.push_back(b[i] - max(a[i], c[i]));
				}
			}
			if (cl[2].size() > n / 2) {
				for (int i : cl[2]) {
					x.push_back(c[i] - max(b[i], a[i]));
				}
			}
			sort(x.begin(), x.end());
			int id = max({cl[0].size(), cl[1].size(), cl[2].size()}) - n / 2;
			rep (i, 0, id - 1) {
				sum -= x[i];
			}
			cout << sum << '\n';
		}
	}
}
