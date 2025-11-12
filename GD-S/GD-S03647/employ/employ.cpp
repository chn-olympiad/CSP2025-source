#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;
const int mxn = 505;
int n, m, c[mxn], a[mxn], sa[mxn], C[mxn << 1][mxn << 1], fac[mxn << 1], ifac[mxn << 1];
char s[mxn];
void add(int &x,int y){x+=y;if(x>=mod)x-=mod;}
int qmd(int x){return x<mod?x:x-mod;}
int qpw(int x,int y=mod-2){int res=1;while(y>0){if(y&1)res=(ll)res*x%mod;x=(ll)x*x%mod;y>>=1;}return res;}
namespace Sub0{
	const int mxN = (1 << 18) + 10;
	int N, f[mxN][20], pc[mxN];
	void solve(){
		memset(f, 0, sizeof(f));
		int i, j, p;
		N = 1 << n;
		for(i = 1, pc[0] = 0; i < N; i++){
			pc[i] = pc[i >> 1] + (i & 1);
		}
		f[0][0] = 1;
		for(i = 0; i < N; i++){
			for(j = 0; j <= pc[i]; j++){
				for(p = 0; p < n; p++){
					if(i >> p & 1 ^ 1){
						add(f[i | 1 << p][j + (s[pc[i] + 1] == '0' || j >= c[p + 1] ? 1 : 0)], f[i][j]);
					}
				}
//				printf("%d %d %d\n", i, j, f[i][j]);
			}
		}
		int x = 0;
		for(i = 0; i <= n - m; i++){
			add(x, f[N - 1][i]);
		}
		printf("%d", x);
	}
}
void solve(){
	int i, j;
	scanf("%d%d %s", &n, &m, s + 1);
	for(i = 0; i <= n; i++) a[i] = 0;
	for(i = 1; i <= n; i++){
		scanf("%d", &j);
		c[i] = j;
		a[j]++;
	}
	sa[0] = a[0];
	for(i = 1; i <= n; i++) sa[i] = sa[i - 1] + a[i];
	Sub0::solve();
//	if(n <= 18){
//		Sub0::solve(); return;
//	}
}
void init(){
	n = 1000;
	int i, j;
	for(i = 1, fac[0] = 1; i <= n; i++) fac[i] = (ll)fac[i - 1] * i % mod;
	for(i = n, ifac[n] = qpw(fac[n]); i > 0; i--) ifac[i - 1] = (ll)ifac[i] * i % mod;
	for(i = 0; i <= n; i++){
		C[i][0] = C[i][i] = 1;
		for(j = 1; j < i; j++){
			C[i][j] = qmd(C[i - 1][j - 1] + C[i - 1][j]);
		}
	}
}
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	init();
	int t = 1;
	while(t--) solve();
	return 0;
}
