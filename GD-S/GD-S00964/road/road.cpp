#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
long long u[1001000],v[1001000],w[1001000];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans+=w[i];
	}
	cout<<ans<<'\n';
	
	return 0;
}
