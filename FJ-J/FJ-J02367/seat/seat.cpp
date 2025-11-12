#include <bits/stdc++.h>
using namespace std;
const int N = 210;
int n, m;
int a[N];
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n * m; i++) 
		scanf("%d", &a[i]);
	int tmp = a[1], pos = 0;
	sort(a + 1, a + n * m + 1, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == tmp) {
			pos = i;
			break;
		}
	}
	int c = (pos + n - 1) / n;
	int r = pos % n;
	if (r == 0) r = n;
	if (!(c & 1)) r = n - r + 1;
	printf("%d %d", c, r);
	return 0;
} 
