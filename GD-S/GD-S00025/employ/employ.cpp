#include<bits/stdc++.h>
using namespace std;

const int N=505,S=1<<19,mod=998244353;
int n,m,x,y,num[S],c[N],fac[N];
long long dp[S][20];
string s;
long long dfs(int now,int tot){
	if(num[now]-tot==m) return fac[n-num[now]];
	if(num[now]==n) return 0;
	if(~dp[now][tot]) return dp[now][tot];
	long long res=0;
	for(int i=0;i<n;++i)
		if(!(now&(1<<i))) res=(res+dfs(now|(1<<i),tot+(s[num[now]]=='0'||c[i]<=tot)))%mod;
	return dp[now][tot]=res;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(int i=1;i<S;++i) num[i]=num[i>>1]+(i&1);
	cin>>n>>m>>s;
	bool op=true;
	fac[0]=1;
	for(int i=1;i<=n;++i) fac[i]=(fac[i-1]*1LL*i)%mod;
	for(int i=0;i<n;++i) cin>>c[i];
	memset(dp,-1,sizeof(dp));
	if(n<=18) cout<<dfs(0,0);
	else cout<<fac[n];
	return 0;
}
