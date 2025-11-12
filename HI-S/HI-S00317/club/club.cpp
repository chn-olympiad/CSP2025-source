#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

long long n, ans=0;
struct node {
	int a, b, c;
} p[100005]; 

void dfs(int step, int ai, int bi, int ci, long long sum) {
	if (step > n) {
		ans = max(ans, sum);
		return;
	}
	if (ai+1 <= n/2) dfs(step+1, ai+1, bi, ci, sum+p[step+1].a);
	if (bi+1 <= n/2) dfs(step+1, ai, bi+1, ci, sum+p[step+1].b);
	if (ci+1 <= n/2) dfs(step+1, ai, bi, ci+1, sum+p[step+1].c);
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	int t; scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		ans=0;
		for (int i=1; i<=n; i++) {
			scanf("%d %d %d", &p[i].a, &p[i].b, &p[i].c);
		}
		
		dfs(0, 0, 0, 0, 0);
		
		printf("%lld\n", ans);
	}
	
	return 0;
}

