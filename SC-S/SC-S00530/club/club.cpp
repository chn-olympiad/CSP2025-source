#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;

int ans = 0;
int t[10];
int a[maxn][5];
int b[maxn];
int n;
void dfs(int u, int res) {
	if (u > n) {
		ans = max(ans, res);
		return ;
	}
	for (int i = 1;i <= 3;i ++) {
		if (t[i] < n / 2) {
			t[i] ++;
			dfs(u + 1, res + a[u][i]);
			t[i] --;
		}
	}
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;scanf("%d", &T);
	while (T --){
		scanf("%d", &n);
		ans = 0;
		for (int i = 1;i <= n;i ++) 
			for (int j = 1;j <= 3;j ++) 
				scanf("%d", &a[i][j]);
		if (n <= 10) {
			dfs(1, 0);
			printf("%d\n", ans);
		} else if (a[1][2] == 0 && a[1][3] == 0){
			for (int i = 1;i <= n;i ++) b[i] = a[i][1];
			sort(b + 1, b + n + 1);
			for (int i = n;i > n / 2;i --) ans += b[i];
			printf("%d\n", ans);
		} else {
			int ans = 0;
			for (int i = 1;i <= n;i ++) {
				ans += max({a[i][1], a[i][2], a[i][3]});
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}