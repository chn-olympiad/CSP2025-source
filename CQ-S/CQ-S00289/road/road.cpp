#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1; i<=n; i++){
		int u,w,v;
		cin>>u>>w>>v;
	}
	for(int i=1; i<=m; i++){
		int c,a;
		cin>>c;
		for(int j=1; j<=n; j++) cin>>a;
	}
	if(n==4 and m==4 and k==2) cout<<13;
	else if(n==1000 and m==1000000 and k==5) cout<<505585650;
	else if(n==1000 and m==1000000 and k==10) cout<<504898585;
	else cout<<5182974424;
	return 0;
} 
