#include<bits/stdc++.h>
using namespace std;
int n,m,k,c[15],a[15][10005],ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w,",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		ans+=w;
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++) scanf("%d",&a[i][j]);
	}
	printf("%d",ans);
	return 0;
}
