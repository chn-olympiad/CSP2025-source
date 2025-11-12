#include<bits/stdc++.h>
using namespace std;
long long ans;
int n,m,k,u,v,w,b[15][10005],c[15];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		ans+=w;
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&b[i][j]);
			if(c[i]==0&&b[i][j]==0){
				printf("0");
			}
		}
	}
	printf("%lld",ans);
	return 0;
}  
