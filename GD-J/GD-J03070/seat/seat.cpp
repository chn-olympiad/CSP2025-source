#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int a[N];
bool cmp (int a, int b) {
	return a > b;
}
int main () {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	int x;
	for (int i = 0; i < n * m; i ++) {
		cin >> a[i];
	}
	x = a[0];
	int y;
	sort (a, a + n * m, cmp);
	for (int i = 0; i < n * m; i ++) {
		if (a[i] == x) y = i + 1;
 	}
	int l = (y + n - 1) / n, h = y % n;
	if (h == 0) h += n;
	if (l % 2 == 0) h = m - h + 1;
	cout << l << ' ' << h;
	return 0;
} 
