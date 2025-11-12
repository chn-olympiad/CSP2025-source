#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
#define int long long
int fa[N];
struct edge{
	int u,v,w;
}e[N];
bool cmp(edge x,edge y){
	return x.w < y.w;
}
int find(int x){
	if(x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;scanf("%lld%lld%lld",&n,&m,&k);
	for(int i = 1;i <= m;i++){
		scanf("%lld%lld%lld",&e[i].u,&e[i].v,&e[i].w);
	} 
	for(int i = 1;i <= n;i++){
		fa[i] = i;
	}
	int ans = 0;
	sort(e + 1,e + m + 1,cmp);
	for(int i = 1;i <= m;i++){
		if(find(e[i].u) == find(e[i].v)) continue;
		ans += e[i].w;
		fa[find(e[i].u)] = find(e[i].v);
	}
	printf("%lld",ans);
	return 0;
}

