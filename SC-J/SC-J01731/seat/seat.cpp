#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int a[N][N];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0);
	int n, m;
	cin >> n >> m;
	int RR = 0;
	vector<int> vec;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int x;
			cin >> x;
			vec.push_back(x);
			if (!RR) {
				RR = x;
			}
		}
	}
	sort(vec.begin(), vec.end(), greater<int>());
	int x = 1, y = 1;
	int tp = 0;
	while (x <= n && y <= m) {
		if (vec[tp] == RR) {
			cout << y << " " << x << "\n";
			return 0;
		}
		if (y & 1) {
			x++;
			if (x == n + 1) {
				x = n, y++;
			}
		} else {
			x--;
			if (x == 0) {
				x = 1, y++;
			}
		}
		tp++;
	}
	return 0;
}