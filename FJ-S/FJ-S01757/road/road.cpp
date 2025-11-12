#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans;
int u[10005],v[10005],w[10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		ans+=w[i];
	}
	cout<<ans;
	return 0;
}
