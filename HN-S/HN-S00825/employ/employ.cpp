#include<bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int n, m, k, res, ans, c[505], d[505], t[505], p[505], f[505], fac[505], inv[505];
char ch[505];
int ksm(int a, int b){
	int s = 1;
	while(b){
		if(b & 1){
			s = s * a % mod;
		}
		a = a * a % mod, b >>= 1;
	}
	return s;
}
void init(){
	fac[0] = 1;
	for(int i = 1; i <= 500; i++){
		fac[i] = fac[i - 1] * i % mod;
		inv[i] = ksm(fac[i], mod - 2);
	}
}
int C(int x, int y){
	if(x < 0 || y < 0 || x < y){
		return 0;
	}
	return fac[x] * inv[x - y] % mod * inv[y] % mod;
}
void dfs(int step){
	if(step > n){
		int cnt = 0;
		for(int i = 1; i <= n; i++){
			t[i] = p[i];
			if(d[i - 1] < c[t[i]] && ch[i] == '1'){
				cnt++;
			}
		}
		ans = (ans + (cnt >= m)) % mod;
		return;
	}
	for(int i = 1; i <= n; i++){
		if(!f[i]){
			f[i] = 1, p[step] = i;
			dfs(step + 1);
			f[i] = 0;
		}
	}
}
signed main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	init();
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> ch[i];
		d[i] = d[i - 1] + (ch[i] - '0');
	}
	for(int i = 1; i <= n; i++){
		cin >> c[i];
	}
	dfs(1);
	cout << ans;
	return 0;
}

