#include <bits/stdc++.h>
using namespace std;

const int N = 110;
struct node {
	int val, id;
};
node a[N];

bool cmp(node x, node y) {
	return x.val > y.val;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n * m; i++) {
		scanf("%d", &a[i].val);
		a[i].id = i;
	}
	sort(a + 1, a + n * m + 1, cmp);
	int l = 1, r = 1;
	for (int i = 1; i <= n * m; i++) {
		if (a[i].id == 1) {
			printf("%d %d", l, r);
			return 0;
		}
		if (l % 2 == 1) r++;
		else r--;
		if (r > n) {
			l++;
			r = n;
		}
		if (r < 1) {
			l++;
			r = 1;
		}
	}
	return 0;
}
