#include <bits/stdc++.h>
using namespace std;
const int MAX = 15;
int n, m, s[MAX * MAX], len, R;
// c  r      (c = lie, r = hang)
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	len = n * m;
	for (int i = 1; i <= len; i++) {
		scanf("%d", s + i);
		if (i == 1) R = s[i];
	}
	sort(s + 1, s + 1 + len, greater<int>());
	int c = 1, r = 1, dir = 1;
	for (int i = 1; i <= len; i++) {
		if (s[i] == R) {
			printf("%d %d", c, r);
			break;
		}
		r += dir;
		if (r < 1) {
			dir = -dir;
			r = 1;
			c++;
		} else if (r > n) {
			dir = -dir;
			r = n;
			c++;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
