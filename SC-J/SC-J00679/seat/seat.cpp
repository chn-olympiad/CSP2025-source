#include <bits/stdc++.h>
using namespace std;
constexpr int N = 10 + 5;

int n, m, sco;
int a[N * N];

bool cmp (int x, int y) {
	return x > y;
}

int main () {
	freopen ("seat.in", "r", stdin);
	freopen ("seat.out", "w", stdout);
	scanf ("%d%d", &n, &m);
	for (int i = 1; i <= n * m; ++ i) scanf ("%d", &a[i]);
	sco = a[1];
	sort (a + 1, a + n * m + 1, cmp);
	int x = 1, y = 1, d = 0;
	for (int i = 2; i <= n * m; ++ i) {
		if (d == 0) {//向下
			if (x == n) {
				d = 1;
				y ++;
			} else ++ x;
			if (a[i] == sco) {
				printf ("%d %d\n", y, x);
				return 0;
			}
		} else {//向上 
			if (x == 1) {
				d = 0;
				y ++;
			} else -- x;
			if (a[i] == sco) {
				printf ("%d %d\n", y, x);
				return 0;
			}
		}
	}
	return 0;
}