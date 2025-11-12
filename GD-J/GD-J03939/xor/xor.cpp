#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 1500005

int n, a[N], i, j, k, s, f[N], dp[N], t;
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for(i=1; i<=n; i++){
		scanf("%d", a+i);
		s ^= a[i];	//前缀异或和 
		t = k ^ s;	//需要的值 
		if(f[t] || !t)	dp[i] = dp[f[t]]+1;
		f[s] = i;
		dp[i] = std::max(dp[i], dp[i-1]);
	}
	printf("%d", dp[n]);
	fclose(stdin), fclose(stdout);
	return 0;
}
