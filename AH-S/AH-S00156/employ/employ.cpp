#include<bits/stdc++.h>
using namespace std;
const int mod=998244353,N=510;
int n,m,ans;
int s[N],c[N];
bool vis[N];
void dfs(int x,int gin,int now){
	if(x==n+1){ans+=(now>=m);return;}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		if(s[x]==0) dfs(x+1,gin+1,now);
		if(s[x]==1){
			if(gin>=c[i]) dfs(x+1,gin+1,now);
			else dfs(x+1,gin,now+1);
		}
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char c;cin>>c;
		s[i]=c-'0';
	}
	for(int i=1;i<=n;i++) cin>>c[i];
	dfs(1,0,0);
	cout<<ans%mod;
	return 0;
}
