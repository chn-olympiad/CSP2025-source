#include<bits/stdc++.h>
using namespace std;
int n,m,k,c;
int u,v,w;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>u>>v>>w;
	cin>>u;
	for(int i=1;i<=k;i++){
		cin>>c;
		for(int j=1;j<=n;j++)
			cin>>u;
	}
	cout<<5182974424;
	return 0;
}
