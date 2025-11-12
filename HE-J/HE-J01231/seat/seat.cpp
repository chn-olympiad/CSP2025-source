// Stay still.
#include <bits/stdc++.h>
using namespace std;

int n, m, a[10005], mp[105][105], s;
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n * m; ++i)
		scanf("%d", &a[i]);
	s = a[1];
	sort(a + 1, a + 1 + n * m, [](int a, int b){ return a > b; });
	for (int nown = 1, nowm = 1, cnt = 1, tmp = 1; ; ++cnt) {
		mp[nown][nowm] = a[cnt];
		if (cnt == n * m) break;
		if (a[cnt] == s) {
			printf("%d %d", nowm, nown);
			break;
		}
		if (tmp == 1) {
			if (nown == n) nowm++, tmp = 0;
			else nown++;
		} else {
			if (nown == 1) nowm++, tmp = 1;
			else nown--;
		}
	}
//	for (int i = 1; i <= n; ++i) {
//		for (int j = 1; j <= m; ++j)
//			cout << mp[i][j] << ' ';
//		cout << '\n';
//	}
	return 0;
}
