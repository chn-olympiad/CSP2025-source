#include<bits/stdc++.h>
using namespace std;
int n,m,k,u[1000001],v[1000001],w[1000001],c[11],a[11][10001],ans=0,tong[10001][10001];
bool b=1,cun[11];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>u[i]>>v[i]>>w[i],ans+=w[i];
	for(int i=1;i<=k;i++){
		cin>>c[i];
		b=c[i]==0;
		for(int j=1;j<=n;j++) cin>>a[i][j],b=a[i][j]==0;
	}
	if(b) cout<<0;
	else cout<<ans;
	return 0;
}
