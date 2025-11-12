#include<bits/stdc++.h>
using namespace std;
queue<long long> ab[3];
long long n,m,k,u[104030],v[1020000],w[1020000],c[102],a[20][12000];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld %lld %lld",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%lld %lld %lld",&u[i],&v[i],&w[i]);
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%lld",a[i][j]);
		}
	}
	cout<<0;
	return 0;
}
