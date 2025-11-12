#include <bits/stdc++.h>
using namespace std;

int n, m;
pair <int, int> a[110];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
//	freopen("seat3.in", "r", stdin);
//	freopen("t.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1 ; i <= n * m ; i++)
		scanf("%d", &a[i].first), a[i].second = i;
	sort(a + 1, a + n * m + 1);
	int k = 0;
	for (int i = 1 ; i <= n * m ; i++)
		if (a[i].second == 1) {
			k = n * m - i + 1;
			break;
		}
	int c = (k - 1) / n + 1;
	if (c & 1) printf("%d %d\n", c, k - (c - 1) * n);
	else printf("%d %d\n", c, n - (k - (c - 1) * n) + 1);
	return 0;
}
