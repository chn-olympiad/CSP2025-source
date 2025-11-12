#include <bits/stdc++.h>
using namespace std;
int n, m, cnt = 1, a1, tmp;
signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m >> a1;
	for(int i = 2; i <= n * m; ++ i) {
		cin >> tmp;
		if(tmp > a1) ++ cnt;
	}
	int r = (cnt - 1) % n + 1, c = (cnt - 1) / n + 1;
	if(!(c & 1)) r = n - r + 1; 
	cout << c << ' ' << r << '\n';
	fclose(stdin);
	fclose(stdout);
	return 0;
}
