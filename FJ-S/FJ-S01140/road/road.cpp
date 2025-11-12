#include<bits/stdc++.h>
using namespace std;
int n,m,k,u[10000001],v[10000001],w[10000001],o[10001][10001];
long long c[1000001],a[10001][10001],cc[1000001],ans=0,f,vi[1000001];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	for(int i=1;i<=n;i++){
		vi[i]=0;
	}
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		o[u[i]][v[i]]=w[i];
		o[v[i]][u[i]]=w[i];
		ans+=w[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	cout<<ans;
	return 0;                                                                 
}
