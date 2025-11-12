#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 100 * 100;
int n, m, a[MAXN];
int st[50][50], purp;
int main() {
	freopen ("seat.in", "r", stdin);
	freopen ("seat.out", "w", stdout);
	scanf ("%d %d", &n, &m);
	for (int i = 1; i <= n * m; i++) {
		scanf ("%d", &a[i]);
		a[i] *= -1;
	} 
	purp = a[1];
	sort (a + 1, a + n * m + 1);
	for (int x = 1, y = 1, pos = 1, cur = 1; cur <= m * n; ) {
		if (a[cur] == purp) {
			cout << y << " " << x << endl;
			return 0;
		}
		//cout << x <<"   "  << y << endl;
		if ((pos == 1 && x == n) || (pos == -1 && x == 1)) pos *= -1, y += 1;
		else x += pos;
		cur += 1;
	}
	return 0;
}