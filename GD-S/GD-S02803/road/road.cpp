#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	int ans=0;
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		ans+=w;
	}
	cout<<ans;
	return 0;
}

