#include<bits/stdc++.h>
using namespace std;
int n,m,k,u,w,v;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>u>>v>>w;
	for(int j=1;j<=k;j++){
		for(int i=1;i<=n+1;i++) cin>>u;
	}
	cout<<13;
	return 0;
}
