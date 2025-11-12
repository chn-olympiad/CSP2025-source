#include <bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int A, int B) { return A > B; }
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n * m; i++) cin >> a[i];
	int tmp = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	int x = 1, y = 1;
	for (int i = 1; i <= n * m; i++) {
		//cout << x << ' ' << y << endl;
		if (a[i] == tmp) {
			cout << y << ' ' << x;
			return 0;
		}
		if (y % 2 == 1) {
			if (x == n) y++;
			else x++;
		}
		else {
			if (x == 1) y++;
			else x--;
		}
	}
	return 0;
}
