#include<bits/stdc++.h>
using namespace std;
namespace Luo_ty{
	const int MAXN = 505, mod = 998244353;
	char s[MAXN];
	int c[MAXN];
	int f[1 << 18][20];
	void pls(int &x, int y){
		x += y;
		if(x >= mod) x -= mod;
	}
	int g[105][105][105], h[105][105][105], pre[MAXN], t[MAXN];
	int main(){
		int n, m;
		scanf("%d%d%s", &n, &m, s + 1);
		pre[0] = 1;
		for(int i = 1;i <= n;i++){
			scanf("%d", &c[i]);
			t[c[i]]++;
			pre[i] = 1ll * pre[i - 1] * i % mod;
		}
		if(n <= 18){
			f[0][0] = 1;
			int all = (1 << n);
			for(int t = 0;t < all;t++){
				int tmp = __builtin_popcount(t);
				//这次选第i个人 
				for(int i = 1;i <= n;i++){
					if((t >> (i - 1)) & 1) continue;
					//之前录取了j个 
					for(int j = 0;j <= tmp;j++){
						if(s[tmp + 1] == '0' || tmp - j >= c[i]) pls(f[t | (1 << (i - 1))][j], f[t][j]);
						else pls(f[t | (1 << (i - 1))][j + 1], f[t][j]); 
					}
				}
			}
			int ans = 0;
			for(int i = m;i <= n;i++) pls(ans, f[all - 1][i]);
			printf("%d", ans);
//			while(1);
			return 0;
		} 
		for(int i = 1;i <= n;i++) g[0][i][0] = 1;
		//用c为i的人 
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				for(int k = 0;k <= j;k++){
					h[j][k][0] = g[i - 1][j][k];
				}
			}
			//用了cnt个
			for(int cnt = 1;cnt <= t[i];cnt++){
				//第j个位置
				for(int j = 1;j <= n;j++){
					//录取了k个
					for(int k = 0;k <= j;k++){
						//如果不放 
						h[j][k][cnt] = h[j - 1][k][cnt];
						//如果放
						if(s[j] == '0' || j - 1 - k >= i) pls(h[j][k][cnt], h[j - 1][k][cnt - 1]);
						else if(k) pls(h[j][k][cnt], h[j - 1][k - 1][cnt - 1]);
					}
				}
			}
			for(int cnt = 1;cnt <= t[i];cnt++){
				//第j个位置
				for(int j = 1;j <= n;j++){
					//录取了k个
					for(int k = 0;k <= j;k++){
						pls(g[i][j][k], h[j][k][cnt]);
					}
				}
			}
		}
		int ans = 0;
		for(int i = m;i <= n;i++) pls(ans, g[n][n][i]);
		printf("%d", ans);
//		while(1);
		return 0;
	}
}
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	return Luo_ty::main();
}//Chelsea 2012
//63MB
/*
3 2
101
1 1 2

10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
