#include <bits/stdc++.h>
using namespace std;
#define int long long
int const N=1e4+100;
int n,m,k,d[N],ans=INT_MAX;
vector<int>a[N];
int c[N],cd[N];
bool vis[N];
void dfs(int p,int sum){
	if(sum>=ans) return;
	if(p>=n){
		ans=min(ans,sum);
		return;
	}
	for(int i:a[p]){
		if(vis[i]) continue;
		vis[i]=1;
		dfs(i,sum+d[i]);
		vis[i]=0;
	}
}
signed main(){
	freopen("road.in","r",stdin);freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		a[v].push_back(u);
		a[u].push_back(v);
		cin>>d[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>cd[j];
	}
	vis[1]=1;
	dfs(1,0);
	cout<<ans;
	return 0;
}
