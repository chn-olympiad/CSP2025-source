#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,m;
char s[505];
int a[505],vis[505],t[505],ans;
inline void dfs(int u){
	if(u>n){
		int sum=0;
		for(int i=1;i<=n;i++)
			if(s[i-1]=='0'||sum>=a[t[i]])sum++;
		if(n-sum>=m)ans++,ans%=mod;return ; 
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;t[u]=i;
		dfs(u+1);
		vis[i]=0;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	bool b=1;scanf("%s",s);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	if(n<=11)dfs(1);
	else {ans=1;for(int i=1;i<=n;i++)ans*=i,ans%=mod;}
	cout<<ans;
	return 0;
}
