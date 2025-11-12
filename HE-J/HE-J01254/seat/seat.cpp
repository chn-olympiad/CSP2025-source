#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1e3 + 5;
int n, m, s, a[N], id, x, y;
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	freopen("seat.in", "r" , stdin);
	freopen("seat.out", "w" , stdout);
	cin >> n >> m >> s;
	a[1] = s;
	for (int i = 2; i <= n * m; i ++)
		cin >> a[i];
	sort(a + 1, a + 1 + n * m, cmp);
	for (int i = 1; i <= m; i ++) {
		for (int j = 1; j <= n; j ++) {
			id ++;
			if (a[id] == s) {
				cout << i << ' ' << j;
				return 0;
			}
		}
		i ++;
		for (int j = n; j >= 1; j --) {
			id ++;
			if (a[id] == s) {
				cout << i << ' ' << j;
				return 0;
			}
		}
	}
	return 0;
}

