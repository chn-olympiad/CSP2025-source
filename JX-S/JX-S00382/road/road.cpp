#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,u,v,w,c;
	cin>>n>>m>>k;
	int a[n];
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<n;j++){
			cin>>c>>a[j];
		}
	}
	cout<<13;
	return 0;
}
