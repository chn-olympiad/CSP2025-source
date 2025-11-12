#include<bits/stdc++.h>
using namespace std;
const int N=1e4+25;
const int inf=1e9+7;
int n,m,k,ans;
int val[N];
int c[15][N];
int g[N][N];
bool vis[N];
vector<int> dianji;
void dfs(){
	if((int)dianji.size()==n) {
		cout<<ans;
		exit(0);
	}
	int now=0,nxt=0,minn=inf;
	for(int i=0;i<(int)dianji.size();i++){
		for(int j=1;j<=n;j++){
			if(vis[j]==1) continue;
			if(g[dianji[i]][j]<minn) minn=g[dianji[i]][j],nxt=j,now=dianji[i];
		}
	}
	vis[nxt]=1;
	dianji.push_back(nxt);
	ans+=minn;
//	cout<<now<<" "<<nxt<<" "<<minn<<" "<<ans<<endl;
	dfs();
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(g,inf,sizeof(g));
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u=0,v=0,w=0;
		cin>>u>>v>>w;
		ans+=w;
		g[u][v]=g[v][u]=min(g[u][v],w);
	}
	bool p=0;
	for(int i=1;i<=k;i++){
		cin>>val[i];
		if(val[i]!=0) p=1;
		for(int j=1;j<=n;j++){
			cin>>c[i][j];
			if(c[i][j]!=0) p=1;
		}
	}
	if(p==0&&k!=0) cout<<0;
	else{
		if(k!=0) cout<<ans<<endl;
		else{
			ans=0;
			vis[1]=1;
			dianji.push_back(1);
			dfs();
		}
	}
	return 0;
}
