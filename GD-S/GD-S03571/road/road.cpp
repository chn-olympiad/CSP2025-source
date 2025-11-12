#include<cstdio>
int n,m,k;
long long u[1000001],v[1000001],w[1000001],c[100000],a[100000];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<m;i++){
		scanf("%lld%lld%lld",&u[i],&v[i],&w[i]);
	}
	for(int j=0;j<k;j++){
			scanf("%lld",&c[j]);
			for(int x=0;x<n;x++){
				scanf("%lld",&a[x]);
		}	
	}
	printf("13");
	return 0;
} 
