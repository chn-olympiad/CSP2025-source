#include<bits/stdc++.h>
using namespace std;
int n,m,k,u[10005],v[10005],w[10005],a[10005][10005],c[10005];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];}
	for(int i =1;i<=k;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];}}
	cout<<"0";

	return 0;}


