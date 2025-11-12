#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int> > a;
int b[15][15];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n * m; i++) {
		int x;
		scanf("%d", &x);
		a.emplace_back(x, i);
	}
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	int cnt = 0;
	for (int c = 1; c <= m; c++) {
		if (c & 1) {
			for (int r = 1; r <= n; r++) {
				if (a[cnt].second == 1) {
					printf("%d %d\n", c, r);
				}
				cnt++;
			}
		} else {
			for (int r = n; r >= 1; r--) {
				if (a[cnt].second == 1) {
					printf("%d %d\n", c, r);
				}
				cnt++;
			}
		}
	}
	return 0;
}