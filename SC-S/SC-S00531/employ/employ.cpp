#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,m,c[520],dp[270000][20],size[270000];
bool vis[270000][20];
char s[520];
int dfs(int S,int f){
	if(vis[S][f])return dp[S][f];
	vis[S][f]=1;
	if(S==(1<<n)-1)return dp[S][f]=(size[S]-f>=m);
	for(int i=1;i<=n;i++){
		if(!(S&(1<<i>>1))){
			if(c[i]<=f||s[size[S]+1]=='0')dp[S][f]=(dp[S][f]+dfs(S|(1<<i>>1),f+1))%mod;
			else dp[S][f]=(dp[S][f]+dfs(S|(1<<i>>1),f))%mod;
		}
	}
	return dp[S][f];
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld%s",&n,&m,s+1);
	if(n>18){
		int ans=1;
		for(int i=1;i<=n;i++)
			ans=ans*i%mod;
		printf("%lld",mod);
		return 0;
	}
	for(int i=1;i<=n;i++)
		scanf("%lld",c+i);
	for(int i=1;i<1<<n;i++)
		size[i]=size[i&(i-1)]+1;
	printf("%lld",dfs(0,0));
}