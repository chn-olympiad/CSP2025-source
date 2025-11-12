#include <bits/stdc++.h>
using namespace std;
const int N = 100 + 50;
struct node {
	int num, id;
} a[N];
bool cmp(const node a, const node b) {
	return a.num > b.num;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n * m; i++) {
		scanf("%d", &a[i].num);
		a[i].id = i;
	}
	sort(a + 1, a + n * m + 1, cmp);
	int x = 0, y = 1;
	for (int i = 1; i <= n * m; i++) {
		if (x % 2 == 0) {
			if (y == 1) {
				x++;
			} else {
				y--;
			}
		} else {
			if (y == n) {
				x++;
			} else {
				y++;
			}
		}
		if (a[i].id == 1) {
			printf("%d %d\n", x, y);
			break;
		}
	}
	return 0;
}
