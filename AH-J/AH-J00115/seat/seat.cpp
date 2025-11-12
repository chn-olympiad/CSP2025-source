#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int a[N], n, m;
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++) cin >> a[i];
	int w = a[1];
	sort(a + 1, a + n * m + 1);
	w = n * m - (lower_bound(a + 1, a + n * m + 1, w) - a) + 1;
	//cout << w << endl;
	int x = w / n;
	if(x * n != w) x++;
	int y = w % n;
	if(y == 0) y = n;
	if(x % 2 == 0) y = n - y + 1;
	cout << x << ' ' << y;
	return 0;
}
