#include <bits/stdc++.h>
using namespace std;

int a[103], b[13][13];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n*m; ++i)
		cin >> a[i];
	int k = a[1];
	sort(a+1, a+n*m+1, greater<>());
	bool flg = false; 
	for(int i = 1, x=1, y=1; i <= n*m; ++i) {
		b[x][y] = a[i];
		if(flg) // ио 
			if(x == 1) {
				++y;
				flg = !flg;
			} else
				--x;
		else // об 
			if(x == n) {
				++y;
				flg = !flg;
			} else
				++x;
	}
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			if(b[i][j] == k) {
				cout << j << ' ' << i << endl;
				return 0;
			}
	return 0;
}
