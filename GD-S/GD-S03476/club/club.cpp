#include <bits/stdc++.h>
#define int long long
#define USE_FREOPEN
#define MUL_TEST
#define FILENAME "club"
using namespace std;
int a[100005][10];

void solve() {
	int n;
	cin >> n;
	int c1 = 0, c2 = 0, c3 = 0, sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i][1] >> a[i][2] >> a[i][3];
		int val = max(max(a[i][1], a[i][2]), a[i][3]);
		if (a[i][1] == val) {
			c1++;
			sum += a[i][1];
		} else if (a[i][2] == val) {
			c2++;
			sum += a[i][2];
		} else {
			c3++;
			sum += a[i][3];
		}
	}
	vector<int> vec;
	if (c1 > (n >> 1)) {
		int out = c1 - (n >> 1);
		for (int i = 1; i <= n; i++) {
			int val = max(max(a[i][1], a[i][2]), a[i][3]);
			if (a[i][1] == val) {
				vec.push_back(a[i][1] - max(a[i][2], a[i][3]));
			}
		}
		sort(vec.begin(), vec.end());
		for (int i = 0; i < out; i++) {
			sum -= vec[i];
		}
	} else if (c2 > (n >> 1)) {
		int out = c2 - (n >> 1);
		for (int i = 1; i <= n; i++) {
			int val = max(max(a[i][1], a[i][2]), a[i][3]);
			if (a[i][2] == val) {
				vec.push_back(a[i][2] - max(a[i][1], a[i][3]));
			}
		}
		sort(vec.begin(), vec.end());
		for (int i = 0; i < out; i++) {
			sum -= vec[i];
		}
	} else if (c3 > (n >> 1)) {
		int out = c3 - (n >> 1);
		for (int i = 1; i <= n; i++) {
			int val = max(max(a[i][1], a[i][2]), a[i][3]);
			if (a[i][3] == val) {
				vec.push_back(a[i][3] - max(a[i][1], a[i][2]));
			}
		}
		sort(vec.begin(), vec.end());
		for (int i = 0; i < out; i++) {
			sum -= vec[i];
		}
	}
	cout << sum << '\n';
}

signed main() {
	#ifdef USE_FREOPEN
		freopen(FILENAME ".in", "r", stdin);
		freopen(FILENAME ".out", "w", stdout);
	#endif
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	int _ = 1;
	#ifdef MUL_TEST
		cin >> _;
	#endif
	while (_--)
		solve();
	
	_^=_;
	return (0^_^0);
}
