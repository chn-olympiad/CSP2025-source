#include <bits/stdc++.h>
using namespace std;
int n,m,c[505]; char s[505];
int dp[300010][20];
void chk(int& x ,int y) {x = min(x,y);}
int main() {
	freopen("employ.in","r",stdin); freopen("employ.out","w",stdout);
	scanf("%d%d%s",&n,&m,s+1);
	for(int i = 1; i <= n; i++) scanf("%d",&c[i]);
	dp[0][0] = 1;
	for(int msk = 0; msk < (1<<n)-1; msk++) {
		int x = __builtin_popcount(msk);
		for(int i = 0; i <= x; i++)
		for(int j = 1; j <= n; j++) {
			if(msk>>(j-1)&1) continue;
			int add = (s[x+1]=='1'&&c[j]>x-i);
			(dp[msk|(1<<(j-1))][i+add] += dp[msk][i]) %= 998244353;
		}
	}
	int ans = 0;
	for(int i = m; i <= n; i++) (ans += dp[(1<<n)-1][i]) %= 998244353;
	cout << ans;
	return 0;
}
//may god bless and help me.
