#include<bits/stdc++.h>
using namespace std;
long long n,m,k,u[1000001],v[1000001],w[1000001],c[1000001],ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(long long i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		ans+=u[i];
	}
	for(int i=1;i<=m;i++){
		cin>>c[i];
	}
	cout<<ans+1+c[1];
	return 0;
}
