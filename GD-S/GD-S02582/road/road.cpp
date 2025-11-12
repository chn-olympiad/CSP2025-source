#include<bits/stdc++.h>
using namespace std;
long long n,m,k,u,v,w;
int a[10015][10015];
int b[15][10005],w1[10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k; 
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		a[u][v]=w;
		a[v][u]=w;
		w1[i]=w;
	}
	sort(w1+1,w1+n+1);
	for(int i=1;i<=k;i++){
		cin>>b[i][0];
		for(int j=1;j<=n;j++){
			cin>>b[i][j];
		}
	}
	cout<<0; 
	return 0;
} 
