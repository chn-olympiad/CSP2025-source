#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int n, m, tot, a[105], r, pos, col, row;
bool cmp(int a, int b) {return a > b;}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d %d", &n, &m);
	tot = n * m;
	for (int i = 1; i <= tot; i++) scanf("%d", &a[i]);
	r = a[1];
	sort(a+1, a+tot+1, cmp);
	for (int i = 1; i <= tot; i++) if (a[i] == r) {pos = i; break;}
	col = (pos % n)? pos / n + 1 : pos / n;
	row = (col & 1)? pos % n : (n - (pos % n) + 1);
	if (!row) row = n;
	else if (row > n) row = 1;
	printf("%d %d", col, row);
	fclose(stdin); fclose(stdout);
	return 0;
}
