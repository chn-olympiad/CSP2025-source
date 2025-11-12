// ×ùÎ»(seat) 
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 105;
int n, m, h, l, pos, grade, a[N];
bool cmp(int x, int y) {
	return x > y;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf ("%d%d", &n, &m);
	for (int i = 1; i <= n * m; i++) scanf ("%d", &a[i]);
	grade = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == grade) {
			pos = i;
			break;
		}
	}
	if (pos % n != 0) l = pos / n + 1;
	else l = pos / n;
	if (l % 2 == 1) {
		if (pos % n != 0) h = pos % n;
		else h = n;
	} else {
		if (pos % n != 0) h = n + 1 - pos % n;
		else h = 1;
	}
	printf ("%d %d", l, h);
	return 0;
}
