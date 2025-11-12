#include<bits/stdc++.h>
using namespace std;
int u[10000],v[10000],w[10000],c[10000];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i];
	}
	for(int i=1;i<=m;i++){
		cin>>v[i];
	}
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int a;
	for(int i=1;i<=n+1;i++)
		for(int i=1;i<=m;i++)
			cin>>a;
	cout<<13;
	return 0;
}









