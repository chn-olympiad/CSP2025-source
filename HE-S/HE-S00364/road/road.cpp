#include<bits/stdc++.h>
using namespace std;
int n,m,k,u[1000010],v[1000010],w[1000010]c[1000010],a[10010][15];
long long sum=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scafn("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u[i],&v[i],&w[i]);
		sum+=w[i];
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)
			scanf("%d",&a[j][i]);
	}
	printf("%lld",sum);
	return 0;
}
