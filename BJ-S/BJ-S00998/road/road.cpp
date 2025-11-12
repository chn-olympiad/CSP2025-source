#include "bits/stdc++.h"
using namespace std;

struct way {
	int to;
	int pri;
};

int country[10005];
int buildpri[10005];
int vis[10005];

vector<way> G[10005];

int n,m,k;
int ans = 2147483647;
void dfs(int now,int res,int vised) {
	
	
	
	if(vised >= n) {
		ans = min(ans,res);
		return ;
	}
	
	for(int i = 0;i < G[now].size();i++) {
		
		if(country[G[now][i].to]) {
			if(!vis[G[now][i].to]) {
				vis[G[now][i].to] = 1;
				//cout<<"Debug: go to "<<G[now][i].to<<" res:"<<res<<endl;
				dfs(G[now][i].to,(res + G[now][i].pri + buildpri[G[now][i].to]),vised);
				vis[G[now][i].to] = 0;
		
			}
		}
		else {
			if(!vis[G[now][i].to]) {
				vis[G[now][i].to] = 1;
				//cout<<"Debug: LN2 go to "<<G[now][i].to<<" res:"<<res<<endl;
				dfs(G[now][i].to,(res + G[now][i].pri),vised + 1);
				vis[G[now][i].to] = 0;
			
			}
		}
	}
}


int main() {
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	for(int i = 1;i <= m;i++) {
		int u,v,p;
		cin>>u>>v>>p;
		G[u].push_back({v,p});
		G[v].push_back({u,p});
	}
	
	//n + i biaoshi country id
	for(int i = 1;i <= k;i++) {
		int q;
		cin>>q;
		buildpri[k + i] = q;
		country[k + i] = 1;
		for(int j = 1;j <= n;j++) {
			int p;
			cin>>p;
			G[i + n].push_back({j,p});
			G[j].push_back({n + i,p});
		}
	}
	
	//cout<<"Input OK!";
	
	for(int i = 1;i <= n;i++) {
		
		//cout<<"Start:"<<i<<endl;
		
		dfs(i,0,1);
	}
	
	cout<<ans;
	
	
	
	return 0;
}
