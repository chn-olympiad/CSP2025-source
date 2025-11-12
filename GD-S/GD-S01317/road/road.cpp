#include <bits/stdc++.h>
using namespace std;
struct node{
	int to;
	int w;
};
int mx=-1e9;
const int M=1e4+5;
vector<node> g[M];
bool vis[N];
int n,m,k;
void dfs(int t,int cnt){
	if(t==n){
		mx=max(mx,cnt);
	}
	for(auto v:g[t]){
		int i=v.to;
		int x=v.w;
		if(!vis[i]){
			vis[i]=1;
			dfs(i,cnt+x);
			vis[i]=0;
		}
	}
}
int a[20][M],c[20];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	int cnt=0;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]==0){
			cnt++;
		} 
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	if(cnt==k&&k!=0){
		cout<<0;
		return 0;
	}
	dfs(1,0);
	cout<<mx;
	return 0;
}
