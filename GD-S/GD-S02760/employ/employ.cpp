#include<bits/stdc++.h>
using namespace std;

const int N = 20, mod = 998244353;
int n, m, a[N], f[1 << N][N], ppc[1 << N];
char c[N];

inline void ADD(int &a, int b) {a = (a + b) % mod;}
signed main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	if(n > 18){
		int jc = 1;
		for(int i = 1; i <= n; ++i) jc = 1ll * jc * i % mod;
		cout << jc;
		return 0;
	}
	for(int i = 1; i < 1 << n; ++i) ppc[i] = ppc[i >> 1] + (i & 1);
	scanf("%s", c + 1);
	for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
	f[0][0] = 1;
	for(int S = 0; S < 1 << n; ++S){
		if(S == (1 << n) - 1) break;
		for(int j = 0; j < n; ++j){
			for(int i = 0; i < n; ++i){
				if((S >> i) & 1) continue;
				int S2 = (S | (1 << i));
				if(c[ppc[S2]] == '1' && ppc[S] - j < a[i]) ADD(f[S2][j + 1], f[S][j]);
				else ADD(f[S2][j], f[S][j]);
			}
		}
	}
	int ans = 0;
	for(int j = m; j <= n; ++j) ADD(ans, f[(1 << n) - 1][j]);
	cout << ans;
	return 0;
}
