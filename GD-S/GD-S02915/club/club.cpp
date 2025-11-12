#include <cstdio>
#include <algorithm>
#define N (int)(1e5 + 10)
#define msg(Args...) fprintf(stderr, Args)
//#define LOCAL

using namespace std;

int a[N][5] = {}, n, c[5];

int dfs(int x) {
	if (x > n) return 0;
	
	int res = 0;
	
	for (int i = 1; i <= 3; i++)
		if (c[i] + 1 <= n >> 1) {
			c[i]++;
			res = max(res, dfs(x + 1) + a[x][i]);
			c[i]--;
		}
		
	return res;
}

int main() {
	#ifndef LOCAL
		freopen("club.in", "r", stdin);
		freopen("club.out", "w", stdout);
	#endif
	
	int t;
	scanf("%d", &t);
	
	while (t--) {
		scanf("%d", &n);
		
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= 3; j++)
				scanf("%d", &a[i][j]);
		
		c[1] = c[2] = c[3] = 0;
		
		printf("%d\n", dfs(1));
	}
	
	#ifndef LOCAL
		fclose(stdin);
		fclose(stdout);
	#endif
}
