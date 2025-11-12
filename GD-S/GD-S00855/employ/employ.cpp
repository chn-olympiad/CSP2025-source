//T4(24)
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define lowbit(x) ((x)&(-(x)))
using namespace std;
const int N = 510, mod = 998244353;

int n, m, sp[N], C[N], del;//del为C[i]=0的人数 
bool equ = true;
ll ans = 0;//ans默认为0 

int g[(1 << 18) + 10];//g[s]表示s中有多少人 
ll f[(1 << 18) + 10][20];//f[s][i]表示考察完了s，有i人成功录取的方案数 

int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++){
		scanf("%1d", &sp[i]);
		if (!sp[i])
			equ = false;
	}
	for (int i = 1; i <= n; i++)
		scanf("%d", &C[i]), del += (C[i] == 0);
	if (m > n - del){
		printf("0\n");
		return 0;
	}
	if (m == n){
		if (equ && !del){
			ans = 1;
			for (int i = 2; i <= n; i++)
				(ans *= i) %= mod;
		}
	}
	else if (n <= 18){
		//初值 
		f[0][0] = 1;
		//dp
		for (int s = 1; s < (1 << n); s++){
			g[s] = g[s - lowbit(s)] + 1;
			for (int k = 0; k < n; k++)//对应的要求是1:sp[g[s]]=1，2:不过人数 g[t] - i < C[k+1] 
				if ((s >> k) & 1){
					int t = s - (1 << k);
					for (int i = 0; i <= g[t]; i++){
						if (sp[g[s]] && g[t] - i < C[k + 1])
							f[s][i + 1] += f[t][i];
						else
							f[s][i] += f[t][i];
					}
				}
			for (int i = 0; i <= g[s]; i++)
				f[s][i] %= mod;
		}
		//答案 
		for (int i = m; i <= n; i++)
			(ans += f[(1 << n) - 1][i]) %= mod;
	}
	printf("%lld\n", ans);
	return 0;
}
