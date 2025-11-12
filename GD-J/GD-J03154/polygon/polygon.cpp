# include <bits/stdc++.h>
using namespace std;
int n, a[5010], ans, vis[5010];
void dfs(int now, int sum, int max_, int cnt){
	if(cnt >= 3 && sum > max_ * 2){
		ans ++;
	}
	for(int i = now; i <= n; i ++){
		if(vis[i] == 1)continue ;
		vis[i] = 1;
		dfs(i, sum + a[i], max(max_, a[i]), cnt + 1);
		vis[i] = 0; 
	}
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i ++)cin >> a[i];
	dfs(1, 0, 0, 0);
	cout << ans;
}
