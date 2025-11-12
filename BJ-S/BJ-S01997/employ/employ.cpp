#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MX = 505,MOD = 998244353;
int ksm(int a,int b){
	int ret = 1;
	while(b){
		if(b & 1)ret = 1ll * ret * a % MOD;
		a = 1ll * a * a % MOD;
		b >>= 1;
	}
	return ret;
}
int f[MX][MX][MX],c[MX],sum[MX];
int fac[MX],ifac[MX];
char s[MX];
void add(int &x,int y){
	x = (x + y) % MOD;
}
int FA(int n,int m){
	return 1ll * fac[n] * ifac[n - m] % MOD;
}
int FC(int n,int m){
	return 1ll * fac[n] * ifac[n - m] % MOD * ifac[m] % MOD;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;cin >> n >> m;
	cin >> s + 1;
	for(int i = 1;i <= n;i++)cin >> c[i];
	sort(c + 1,c + 1 + n);
	for(int i = 0;i <= n;i++)
		for(int j = 1;j <= n;j++)if(i < c[j])sum[i]++;
	fac[0] = ifac[0] = 1;
	for(int i = 1;i <= n;i++)fac[i] = 1ll * fac[i - 1] * i % MOD;
	ifac[n] = ksm(fac[n],MOD - 2);
	for(int i = n - 1;i >= 1;i--)ifac[i] = 1ll * ifac[i + 1] * (i + 1) % MOD;
	f[0][0][0] = 1;
	for(int i = 0;i < n;i++)
		for(int j = 0;j <= i;j++)
			for(int k = 0;k <= i;k++)
				if(f[i][j][k] && i - j <= n - m){
					int A = n - sum[i - j] - (i - k),B = sum[i - j] - k;
					if(s[i + 1] == '0'){
						if(A > 0){
							for(int t = 0;t <= min(sum[i - j] - sum[i - j + 1],k);t++)
								if(sum[i - j + 1] >= k - t)add(f[i + 1][j][k - t],1ll * f[i][j][k] * A % MOD * FC(sum[i - j] - sum[i - j + 1],t) % MOD * FA(k,t) % MOD);
						}
						if(B > 0){
							for(int t = 0;t <= min(sum[i - j] - sum[i - j + 1],k + 1);t++)
								if(sum[i - j + 1] >= k + 1 - t)add(f[i + 1][j][k + 1 - t],1ll * f[i][j][k] * FC(sum[i - j] - sum[i - j + 1],t) % MOD * FA(k + 1,t) % MOD);
						}
					}
					else{
						if(A > 0){
							for(int t = 0;t <= min(sum[i - j] - sum[i - j + 1],k);t++)
								if(sum[i - j + 1] >= k - t){
									add(f[i + 1][j][k - t],1ll * f[i][j][k] * A % MOD * FC(sum[i - j] - sum[i - j + 1],t) % MOD * FA(k,t) % MOD);
								}
						}
						if(B > 0){
							add(f[i + 1][j + 1][k + 1],f[i][j][k]);
						}
					}
				}
	int ans = 0;
	for(int j = m;j <= n;j++)add(ans,1ll * f[n][j][sum[n - j]] * fac[sum[n - j]] % MOD);
	cout << ans << '\n';
	return 0;	
}