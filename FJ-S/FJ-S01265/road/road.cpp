#include<cstdio>
#include<iostream>
using namespace std;
int u[1000005],v[1000005],f[15][10005];
long long a[10005][10005],c[15][10005],w[1000005];
long long ans=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d%lld",&x,&y,&w[i]);
		if(x>y){
			u[i]=y;
			v[i]=x;
		}else{
			u[i]=x;
			v[i]=y;
		}
	}
	long long xx;
	int ll=0;
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i][0]);
		xx=0;
		for(int j=1;j<=n;j++){
			scanf("%lld",&c[i][j]);
			xx+=c[i][j];
			a[i][j]=1e18;
		}
		if(ans<xx){
			ans=xx;
			ll=i;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
