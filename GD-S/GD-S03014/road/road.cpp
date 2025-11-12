#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int n,m,k;
int w[N];
vector<pair<int,int>>e[N];
int C[N],c[15][N];
int main(){
	int ans=0;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v>>w[i];
		e[u].push_back({v,w[i]});
		e[v].push_back({u,w[i]});
	}
	for(int i=1;i<=k;i++){
		cin>>C[i];
		for(int j=1;j<=n;j++){
			cin>>c[i][j];
		}
	}
	if(k==0){
		for(int i=1;i<=m;i++){
			ans+=w[i];
		}
		cout<<ans<<"\n";
	}
	return 0;
}
