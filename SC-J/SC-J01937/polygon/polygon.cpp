#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
int n;
const int maxn = 1e4+5;
int a[maxn];
int xz[maxn], cnt;
int sum;
void dfs(int mg, int cd, int gs,int maxx) { //当前木棍，长度总和，木棍个数
	if (gs >= 3) {
		if (cd >maxx* 2) {
			sum++;
			sum%=mod;

		}
	}
	for (int i = mg + 1; i <= n; ++i) {
		
		xz[gs+1] = a[i];
		if(a[i]>maxx){
			dfs(i, cd + a[i], gs + 1,a[i]);
		}else{
			dfs(i,cd+a[i],gs+1,maxx);
		}
		
	}
}
signed main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
		
	}
	dfs(0, 0, 0,0);
	printf("%lld", sum);
	return 0;
}
/*
*/

