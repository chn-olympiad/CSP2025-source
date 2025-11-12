#include<bits/stdc++.h>

using namespace std;
const int N = 1e6 + 5; 

int t, n;
int a[N][4], ans, sum[N];

void dfs(int x, int dep) {
	if (dep == n + 1){
		ans = max(x, ans);
		return ;
	}
	for (int i = 1; i <= 3; i ++) 
		if (sum[i] < n / 2) {
			sum[i] ++;
			dfs(x + a[dep][i], dep + 1);
			sum[i] --;
	}
	return ;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++)
			scanf("%d%d%d", &a[i][1], &a[i][2], &a[i][3]);
		ans = 0;
		dfs(0, 1);
		
		printf("%d\n", ans);
	}
	return 0; 
} 
