#include <bits/stdc++.h>
using namespace std;
int a[20005][21222];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int o=0;
	for(int i=1;i<=m;i++){
		int q,w,e;
		cin>>q>>w>>e;
		o+=e;
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n+1;j++){
			cin>>a[i][j];
		}
	}
	cout<<o;
	return 0;
}
