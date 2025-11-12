#include <stdio.h>
#include <algorithm>
#define int long long
using namespace std;
int n, m;
struct node {
	int index, score;
} a[125];
bool cmp(node a, node b) {
	return a.score > b.score;
}
signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%lld %lld", &n, &m);
	for (int i = 1; i <= n * m; i++) {
		scanf("%lld", &a[i].score);
		a[i].index = i;
	}
	sort(a + 1, a + n * m + 1, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (a[i].index == 1) 
		{
			int x, y;
			x = (i + n - 1) / n;
			y = i % n;
			if (y == 0) y = n;
			if (x % 2 == 0) {
				y = n - y + 1; 
			} 
			printf("%lld %lld", x, y);
			return 0;
		}
	}
	return 0;
}