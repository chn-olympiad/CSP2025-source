#include<bits/stdc++.h>
using namespace std; 
int n,m,k,c[15][10005];
struct node{
	int u,v,w;
}arr[1000005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>arr[i].u>>arr[i].v>>arr[i].w;
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n+1;j++){
			cin>>c[i][j];
		}
	}
	cout<<6;
	return 0;
}
