#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=510,mod=998244353;
int n,m,a[N],vis[N],p[N],ans=0;
string s;
void dfs(int x,int cnt){
	if(x>n){
		if(n-cnt>=m) ans=(ans+1)%mod;
		return;
	}
	bool fl=(s[x]=='1'?0:1);
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		p[x]=i;vis[i]=1;
		if(cnt>=a[i]) dfs(x+1,cnt+1);
		else dfs(x+1,cnt+fl);
		p[x]=0;vis[i]=0;
	}
}
void solve1(){
	memset(vis,0,sizeof(vis));
	dfs(1,0);
	cout<<ans;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m>>s;s=" "+s;
	for(int i=1;i<=n;i++) cin>>a[i];
	solve1();
	return 0;
}
