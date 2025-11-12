#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,k,ans;
int u[N],v[N],w[N],c[N],a[N][N];
int	main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		ans+=w[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		ans+=c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			ans+=a[i][j];
		}
	}
	cout<<ans<<endl;
	return 0;
}
