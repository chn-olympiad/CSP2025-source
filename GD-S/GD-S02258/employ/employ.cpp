#include<bits/stdc++.h>
using namespace std;
#define N 505
#define int long long
const int mod = 998244353;
int n,m,i,j,ans,c[N],qs[N],g[300005],f[20][300005];
char s[N];
int dfs(int cnt,int S){
	if(S==(1<<n)-1){
		if(cnt>=m) return 1;
		return 0;
	}
	if(f[cnt][S]!=-1) return f[cnt][S];
	int res=0;
	for(int i=1;i<=n;i++){
		if(S&(1<<(i-1))) continue;
		if(g[S]-cnt>=c[i] || s[g[S]+1]=='0') res=(res+dfs(cnt,S^(1<<(i-1))))%mod;
		else res=(res+dfs(cnt+1,S^(1<<(i-1))))%mod;
	}
	return f[cnt][S]=res;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	scanf("%s",s+1);
	for(i=1;i<=n;i++) scanf("%lld",&c[i]);
	if(n<=18){
		memset(f,-1,sizeof(f));
		for(i=0;i<(1<<n);i++) g[i]=__builtin_popcount(i);
		printf("%lld\n",dfs(0,0));
	}
	else puts("0");
	return 0;
}
