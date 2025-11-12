#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 5e3;
const ll MOD = 998244353ll;
ll ksm(ll x,int p) {
	ll ans = 1ll;
	while (p) {
		if (p & 1) ans = ans * x % MOD;
		x = x * x % MOD;
		p >>= 1;
	}
	return ans;
}
int n;
int a[maxn + 5];
int mxa = 0;
ll f[maxn + 5][maxn + 5];
ll ans = 0ll;
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1;i <= n;i ++) {
		scanf("%d",&a[i]);
		mxa = max(mxa,a[i]);
	}
	sort(a + 1,a + n + 1);
	ans = ksm(2ll,n) % MOD; // 总答案(含m<=2)
	for (int i = 0;i <= mxa;i ++) f[0][i] = 1ll;
//	printf("ans = %lld\n",ans);
	ans = (ans - 2ll + MOD) % MOD; // 只选0个/1个的答案
	for (int i = 1;i <= n - 1;i ++) { // a[i]为最大值且一定选啊a[i]
		int mxV = a[i + 1];
		for (int j = 0;j <= mxa;j ++) { // 总不合法答案(一定含m<=2)
			f[i][j] = (f[i][j] + f[i - 1][j]) % MOD;
			if (j >= a[i]) f[i][j] = (f[i][j] + f[i - 1][j - a[i]]) % MOD;
		}
//		printf("[1,%d]: %lld,mxV = %d\n",i,f[i][mxV],mxV);
		ans = (ans - f[i][mxV] + MOD) % MOD;
	}
	printf("%lld",ans);
	return 0;
}
/*
5
1 2 3 4 5
*/