#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5009, Q = 998244353;
ll f[N][N], fac[N], infac[N], a[N], pow2[N];
ll qpow(ll a, ll b){
	ll ans = 1;
	while(b){
		if(b & 1) ans = ans * a % Q;
		a = a * a % Q;
		b >>= 1;
	}
	return ans;
}
ll C(int n, int m){
	if(n < m) return 0;
	return fac[n] * infac[n - m] % Q * infac[m] % Q;
}
struct Node{
	ll cnt, val;
}p[N];
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	for(int i = 0; i <= 5000; i++) f[0][i] = 1;
	for(int i = 1; i <= n; i++){
		f[i][0] = 1;
		for(int j = 1; j <= 5000; j++){
			f[i][j] = f[i - 1][j];
			if(j >= a[i]) f[i][j] = (f[i][j] + f[i - 1][j - a[i]]) % Q;
		}
	}
	fac[0] = pow2[0] = 1;
	for(int i = 1; i <= n; i++){
		fac[i] = fac[i - 1] * i % Q;
		pow2[i] = pow2[i - 1] * 2 % Q;
	}
	infac[n] = qpow(fac[n], Q - 2);
	for(int i = n - 1; i >= 0; i--){
		infac[i] = infac[i + 1] * (i + 1) % Q;
	}
	int cntp = 0, las = 0;
	for(int i = 1; i <= n; i++){
		if(a[i] != a[i - 1]){
			if(i != 1) {
				p[++cntp] = {i - 1 - las, a[i - 1]};
			}
			las = i - 1;
		}
	}
	p[++cntp] = {n - las, a[n]};
	ll ans = 0;
	for(int i = 3; i <= p[1].cnt; i++) ans = (ans + C(p[1].cnt, i)) % Q;
	int cnt1 = p[1].cnt;
	for(int i = 2; i <= cntp; i++){
		ll sum = 0;
		ans = (ans + (pow2[cnt1] - 1) * C(p[i].cnt, 2) % Q) % Q;
		for(int j = 3; j <= p[i].cnt; j++){
			sum = (sum + C(p[i].cnt, j)) % Q;
		}
		ans = (ans + pow2[cnt1] * sum % Q) % Q;
		ans = (ans + ((pow2[cnt1] - f[cnt1][p[i].val]) * p[i].cnt % Q + Q) % Q) % Q;
		cnt1 += p[i].cnt;
	}
	printf("%lld\n", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}