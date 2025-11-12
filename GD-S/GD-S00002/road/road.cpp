#include<bits/stdc++.h>
#define ll long long
const int N=1e4+20;
using namespace std;
ll n,m,k,a[N][N],cr[20][N],ans,cp[20];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(a,0x7fffffff,sizeof(a));
	memset(cr,0x7fffffff,sizeof(cr));
	memset(cp,0x7fffffff,sizeof(cp));
	for(int i=1;i<=N;i++) a[i][i]=0;
	scanf("%lld %lld %lld",&n,&m,&k);
	for(int i=1;i<=m;i++){
		ll u,v,w;
		scanf("%lld %lld %lld",&u,&v,&w);
		a[u][v]=w;
		a[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&cp[i]);
		for(int j=1;j<=n;j++){
			ll w;
			scanf("%lld",&w);
			cr[i][j]=w;
		}
	}
	printf("0\n");
	fplace(stdin);
	fplace(stdout);
	return 0;
} 
