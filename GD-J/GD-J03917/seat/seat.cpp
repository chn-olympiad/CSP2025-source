#include <cstdio>
#include <algorithm>
using namespace std;

int n, m, a[101], pm, b[15][15];
bool cmp(const int& x, const int& y) {
	return x > y;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n * m; i++)
		scanf("%d", &a[i]);
	int R = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	for (int i = 1; i <= n * m; i++)
		if (a[i] == R) {
			pm = i;
			break;
		}
	int nw = 0;
	for (int i = 1; i <= n; i++)
		if (i % 2 == 1)
			for (int j = 1; j <= m; j++)
				b[i][j] = ++nw;
		else
			for (int j = m; j >= 1; j--)
				b[i][j] = ++nw;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (b[i][j] == pm) {
				printf("%d %d\n", i, j);
				return 0;
			}
	return 0;
}
