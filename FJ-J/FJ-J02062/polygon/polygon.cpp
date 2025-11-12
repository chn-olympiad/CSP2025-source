#include<bits/stdc++.h>
using namespace std;
#define LL long long
const LL N = 5e3+10;
const LL mod = 998244353;

LL n, ans=0;
LL a[N], b[N];
LL dp[N][N];

LL f(int x){
	LL sum1=1, sum2=1;
	for(int i=n; i>n-x; i--){
		sum1 = sum1 * i;
	}
	for(int i=1; i<=x; i++){
		sum2 = sum2 * i;
	}
	
	return (sum1 / sum2)%mod;
}

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	scanf("%lld", &n);
	for(int i=1; i<=n; i++){
		scanf("%lld", &a[i]);
		b[i] = b[i-1]+a[i];
	}
	
	sort(a+1, a+1+n);
	
	if(n <= 3){
		if(a[n]*2 < b[n]){
			ans++;
			printf("%lld", ans%mod);
		}else{
			printf("%lld", ans%mod);
		}
		return 0;
	}
	
	for(int i=3; i<=n; i++){
		ans += f(i) % mod;
		ans = ans % mod;
	}
	printf("%lld", ans%mod);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
