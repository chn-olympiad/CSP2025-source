#include<bits/stdc++.h>
using namespace std;
const int N = 5010, p = 998244353;
int n;
int a[N], maxx_a;
int c[N][N];
long long ans;
void solve1(int cnt, int sum, int maxx, int m){
	if(cnt == n + 1){
		if(m >= 3 && (sum > maxx * 2)){
			ans ++;
			ans %= p;
		}
		return ;
	}
	solve1(cnt + 1, sum, maxx, m);
	solve1(cnt + 1, sum + a[cnt], max(maxx, a[cnt]), m + 1);
}
void solve2(){
	for(int i = 3;i <= n;i ++){
		ans += c[n][n - i];
		ans %= p;
	}
	return ;
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1;i <= n;i ++){
		scanf("%d", &a[i]);
		maxx_a = max(maxx_a, a[i]);
	}
	maxx_a += 1;
	c[0][0] = 1;
	for(int i = 1;i <= n;i ++){
		c[i][0] = 1;
		for(int j = 1;j <= i;j ++){
			c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
			c[i][j] %= p;
		}
	}
	if(n <= 25){
		solve1(1, 0, 0, 0);
		cout << ans;
	}else if(maxx_a <= 1){
		solve2();
		cout << ans;
	}else cout << 0;
	return 0;
}
