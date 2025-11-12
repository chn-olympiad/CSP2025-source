#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int s=0;
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		s+=w;
	}
	cout<<s;
	return 0;
}