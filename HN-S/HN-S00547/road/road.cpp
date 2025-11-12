#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
vector<pair<int,int> > e;
int c[15],r[15][N];
int n,m,k;
int sum;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int u,v,w;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		e[u].push_back({v,w});
		e[v].push_back({u,w});
		sum+=w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>r[i][j];
		}
	}
	/*
	if(k==0){
		
	}
	*/
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
