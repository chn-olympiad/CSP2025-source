#include<bits/stdc++.h>
using namespace std;
const int max_n = 1e5 + 5;

int t, n, ans;
int A[max_n][4], s[max_n];

void dfs(int x, int y, int a, int b, int c) {
	if (a > n / 2 || b > n / 2 || c > n / 2)
		return ;
	
	if (y + s[n] - s[x - 1] <= ans)
		return ;
	
	if (x > n) {
		ans = max(ans, y);
		return ;
	}
	
	if (a < n / 2)
		dfs(x + 1, y + A[x][1], a + 1, b, c);
		
	if (b < n / 2)
		dfs(x + 1, y + A[x][2], a, b + 1, c);
		
	if (c < n / 2)
		dfs(x + 1, y + A[x][3], a, b, c + 1);
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	scanf("%d", &t);
	
	while (t--) {
		ans = 0;
		
		scanf("%d", &n);
		
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				scanf("%d", &A[i][j]);
				s[i] = max(s[i], A[i][j]);
			}
			s[i] += s[i - 1];
		}
		
		dfs(1, 0, 0, 0, 0);
		
		printf("%d\n", ans);
	}
	
	return 0;
}