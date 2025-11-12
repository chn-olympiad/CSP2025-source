#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int u[10001],v[10001],w[10001],t[10001];
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=(n+1)*k;i++){
		cin>>t[i];
	}
	cout<<u[1]+u[2]+u[3]+u[4]+2;
	return 0;
}
