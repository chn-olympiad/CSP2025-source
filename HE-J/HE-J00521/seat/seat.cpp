#include <iostream>
#include <algorithm>
using namespace std;

int n, m, me, pos, x = 1, y = 1, cnt = 1, a[105];
bool up;

int bin_search(int l, int r) {
	while (l <= r) {
		int mid = (l + r) / 2;
		if (a[mid] == me) return mid;
		else if (a[mid] > me) r = mid - 1;
		else l = mid + 1;
	}
	return l;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1;i <= n * m;i++) cin >> a[i];
	me = a[1];
	sort(a + 1, a + 1 + n * m);
	pos = n * m -  bin_search(1, n * m) + 1;
	while (cnt != pos) {
		if (y == n && !up) {
			x++;
			up = true;
			cnt++;
			continue;
		}
		if (y == 1 && up) {
			x++;
			up = false;
			cnt++;
			continue;
		}
		if (up) y--;
		else y++;
		cnt++;
	}
	cout << x << " " << y << "\n";
	return 0;
}
