#include<bits/stdc++.h>
using namespace std;

const int mod = 998244353;

const int N = 5010;

long long qpow(long long a, long long b){
	long long ans = 1;
	while(b){
		if(b & 1){
			ans = (ans * a) % mod;
		}
		b /= 2;
		a = (a * a) % mod;
	}
	return ans;
}

int n;
long long a[N];

long long jc[N], ijc[N];

void get(){
	jc[0] = 1;
	ijc[0] = 1;
	for(int i = 1;i <= n;i ++){
		jc[i] = (jc[i - 1] * i) % mod;
		ijc[i] = qpow(jc[i], mod - 2);
	}
	return ;
}

long long f[N][N];

long long get_sum1(int ii){
	long long ans = 0;
	for(int i = 1;i <= ii;i ++){
		long long an = 1;
		an = (an * jc[ii]) % mod;
		an = (an * ijc[i]) % mod;
		an = (an * ijc[ii - i]) % mod;
		ans = (ans + an) % mod;
	}
	return ans;
}

long long get_sum2(int ii){
	long long ans = 0;
	for(int i = 1;i <= a[ii];i ++){
		ans = (ans + f[ii - 1][i]) % mod; 
	}
	return ans;
}

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout); 
	scanf("%d", &n);
	for(int i = 1;i <= n;i ++){
		scanf("%lld", &a[i]); 
	}
	
	get();
	
	sort(a + 1, a + n + 1);
	
	long long ans = 0;
	for(int i = 0;i <= n;i ++)f[i][0] = 1;
	for(int i = 1;i <= n;i ++){
		if(i >= 3){
			long long sum1 = get_sum1(i - 1);	
			long long sum2 = get_sum2(i);
			long long xx = ((sum1 - sum2) % mod + mod) % mod;
			ans = (ans + xx) % mod;
		}
		
		for(int j = 1;j <= 5000;j ++){
			f[i][j] = f[i - 1][j];
			if(j >= a[i]){
				f[i][j] = (f[i][j] + f[i - 1][j - a[i]]) % mod;
			}
			
		}
	}
	
	printf("%lld\n", ans);
	
	return 0;
}