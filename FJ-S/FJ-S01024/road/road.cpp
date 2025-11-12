#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define FILE(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
#define file(x) freopen(x".in","r",stdin);
using namespace std;
const int N=1e4+5,M=1e6+5;
int n,m,k,c[N],a[N][N],dis[M];
bool vis[M];
struct node{
	int v,w;
};
vector<node> g[2*N];
int dfs(int u){
	int s1=0,s2=c[u];
	for(node i:g[u]){
		if(vis[i.v]){
			continue;
		}
		vis[i.v]=1;
		s1+=i.w;
		if(i.v<=k){
			s2+=min(a[u][i.v],i.w);
		}
		else{
			s2+=i.w;
		}
		int x=dfs(i.v);
		s1+=x;s2+=x;
	}
	return min(s1,s2);
}
signed main(){
	FILE("road")
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;cin>>u>>v>>w;
		g[u].pb({v,w});g[v].pb({u,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	cout<<dfs(1);
	return 0;
}
