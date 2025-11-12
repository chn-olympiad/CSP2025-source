#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,m,cnt,ans;
char ch[510];
int c[510];
int vis[510],s[510];
void dfs(int x){
	if(x==n+1){
		int tot=0;
		for(int i=1;i<=n;i++)
			if(c[s[i]]<=tot||ch[i]=='0')tot++;
		if(n-tot>=m)ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;
		s[x]=i;
		dfs(x+1);
		s[x]=0;
		vis[i]=0;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		cin>>ch[i];
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&c[i]);
		if(c[i]==0)cnt++;
	}
	if(n-cnt<m){
		printf("0");
		return 0;
	}
	dfs(1);
	printf("%lld",ans);
	return 0;
}
