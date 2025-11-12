#include<bits/stdc++.h>
using namespace std;
long long n,m,k,ans=1e18;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
	}
	for(int i=1;i<=k;i++){
		long long sum=0;
		for(int j=1;j<=n+1;j++){
			int x;
			cin>>x;
			sum+=x;
		}
		ans=min(ans,sum);
	}
	cout<<ans;
	return 0;
}
