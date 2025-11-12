#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,c[505],dp[262145][505],p = 998244353,ans;
char ch[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i = 1; i <= n; i++) scanf(" %c",&ch[i]);
	for(int i = 1; i <= n; i++) scanf("%lld",&c[i]);
	dp[0][0] = 1;
	for(int s = 0; s < (1<<n); s++){
		ll sum = 0,ss = s;
		while(ss){
			sum += ss%2;
			ss /= 2;
		} 
		for(int j = 1; j <= n; j++){
			if((s&(1<<(j-1))) == 0){
				for(int i = 0; i <= sum; i++){
					if(ch[sum+1] == '0' || c[j] <= (sum-i)){
						dp[s|(1<<(j-1))][i] += dp[s][i];
						if(dp[s|(1<<(j-1))][i] >= p){
							dp[s|(1<<(j-1))][i] -= p;
						} 
					}else{
						dp[s|(1<<(j-1))][i+1] += dp[s][i];
						if(dp[s|(1<<(j-1))][i+1] >= p){
							dp[s|(1<<(j-1))][i+1] -= p;
						}
					}
				}
			}
		}
	}
	for(int i = m; i <= n; i++) ans = (ans+dp[(1<<n)-1][i])%p;
	printf("%lld",ans);
	return 0;
}
/*
台南乐跟本不会这道题，看能不能拿个耳屎分把

          _____    ____
   /\    |        /    \
  /__\   |_____   |    |
 /    \  |        |    |
/      \ |        \____/  


*/
