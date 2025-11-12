#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e1 + 10;
int n, m, k;
int a[N];

bool cmp (int a, int b) {
	return a > b;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n * m; i++) {
		scanf("%d", a + i);
	}
	k = a[1];
	sort(a + 1, a + 1 + n * m, cmp);
	int f = 1, x = 1, y = 1, i = 1;
	while (true) {
		if (a[i] == k) {
			printf("%d %d\n", y, x);
			break;
		} else {
			if (x == n && f) {
				y++;
				f = 0;
			} else if (x == 1 && !f) {
				y++;
				f = 1;
			} else {
				if (f) {
					x++;
				} else {
					x--;
				}
			}
			i++;
		}
	}
	return 0;
}
