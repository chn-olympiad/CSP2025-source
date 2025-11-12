#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,hcnt,cnt,fa[10005],ans;
struct edge{
	int u,v,cost;
}e[2000005];
bool cmp(edge x,edge y){
	return x.cost<y.cost;
}
int findf(int x){
	if(x==fa[x]) return x;
	return fa[x]=findf(fa[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld %lld %lld",&n,&m,&k);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		scanf("%lld %lld %lld",&e[i].u,&e[i].v,&e[i].cost);
	}
	for(int i=1,tmp;i<=k;i++){
		scanf("%lld",&tmp);
		for(int j=1,w;j<=n;j++){
			scanf("%lld",&w);
		}
	}
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++){
		if(cnt==n-1) break;
		int a=findf(e[i].u),b=findf(e[i].v);
		if(a!=b){
			fa[a]=b;
			cnt++;
			ans+=e[i].cost;
		}
	}
	cout<<ans;
	return 0;
}
