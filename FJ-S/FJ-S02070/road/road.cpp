#include<bits/stdc++.h>
using namespace std;
int mp[10003][10003];
int xz[13][10003];
int vis[10003];
bool vs[10003];
int ans,n;
void dfs(int q,int p,int r){
	bool io = 1;
	for(int i = 1;i <= n;i++){
		io = io & vs[i];
	}
	if(io){
		ans = min(ans,r-mp[q][p]);
		return;
	}
	for(int i = 1;i <= n;i++){
		if(i != p && vs[i] != 1){
			vs[i] = 1;
			dfs(p,i,r+mp[p][i]);
			vs[i] = 0;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(mp,0x3f,sizeof(mp));
	int m,k;
	cin>>n>>m>>k;
	for(int i = 1;i <= n;i++){
		int u,v,w;
		cin>>u>>v>>w;
		mp[u][v] = w;
		mp[v][u] = w;
	}
	for(int i = 1;i <= k;i++){
		for(int j = 0;j <= n;j++){
			cin>>xz[i][j];
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = i;j <= n;j++){
			for(int lc = 1;lc <= k;lc++){
				mp[i][j] = min(mp[i][j],xz[lc][0]+xz[lc][i]+xz[lc][j]);
				mp[j][i] = mp[i][j];
			}
		}
	}
	ans = INT_MAX;
	for(int i = 1;i <= n;i++){
		dfs(i,i,0);
	}
	cout<<ans+1;
	return 0;
}
