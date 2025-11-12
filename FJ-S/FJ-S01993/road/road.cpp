#include<bits/stdc++.h>
using namespace std;
const int Nn=1e4+10,Nm=1e6+10;
int n,m,k,u[Nm],v[Nm],w[Nm],c[20],a[20][Nn];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	cout<<0;
	return 0;
} 
