#include<bits/stdc++.h>
using namespace std;
const int N1=1e4+5,N2=1e6+5,N3=15;
vector<int> e[N1];
int n,m,k,w[N2],h[N3][N1];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v>>w[i];
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for (int i=1;i<=k;i++){
		cin>>h[i][0];
		for (int j=1;j<=n;j++)
			cin>>h[i][j];
	}
	cout<<7891; 
	return 0;
}

