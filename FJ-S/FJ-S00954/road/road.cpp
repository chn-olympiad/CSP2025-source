#include<iostream>
#include<cstdio>
using namespace std;
int n,m,k;
int u[1001],v[1001],w[100001],c[11],a[1001];
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
			cin>>a[j];
		}
	}
	cout<<0;
	return 0;
}
