#include <bits/stdc++.h>
using namespace std;
int m, n, l, p, s[105], st[15][15];
bool cmp (int a, int b) { return a > b;}
int main () {
	freopen ("seat.in", "r", stdin);
	freopen ("seat.out", "w", stdout);
	scanf ("%d%d", &n, &m);
	for (int i = 1; i <= n * m; i++) scanf ("%d", &s[i]);
	p = s[1];
	sort (s + 1, s + n * m + 1, cmp); 
	for (int i = 1; i <= n * m; i++) {
		if (s[i] == p) {
			l = i;
			break;
		}
	}
	int i = 1, j = 1, k = 1;
	bool down = true;
	while (k < l) {
		if (down && j + 1 <= n) j++;
		else if (!down && j - 1 >= 1) j--;
		else if (down && j + 1 > n) i++, down = false;
		else if (!down && j - 1 < 1) i++, down = true;
		k++;
	}
	printf ("%d %d", i, j);
	return 0;
} 
