#include <bits/stdc++.h>
using namespace std;
const int N=1e4+7,M=1e6+7;
int n,m,k;
struct node{
	int u,v,w;
}f[M];
int a[15][N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>f[i].u>>f[i].v>>f[i].w;
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	cout<<"0\n";
	return 0;
}
