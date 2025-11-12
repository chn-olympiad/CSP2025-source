#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int s = 0, f = 1;char ch = getchar();
	while(!isdigit(ch)){if(ch == '-')f = -1;ch = getchar();}
	while(isdigit(ch)){s = s * 10 + ch - '0';ch = getchar();}
	return s * f;
}
const int MAXN = 5e2 + 5, MR = 1 << 18, MOD = 998244353;
int n, m, s[MAXN], a[MAXN], f[MR][19], num[MAXN];
signed main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	n = read(), m = read();
	if(n == m){
		puts("0");
		return 0;
	}
	for(int i = 1;i <= n;i ++)scanf("%1d", &s[i]);
	for(int i = 1;i <= n;i ++)a[i] = read();
	if(n <= 18){
		f[0][0] = 1;
		for(int i = 0;i < (1 << n);i ++){
			int len = 0, x = i;
			while(x){
				len ++;
				x -= (x & -x);
			}
			for(int j = 1;j <= n;j ++){
				if((1 << j - 1) & i)continue;
				for(int k = 0;k <= n;k ++){
					if(!s[len + 1] || a[j] <= k){
						f[(1 << j - 1) | i][k + 1] += f[i][k];
						f[(1 << j - 1) | i][k + 1] %= MOD;
					}
					else{
						f[(1 << j - 1) | i][k] += f[i][k];
						f[(1 << j - 1) | i][k] %= MOD;
					}
				}
			}
//			for(int j = 0;j <= n;j ++)
//				printf("%lld %lld %lld\n", i, j, f[i][j]);
		}
		int ans = 0;
		for(int i = 0;i <= n - m;i ++)ans = (ans + f[(1 << n) - 1][i]) % MOD;
		printf("%lld\n", ans);
		return 0;
	}
	if(m == 1){
		int ans = 1, res = 1;
		for(int i = 1;i <= n;i ++){
			res = res * i % MOD;
			num[a[i] + 1] ++;
			if(a[i] == n)ans = 0;
		}
		int tmp = 0;
		for(int i = n;i >= 1;i --){
			tmp ++;
			for(int j = 1;j <= num[i];j ++)ans = ans * tmp % MOD, tmp --;
		}
		printf("%lld\n", ((res - ans) % MOD + MOD) % MOD);
	}
	return 0;
}

