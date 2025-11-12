#include<bits/stdc++.h>
using namespace std;
int w[10005][3],a[15][10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int i,j,n,k,ans=0,m;
	scanf("%d %d %d",&n,&m,&k);
	for(i=1;i<=n;i++){
		scanf("%d %d %d",&w[i][0],&w[i][1],&w[i][2]);
		ans+=w[i][2];
	}
	for(i=1;i<=k;i++){
		for(j=0;j<=n;j++)
			scanf("%d",&a[i][j]);
	}
	printf("%d\n",ans);
	return 0;
}
