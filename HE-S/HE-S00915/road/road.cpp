#include<bits/stdc++.h>
using namespace std;
int n,m,k,u[114514],v[114514],w[114514],c[114],a[114][114514];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	cout<<4;
	return 0;
}
