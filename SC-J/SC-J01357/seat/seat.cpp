#include <bits/stdc++.h>
using namespace std;

const int maxn = 105;

int n, m, a[maxn];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	int rk = 0;
	for(int i = 1; i <= n * m; i++) {
		cin >> a[i];
		if(a[i] >= a[1]) rk++;
	}
	int x = (rk + n - 1) / n;
	int y = (x & 1) ? n - (x * n - rk) : 1 + (x * n - rk);
	cout << x << " " << y << "\n";
	return 0;
}