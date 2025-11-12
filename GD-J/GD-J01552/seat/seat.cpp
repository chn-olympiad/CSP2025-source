#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e4 + 5;
int n, m, a[maxn];

bool cmp (int x, int y) {
	return x > y;
}

void solve() {
	int pr = a[1], pos = 1;
	sort(a + 1, a + n * m + 1, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (pr == a[i]) {
			pos = i;
			break;
		}
	}
	if (pos == 1) {
		cout << 1 << " " << 1 << endl;
		return ;
	}
	int x = 1, y = 1;
	while (--pos) {
		if (y % 2 != 0 && x + 1 > n || y % 2 == 0 && x - 1 < 1) {
			y++;
		} else {
			if (y % 2 != 0) x++;
			else x--;
		}
	}
	cout << y << " " << x << endl;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	solve();
}
