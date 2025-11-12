#include <bits/stdc++.h>
using namespace std;

int n, m;
struct node{
	int id, val;
	bool operator < (const node &A) const {
		return val > A.val;
	}
} a[105];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n * m; i++) {
		scanf("%d", &a[i].val);
		a[i].id = i;
	}
	sort(a + 1, a + n * m + 1);
	int pos = -1;
	for (int i = 1; i <= n * m; i++) {
		if (a[i].id == 1) {
			pos = i;
			break;
		}
	}
	int x = 1, y = 1, d = 1;
	for (int i = 2; i <= pos; i++) {
		int nx = x + d, ny = y;
		if (nx < 1 || nx > n) {
			nx = x;
			d = -d;
			ny++;
		}
		x = nx, y = ny;
	}
	printf("%d %d\n", y, x);
	return 0;
}
