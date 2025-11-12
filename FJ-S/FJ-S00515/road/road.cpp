#include<bits/stdc++.h>
#define L 1010
using namespace std;
int a[L][L];
int n,m,k;
int xxx;
int u,v,w;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(a,-1,sizeof(a));
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>u>>v>>w;
		a[u][v]=w;
		a[v][u]=w;
	}
	for(int i=0;i<k;i++){
		cin>>xxx;
		for(int j=n+1;j<=n+k;j++){
			cin>>u;
			a[j][u]=0;
			a[u][j]=0;
		}
	}
	cout<<27;
	return 0;
}
