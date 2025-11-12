#include<bits/stdc++.h>

using namespace std;
int u[1000005],v[1000005],w[1000005],c[1000005],x[1000005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i = 1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	int ans=0;
	for(int i = 1;i<=m;i++){
		cin>>c[i];
		for(int j = 0;j<=n;j++){
			cin>>x[j];
			ans+=min(x[j]+x[j-1]+c[i],u[i]);
		}
	}
	cout<<ans;
	return 0;
}
