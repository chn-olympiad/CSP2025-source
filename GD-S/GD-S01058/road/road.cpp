#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		int u,v,w;
		cin>>u>>v>>w;
		ans+=w;
	}
	cout<<ans;
	return 0;
} 
