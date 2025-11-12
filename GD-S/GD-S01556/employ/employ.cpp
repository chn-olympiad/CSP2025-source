#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=25, M=(1<<18)+5, Mod=998244353;
int n, m, c[505];
bool s[505];
ll dp[M][N];
inline int popcnt(int x){
	int cnt = 0;
	while(x){
		++cnt; x&=(x-1);
	}
	return cnt;
}
inline void mod(ll x){
	if(x >= Mod) x -= Mod;
}
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	bool flag = true;
	scanf("%d%d", &n, &m);
	for(int i=1,x; i<=n; ++i){
		scanf("%1d", &x);
		s[i] = x;
		flag &= s[i];
	}
	for(int i=1; i<=n; ++i) scanf("%d", &c[i]);

	ll ans = 0;
	if(flag){
		int cnt = 0;
		for(int i=1; i<=n; ++i) cnt += (c[i]==0);
		if(cnt > n-m) printf("0\n");
		else{
			ans = 1ll;
			for(int i=1; i<=n; ++i) ans = ans*i%Mod;
			printf("%lld\n", ans);
		}
		return 0;
	}
	dp[0][0] = 1;
	int maxn = (1<<n)-1;
	for(int st=0,i; st<maxn; ++st){
		i = popcnt(st);
		for(int j=i; j>=0; --j){
			for(int k=1; k<=n; ++k){
				if((st>>k-1) & 1) continue;
				if(c[k]>j && s[i+1]){
					dp[st^(1<<k-1)][j] += dp[st][j];
					mod(dp[st^(1<<k-1)][j]);
				}else{
					dp[st^(1<<k-1)][j+1] += dp[st][j];
					mod(dp[st^(1<<k-1)][j+1]);
				}
			}
//			printf("%lld ", dp[st][j]);
		}
//		putchar('\n');
	}
	for(int i=0; i<=n-m; ++i){
//		printf("%lld ", dp[maxn][i]);
		ans += dp[maxn][i];
		mod(ans);
	}
	printf("%lld\n", ans);
	return 0;
}
