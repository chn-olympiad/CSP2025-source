#include<bits/stdc++.h>
using namespace std;
int n, l[5005], sum, ans, c[5005][5005];
void dfs(int i, int ys, int ysg, int ws, int maxn){
	if(i == n + 1){
		if(ysg < 3 || ys <= maxn * 2)return;
		ans++;
		ans %= 998244353;
		return;
	}
	if(ys + ws <= maxn * 2)return;
	if(n - i + 1 + ysg < 3)return;
	dfs(i + 1, ys + l[i], ysg + 1, ws - l[i], max(maxn, l[i]));
	dfs(i + 1, ys, ysg, ws - l[i], maxn);
}
void init(){
	for(int i = 1; i <= n; i++){
		c[i][0] = 1;
		c[i][1] = i;
		for(int j = 2; j <= i; j++){
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
			c[i][j] %= 998244353;
		}
	}
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &l[i]);
		sum += l[i];
	}
	if(sum == n){
		init();
		for(int i = 3; i <= n; i++){
			ans += c[n][i];
			ans %= 998244353;
		}
	}
	else dfs(1, 0, 0, sum, -1);
	printf("%d", ans);
	return 0;
} 
