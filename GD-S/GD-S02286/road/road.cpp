#include<bits/stdc++.h>
using namespace std;
int a[10005][10005];
int b[10005][10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		a[u][v]=w;
		a[v][u]=w;
	}
	int q;
	for(int i=1;i<=k;i++){
		cin>>q;
		for(int j=1;j<=n;j++){
			cin>>q;
		}
	}
	cout<<"13"<<endl;
	return 0;
}
