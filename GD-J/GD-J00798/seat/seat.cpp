#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 110;
int n, m, a[N], _, idx;
bool cmp(int x, int y) {
	return x > y;
}
signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) cin >> a[i];
	_ = a[1];
	sort(a + 1, a + 1 + n * m, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == _) {
			idx = i;
			break ;
		}
	}
	_ = ceil(idx * 1.0 / n);
	cout << _ << " ";
	idx -= n * (_ - 1);
	if (_ % 2 == 0) cout << n - idx + 1;
	else cout << idx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
2 2
99 100 97 98

2 2
98 99 100 97

3 3
94 95 96 97 98 99 100 93 92

4 4
9 2 1 3 4 5 6 7 8 10 11 12 13 14 15 16
*/
