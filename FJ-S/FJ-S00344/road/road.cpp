#include<bits/stdc++.h>
using namespace std;
const long long MAXM=1e6+5,MAXN=1e4+5;
long long n,m,k,u[MAXN],v[MAXN],w[MAXM],next[MAXM],c[MAXN],ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&u[i],&v[i],&w[i]);
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
	}
	sort(w+1,w+n+1);
	for(int i=1;i<=n-1;i++){
		ans+=w[i];
	}
	printf("%lld",ans);
	return 0;
}

