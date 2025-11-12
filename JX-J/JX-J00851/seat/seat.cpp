#include <bits/stdc++.h>
using namespace std;
const int M = 105;
int n, m, a[M], b[M];
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n * m; ++i)
		cin >> a[i], b[i] = a[i];
	sort(b + 1, b + n * m + 1, greater<int>());
	for (int i = 1; i <= n * m; ++i) 
		if (b[i] == a[1]) {
			int r = ceil((double)i / n);
			int c;
			c = i - (r - 1) * n;
			if (!(r & 1)) c = n - c + 1;
			cout << r  << ' ' << c << '\n';
			break;
		}
	return 0;
}
/*
g++ seat.cpp -o seat -O2 -std=c++14 -static
*/