#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 7;

struct node {
	int x, y;
} b[N];

int a[N];

int n, m, r, cnt;

inline bool cmp(int a, int b) {
	return a > b; 
}

signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	
	for (int i = 1; i <= n * m; ++i) {
		scanf("%d", &a[i]);
	}
	
	r = a[1];
	sort(a + 1, a + 1 + n * m, cmp);
	
	for (int i = 1; i <= n; ++i) {
		if (i % 2 == 1) {
			for (int j = 1; j <= m; ++j) {
				b[a[++cnt]].x = i, b[a[cnt]].y = j;
			}
		} else {
			for (int j = m; j; --j) {
				b[a[++cnt]].x = i, b[a[cnt]].y = j;
			}
		}
	} 
	
	printf("%d %d", b[r].x, b[r].y);
	return 0;
}
