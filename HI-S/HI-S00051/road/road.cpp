#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,k,aa=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		aa+=w;
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			int a;
			cin>>a;
		}
	}
	cout<<aa;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	return 0;
} 
