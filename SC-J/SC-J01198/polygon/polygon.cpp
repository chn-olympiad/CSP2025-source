#include<bits/stdc++.h>
//#undef STDIO
const int N = 5010, MOD = 998244353;
int n, a[N], f[N], ans;
int qp(int x, int y){
	int ans = 1;
	while(y){
		if(y & 1) ans = 1ll * x * ans % MOD;
		x = 1ll * x * x % MOD;
		y >>= 1;
	}
	return ans;
}
int main(){
#ifndef STDIO
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
#endif
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	std::sort(a + 1, a + n + 1);
	f[0] = 1;
	for(int i = 1; i <= n; i++){
		int sum = 0;
		for(int j = 0; j <= a[i]; j++){
			sum += f[j];
			sum %= MOD;
		}
		ans += (qp(2, i - 1) - sum + MOD) % MOD;
		ans %= MOD;
		for(int j = a[n]; j >= 0; j--){
			if(j >= a[i]){
				f[j] += f[j - a[i]];
				f[j] %= MOD;
			}
		}
	}
	printf("%d\n", ans);
	fflush(stdout);
	fclose(stdin);
	fclose(stdout);
	return 0;
}