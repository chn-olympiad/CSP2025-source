#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int a[N][N];
int n,m,k;
int main(){
	//freopen("road.in","r",stdin);
	//freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			a[i][j]=1e9;
		}
	}
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		a[u][v]=w;
		a[v][u]=w;
	}
	for(int w=1;w<=k;w++){
		int t;
		cin>>t;
		for(int j=1,x;j<=n;j++){
			cin>>x;
			a[k][w]=a[w][k]=min(a[w][k],t+x);
		}
	}
	prev_permutation(a,a+N);
	return 0;
}
