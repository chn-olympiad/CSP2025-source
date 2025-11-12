#include <bits/stdc++.h>
using namespace std;

int a[5005], n;
long long C[5005][5005], mod = 998244353, ans;

void dfs(int id, int sum, int mx, int cnt){
	if(id == n+1){
		if(cnt >= 3 && sum > mx * 2) ans ++, ans %= mod;
		return;
	}
	dfs(id+1, sum+a[id], max(mx, a[id]), cnt+1);
	dfs(id+1, sum, mx, cnt);
}

void ok1(){
	C[1][0] = C[1][1] = 1ll;
	for(int i = 2; i <= n; i ++){
		C[i][0] = C[i][i] = 1ll;
		for(int j = 1; j < i; j ++)
			C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod;
	}
	for(int i = 3; i <= n; i ++)
		ans = (ans + C[n][i]) % mod;
	printf("%lld", ans);
}

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int maxn = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]);
		maxn = max(maxn, a[i]);
	}
	if(maxn == 1) ok1();
	else{
		dfs(1, 0, 0, 0);
		printf("%lld", ans);
	}
	return 0;
}
