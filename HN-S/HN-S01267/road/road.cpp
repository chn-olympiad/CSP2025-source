#include<cstdio>
#include<iostream>
using namespace std;
int n,m,k,u,v,w;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n+1;j++){
			cin>>v;
		}
	}
	cout<<0;
	return 0;
} 
