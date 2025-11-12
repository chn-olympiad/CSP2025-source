#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
long long l[N],n,m,k,u[N],v[N],w[N],c[N],a[105][105],cnt=1220323,ans=1323203;
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
cin>>n>>m>>k;
for(int i=1;i<=m;i++){
	cin>>u[i]>>v[i]>>w[i];
	ans=min(ans,w[i]);
}
for(int i=1;i<=k;i++){
	cin>>c[i];
	for(int j=1;j<=n;j++){
	cin>>a[i][j];
		cnt=min(cnt,a[i][j]);
	}
}
cout<<ans+cnt;

	return 0;
}
