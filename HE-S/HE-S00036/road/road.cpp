#include<bits/stdc++.h>
using namespace std;
int u[1000005],v[1000005],w[1000005];
int c[15],a[15][1005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&u[i],&v[i],&w[i]);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	//输出所有道路维修的钱
	long long ans=0;
	for(int i=1;i<=m;i++){
		ans+=w[i];
	} 
	printf("%lld",ans);
	return 0;
}
