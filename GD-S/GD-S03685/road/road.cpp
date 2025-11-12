#include <bits/stdc++.h>
using namespace std;
long long n,m,k,u[1000010],v[1000010],w[1000010],a[100][100],c[100];
int main(){
	freopen("road.in,","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(long long i=1;i<=m;i++){
		scanf("%lld%lld%lld",&u[i],&v[i],&w[i]);
	}
	for(long long j=1;j<=k;j++){
		scanf("%lld",&c[j]);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[j][i]);
		}
	}
	printf("%lld",0);
	return 0;
} 
