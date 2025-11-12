#include <bits/stdc++.h>
using namespace std;

int n, m, k;

struct road {
	int v, u, w;
} a[1000010];
int b[10010]; // 经过此城市的道路 

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++)
		scanf("%d%d%d", &a[i].u, &a[i].v, &a[i].w);
	if (k == 0) {
		for (int i = 1; i <= m; i++) {
			b[a[i].u]++;
			b[a[i].v]++;
		} 
		int ans = 0, sum = 0;
		for (int i = 1; i <= n; i++) 
			if (b[i] == 1) {
				ans += b[i];
				++sum;
			}
		int c[1000010], l = 0;
		memset(c, 0, sizeof(c));
		for (int i = 1; i <= m; i++) 
			if (b[i] > 1)
				c[++l] = b[i];
		sort(c + 1, c + l + 1);
		for (int i = 1; i <= n - 1 - sum; i++)
			ans += c[i];
		printf("%d\n", ans);
	} 
	return 0;
}
