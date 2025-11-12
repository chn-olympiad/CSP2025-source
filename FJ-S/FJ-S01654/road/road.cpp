#include<bits/stdc++.h>
using namespace std;
//const int M=1e6+10;
const int N=1e4+10;

int w[N][N];
int c[15],a[15][N];
int cost;

void solve(){
	int n,m,k;
	cin>>n>>m>>k;
	int u,v;
	for(int i=1;i<=m;i++){
		cin>>u>>v;
		cin>>w[u][v];
		w[v][u]=w[u][v];
		cost+=w[u][v];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	cout<<cost;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	solve();  
	return 0;
}//awa
