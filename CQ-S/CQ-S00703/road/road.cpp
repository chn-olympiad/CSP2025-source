#include<bits/stdc++.h>
using namespace std;
int gm[10050][10050],gt[15],ans=0;

int main(){
//	freopen("road.in","r",stdin);
//	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	vector<int> g[10050];
	for(int i=1;i<=n;i++){
		int u,v,m;
		cin>>u>>v>>m;
		g[u].push_back(v);
		g[v].push_back(u);
		gm[u][v]=m;
		gm[v][u]=m;
		ans+=m;
	}
	for(int i=1;i<=k;i++){
		cin>>gt[i];
		for(int j=1;i<=n;j++){
			int m;
			cin>>m;
			g[n+i].push_back(j);
			g[j].push_back(n+i);
			gm[n+i][j]=m;
			gm[j][n+i]=m;
		}
	}
    cout<<ans<<endl;
	return 0;
} 
