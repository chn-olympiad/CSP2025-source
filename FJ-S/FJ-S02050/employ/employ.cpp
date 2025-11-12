#include <bits/stdc++.h>
using namespace std;
#define int long long
int const N=1e6+100;
int n,m,c[N];
string s;
bool vis[N];
int ans=0;
vector<int>t;
int const mod=998244353;
void dfs(int tt){
	if(tt==n){
		ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		dfs(tt+1);
		vis[i]=0;
	}
}
signed main(){
	freopen("employ.in","r",stdin);freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
//	for(int i=1;i<=n;i++){
//		memset(vis,0,sizeof(vis));
//		vis[i]=1;
//		dfs(1);
//	}
	ans=1;
	for(int i=1;i<=n;i++) ans=(ans*i)%mod;
	cout<<ans;
	return 0;
}
/*
1 2 3 4
3 2
111
1 1 2 

1--6
2--6
3--6
4--6
*/