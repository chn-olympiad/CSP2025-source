#include <bits/stdc++.h>
//#define int long long
using namespace std;
bool cmp (int a, int b) {
	return a > b;
}
int n, m, a[110], c, r, x, nm, xrank;
signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	nm = n * m;
	for (int i = 1; i <= nm; i ++)
		cin >> a[i];
	x = a[1];
	sort(a + 1, a + 1 + nm, cmp);
	for (int i = 1; i <= nm; i ++)
		if (a[i] == x)
			xrank = i;
//	cout << "xrank: " << xrank << endl;
	r = xrank % n;
//	cout << "r: " << r << endl;
	if (r)
		c = xrank / n + 1;
	else {
		c = xrank / n;
		r = n;
	}
	if (c % 2 == 0)
		r = n - r + 1;
	cout << c << " " << r;
	return 0;
}

/*
3 3
94 95 96 97 98 99 100 93 92
*/