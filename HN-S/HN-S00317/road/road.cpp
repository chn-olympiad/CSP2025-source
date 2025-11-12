#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
const int M=1e4+5;
std::vector<int> g[N];
int w[M][M];
int c[15]; 
int a[15][M];
long long ans=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1,u,v;i<=m;i++){
		cin>>u>>v;
		cin>>w[u][v];
		g[u].push_back(v);
		g[v].push_back(u);
	}//½¨±ß 
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
					if(w[i][j]>w[i][k]+w[k][j]&&w[i][k]!=0&&w[k][j]!=0) ans+=w[i][k]+w[k][j];
					else if(w[i][k]==0&&w[k][j]==0) ans+=w[i][j];
					cout<<ans<<" "<<w[i][j]<<" "<<w[i][k]<<" "<<w[k][j]<<'\n';
			}
		}
	}
	cout<<ans;
	return 0;
} 
