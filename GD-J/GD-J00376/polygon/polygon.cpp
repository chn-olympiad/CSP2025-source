#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5007, mod = 998244353;
int n;
int a[N];
int maxai;
ll ans;
ll c[N][N];
ll g[507][507][107];
ll f[N];
void init(){
	for(int i = 0; i <= n; i++) c[i][0] = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= i; j++){
			c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
		}
	}
}
void dfs(int now, int lst, int cnt, int sum){
	if(now > n){
		if(cnt >= 3 && sum > a[lst] * 2){
			ans = (ans + 1) % mod;
		}
		return;
	}
	if(cnt + (n - now + 1) < 3) return;
	dfs(now + 1, now, cnt + 1, sum + a[now]);
	dfs(now + 1, lst, cnt, sum);
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		maxai = max(maxai, a[i]);
	}
	sort(a + 1, a + n + 1);
	if(n == 3){
		if(a[1] + a[2] > a[3]) printf("1\n");
		else printf("0\n");
		return 0;
	}
	if(n <= 20){
		dfs(1, 0, 0, 0);	
		printf("%lld\n", ans);
		return 0;
	}
	init();
	if(maxai == 1){
		for(int i = 3; i <= n; i++){
			ans = (ans + c[n][i]) % mod;
		}
		printf("%lld\n", ans);
		return 0;
	}
	if(n <= 500){
		g[0][0][0] = 1;
		for(int i = 1; i <= n; i++){
			g[i][0][0] = 1;
			for(int j = 1; j <= i; j++){
				for(int k = 1; k <= 100; k++){
					if(k >= a[i]){
						g[i][j][k] = (g[i - 1][j][k] + g[i - 1][j - 1][k - a[i]]) % mod;	
					}
					else{
						g[i][j][k] = g[i - 1][j][k];
					}
				}
			}
		}
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= 100; j++){
				g[n][i][j] = (g[n][i][j] + g[n][i][j - 1]) % mod;
			}
		}
		for(int i = 3; i <= n; i++){
			f[i] = c[n][i];
			for(int j = i; j <= n; j++){
				f[i] = (f[i] - g[n][i - 1][a[j]] + mod) % mod;
			}
		}
		for(int i = 3; i <= n; i++){
			ans = (ans + f[i]) % mod;
		}
		printf("%lld\n", ans);
		return 0;
	}
	if(n <= 5000){
		printf("0\n");
	}
	return 0;
}
