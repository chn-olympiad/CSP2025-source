#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	int n,m,k;
	cin>>n>>m>>k;
	vector<vector<int> >a(n+1,vector<int>(m+1,2e10));
	vector<int>c(n+2,0);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int u,v,w;
			cin>>u>>v>>w;
			a[u][v]=w;
			a[v][u]=w;
		}
	}
	for(int i=1;i<=n+1;i++){
		cin>>c[i];
	}
	
	return 0;
} 
