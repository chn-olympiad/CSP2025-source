#include <bits/stdc++.h>
using namespace std;
const int N = 505;
const int mod = 998244353;

int n, m, c[N] = {0};
char s[N];


int pre[N] = {0};
int fac[N] = {0};
	
int f[N][N] = {{0}};
int g[N][N] = {{0}};	
	
void add(int &x, int y) {
	x = (x + y >= mod) ? x + y - mod : x + y;
}
void sub(int &x, int y) {
	x = (x - y >= 0) ? x - y : x - y + mod;
}
	
void slv() {
	for (int i = 1; i <= n; i++) pre[c[i]]++;
	for (int i = 1; i <= n; i++) pre[i] += pre[i - 1];
	f[0][0] = 1;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		memcpy(g, f, sizeof g);
		memset(f, 0, sizeof f);
		cnt += (s[i] == '0');
		for (int j = 0; j < i; j++)
			for (int l = 0; l < i; l++)
				if (g[j][l]) {
					int v = g[j][l];
				//	printf("f[%d][%d][%d][%d] = %d\n", i - 1, j, k, l, g[j][k][l]);
					if (s[i] == '0') 
						add(f[j][l], v);
					else {
						//填 0
						add(f[j][l + 1], 1ll * v * max(pre[i - 1 - j] - l, 0) % mod); 
						//填 1，需要容斥 
						add(f[j + 1][l], v);//不考虑限制 
						sub(f[j + 1][l + 1], 1ll * v * max(pre[i - 1 - j] - l, 0) % mod);
					}
				}
	}
	fac[0] = 1;
	for (int i = 1; i <= n; i++) fac[i] = 1ll * i * fac[i - 1] % mod; 
	int ans = 0;
	for (int j = m; j <= n; j++)
		for (int l = 0; l <= n; l++) 
			add(ans, 1ll * fac[n - l] * f[j][l] % mod);			
	printf("%d\n", ans);
}


int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
	slv();
	return 0;
} 
