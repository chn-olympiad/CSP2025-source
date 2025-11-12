#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using db = double;
using ldb = long double;

const int N = 1e6 + 5;
int n, m, a[N];

inline bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n * m; ++i) cin >> a[i];
	int x = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	x = lower_bound(a + 1, a + n * m + 1, x, cmp) - a;
	int l = (x - 1) / n + 1, h = x % n;
	if (h == 0) h = n;
	if (l & 1) cout << l << ' ' << h;
	else cout << l << ' ' << n + 1 - h;
	return 0;
}
/*
2 3
3 2 4 1 5 6
2 2
99 100 97 98
2 2
98 99 100 97
3 3
94 95 96 97 98 99 100 93 92
*/
