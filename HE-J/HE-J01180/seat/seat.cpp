#include <bits/stdc++.h>
using namespace std;
int n, m, a[110], r_mark, x = 1, y = 1;
bool cmp(int num_1, int num_2) {
	return num_1 > num_2;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
		cin >> a[i];
	r_mark = a[1];
	sort(a + 1, a + 1 + n * m, cmp);
	for(int i = 1; i <= m * n; i++) {
		if (a[i] == r_mark)
			break;
		if (y % 2) {
			x++;
		} else {
			x--;
		}
		if (x == n + 1)
			x--, y++;
		if (x == 0)
			x++, y++;
//		cout << y << ' ' << x <<endl;
	}
	cout << y << ' ' << x <<endl;
	return 0;
}
