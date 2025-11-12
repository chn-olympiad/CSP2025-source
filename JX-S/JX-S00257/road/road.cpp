#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct code{
	int u,v,w;
}a[1000010];
int c,g[11][10010];
int ans=99999999,sum[11];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
		
	}
	for(int i=1;i<=k;i++){
		cin>>c;
		int cnt=c;
		for(int j=1;j<=n;j++){
			cin>>g[i][j];
			cnt+=g[i][j];
		}
		sum[i]=cnt;
	}
	for(int i=1;i<=k;i++){
		ans=min(ans,sum[i]);
	}
	cout<<ans;
	return 0;
}
