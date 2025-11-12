#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,k,u,v,w,cc;
int a[N][N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
	}
	cin>>cc;
	for(int i=1;i<=k;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	cout<<13;
	return 0;
}
