#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k;
vector<int> e[10005];
vector<int> w[10005];
int u,v,ww;
int ans=1000000000;
int b[15];
int c[15][10005];
int vis[10005];
bool all(){
	for(int i=1;i<=n;i++){
		if(vis[i]==0)return false;
	}
	return true;
}
void dfs2(int now,int s){
	if(all()){
		ans=min(ans,s);
		return;
	}
	int g=e[now].size();
	for(int i=0;i<g;i++){
		if(vis[e[now][i]]==0){
			vis[e[now][i]]=1;
			dfs2(e[now][i],s+w[now][i]);
			vis[e[now][i]]=0;
		}
	}
}
void dfs(int now,int s){
	if(now==k+1){
		vis[1]=1;
		dfs2(1,s);
		return;
	}
	for(int i=1;i<=n;i++){
		e[i].push_back(now+n);
		w[i].push_back(c[now][i]);
		e[now+n].push_back(i);
		w[now+n].push_back(c[now][i]);
	}
	dfs(now+1,s+b[now]);
	for(int i=1;i<=n;i++){
		e[i].pop_back();
		w[i].pop_back();
		e[now+n].pop_back();
		w[now+n].pop_back();
	}
	dfs(now+1,s);
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>ww;
		e[u].push_back(v);
		w[u].push_back(ww);
		e[v].push_back(u);
		w[v].push_back(ww);
	}
	for(int i=1;i<=k;i++){
		cin>>b[i];
		for(int j=1;j<=n;j++){
			cin>>c[i][j];
		}
	}
	dfs(1,0);
	cout<<ans<<endl;
	return 0;
}
