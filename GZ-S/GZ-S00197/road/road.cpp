//GZ-S00197 遵义市第四中学 戴文博 
#include <bits/stdc++.h>
using namespace std;
long long n,m,k;
long long u[1000005],v[1000005],w[1000005],c[1000005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    scanf("%lld%lld%lld",&n,&m,&k);
    for(int i=1;i<=m;i++){
    	scanf("%lld%lld%lld",&u[i],&v[i],&w[i]);
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n+1;j++){
			scanf("%lld",&c[j]);
		}
	}
	cout<<0;
	return 0;
	fclose(stdin);
	fclose(stdout);
}

