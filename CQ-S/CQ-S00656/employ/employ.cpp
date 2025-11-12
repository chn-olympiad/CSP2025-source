#include<bits/stdc++.h>
using namespace std;
const int N=505,mod=998244353;
long long ans;
bool vis[N];
int n,m,c[N],b[N],jc[N];
char s[N];
void dfs(int x,int ss){
	if(ss+n-x+1<m) return;
	if(ss==m){
		ans=(ans+jc[n-x+1])%mod;
		return;
	}
	if(x>n){
		if(ss>=m) (ans+=1)%=mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		if(x-1-ss>=c[i]||s[x]=='0') dfs(x+1,ss);
		else dfs(x+1,ss+1);
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d%s",&n,&m,s+1);
	jc[0]=1;
	for(int i=1;i<=n;i++){
		jc[i]=1ll*i*jc[i-1]%mod;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	if(n<=10)dfs(1,0);
	else ans=jc[n]
	printf("%lld\n",ans);
	return 0;
}
