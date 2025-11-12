#include<bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
int n, m, c[25];
bool a[25];
long long f[300005][25], ans;
int ct(int s){
	int res = 0;
	while(s){
		if(s & 1)res++;
		s >>= 1;
	}
	return res;
}
bool ff = 1;
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n;i++){
		char s;
		cin >> s;
		a[i] = (s == '1' ? 1 : 0);
		ff &= a[i];
	}
	int cc = 0;
	for(int i = 1;i <= n;i++){
		scanf("%d", &c[i]);
		if(c[i] == 0)cc++;
	}
	if(n > 18){
		printf("0");return 0;
	}
	f[0][0] = 1;
	for(int s = 0;s < (1 << n);s++){
		int t = ct(s) + 1;
		for(int j = 0;j <= m;j++){
			for(int i = 1;i <= n;i++){
				if(s & (1 << (i - 1)))continue;
				int tt = (j >= c[i]) || (a[t] == 0);
				int to = s | (1 << (i - 1));
				f[to][j + tt] = (f[to][j + tt] + f[s][j]) % mod;
			}
		}
	}
	for(int i = 0;i <= n - m;i++){
		ans = (ans + f[(1 << n) - 1][i]) % mod;
	}
	printf("%lld", ans);
	return 0;
}