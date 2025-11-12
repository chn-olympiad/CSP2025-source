#include <bits/stdc++.h>
using namespace std;

int n,m,k,ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		ans+=w;
	}
	for(int i=1;i<=k;i++){
		int c,a1,a2,a3,a4,a5;
		cin>>c>>a1>>a2>>a3>>a4>>a5;
	}
	cout<<ans;
	return 0;
} 
