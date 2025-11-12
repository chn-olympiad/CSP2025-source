#include <bits/stdc++.h>
using namespace std;
int n, m;
struct node {int sum, num;}a[101];
bool cmp(node x, node y) {return x.sum > y.sum;}
signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n * m; i ++) scanf("%d", &a[i].sum), a[i].num = i;
	sort(a + 1, a + n * m + 1, cmp);
	int res = 0;
	for(int i = 1; i <= n * m; i ++) if(a[i].num == 1) {res = i; break;}
	int x = (res + n - 1) / n, y = (res - 1) % n + 1;
	if(x % 2 == 0) printf("%d %d", x, m + 1 - y);
	else printf("%d %d", x, y);
	return 0;
}
