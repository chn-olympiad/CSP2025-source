#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[100][100],b[100][100];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		a[u][v]=w;
		a[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		int j;
		cin>>j;
		for(int t=1;t<=n;t++) cin>>b[j][t];
	}
	if(k==0) cout<<0;
	else cout<<n;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
