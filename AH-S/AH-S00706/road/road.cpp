#include <bits/stdc++.h>
using namespace std;

int u[1000001],v[1000001],w[1000001];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int ans=0;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		ans+=u[i]+v[i]+w[i];
	}
	for(int i=1;i<=k;i++){
		for(int i=1;i<=n+1;i++){
			int a;
			cin>>a;
		}
	}
	cout<<ans;
	return 0;
}
