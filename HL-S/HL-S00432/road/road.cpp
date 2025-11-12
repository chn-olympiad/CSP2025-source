#include<bits/stdc++.h>
using namespace std;
int u[1000006],v[1000009],w[1000009],c[1000009],y[1000009];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	long long ret=0;
	scanf("%d%d%d", &n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d", &u[i],&v[i],&w[i]);
		ret+=w[i]*1ll;
	}
	for(int i=1;i<=k;i++){
		scanf("%d", &c[i]);
		for(int j=1;j<=n;j++){
			scanf("%d", &y[j]);
		}
	}
	printf("%lld", ret);
	return 0;
}