#include <bits/stdc++.h>
using namespace std;
//2  seat
int n, m, a[200], R, j = 1, l = 1;
bool cmp (int x, int y) {
	return x > y;
}
int main () {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	int len = n * m;
	for (int i = 1; i <= len; i++) {
		scanf("%d", &a[i]); 
	}
	R = a[1];
	sort(a + 1, a + len + 1, cmp);
	int flag = 0;
	for (int i = 1; i <= m; ) {
		while (j <= n && j >= 1) {
			if (a[l] == R) {
				printf("%d %d", i, j);
				return 0;
			}
			if (flag == 1) --j;
			if (flag == 0) ++j;
			++l;
		}
		if (j > n) {
			flag = 1;
			--j;
			++i;
		}
		if (j < 1) {
			flag = 0;
			++j;
			++i;
		}
	}
	return 0;
}
