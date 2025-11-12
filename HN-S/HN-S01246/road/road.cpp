#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6;
int n,m,k; 
int a[maxn];
bool g[maxn];
vector<int> ma[maxn];
long long ans=1e8;
map<int,map<int,int>> w;
void dfs(long long sum,int now,int vis){
	if (vis+1==n){
		ans=min(ans,sum);
		return;
	}
	for (int i=0;i<ma[now].size();i++){
		if (!g[ma[now][i]]){
			g[ma[now][i]]=true;
			dfs(sum+w[now][ma[now][i]],ma[now][i],vis+1);	
			g[ma[now][i]]=false;
		}
	}
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	int s=-1;
	for (int i=1;i<=m;i++){
		int u,v,x;
		cin >> u >> v >> x;
		ma[u].push_back(v);
		ma[v].push_back(u);
		w[u][v]=x;
		w[v][u]=x;
		if (s==-1) s=u;
	}
	for (int i=1;i<=k;i++){
		cin >> a[i];
	} 
	g[s]=true;
	dfs(0,s,0);
	if (ans!=1e8) cout << ans;
	else cout << 0;
	return 0;
} 
