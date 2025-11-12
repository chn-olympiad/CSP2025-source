#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n,m,k,u,v,w,ans;
ll c[10010],a[10010];
ll g[10010][10010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld %lld %lld",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%lld %lld %lld",&u,&v,&w);
		g[u][v]=w;
		g[v][u]=w;
		ans+=w;
	}
	for(int i=0;i<k;i++){
		scanf("%lld",&c[i]);
		for(int j=0;j<n;j++){
			scanf("%lld",&a[i]);
		}
	}
	for(int i=0;i<k;i++){
		if(c[i]==0){
			printf("0");
			return 0;
		}
	}
	printf("%lld",ans/2);
	return 0;
}

