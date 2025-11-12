#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m, a[105], s[105];

bool cmp(int x, int y) {
	return x > y;
}

signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);

	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n * m; i++) {
		scanf("%lld", &a[i]);
		s[i] = a[i];
	}
	
	sort(s + 1, s + 1 + n * m, cmp);
	
	int x = 1, y = 1, i = 1, f = 0;
	while (x <= m) {
		while (y <= n) {
			if (s[i] == a[1]) {
				f = 1;
				break;
			}
			y++;
			i++;
		}
		if (f == 1) break;
		y--;
		x++;
		while (y >= 1) {
			if (s[i] == a[1]) {
				f = 1;
				break;
			}
			y--; 
			i++;
		}
		if (f == 1) break;
		y++;
		x++;
	}
	printf("%lld %lld", x, y);

	return 0;
}
/*
2 2
99 100 97 98
*/
/*
2 2
98 99 100 97
*/
/*
3 3
94 95 96 97 98 99 100 93 92
*/
