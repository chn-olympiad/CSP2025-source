#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
struct node{
	long long u,v,w;
	bool operator<(const node&a)const{
		return a.w<w;
	}
};
long long ans;
long long n,m,k;
const long long N=1000001;
priority_queue<node> q;
long long vis[N],fa[N];
long long find(long long x){
	if (x==fa[x]){
		return x;
	}
	return fa[x]=find(fa[x]);
}
bool cmp(node a,node b){
	return a.w<b.w;
}
void kruskal(){
	while (!q.empty()){
		long long u=q.top().u,v=q.top().v,w=q.top().w;
		q.pop();
		u=find(u),v=find(v);
		if (u!=v){
			ans+=w;
			fa[u]=v;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for (long long i=1;i<=m;i++){
		long long u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		q.push({i,v,w});
		q.push({i,u,w});
	}
	for (long long i=1;i<=k;i++){
		long long c,a;
		scanf("%lld",&c);
		for(long long j=1;j<=n;j++){
			scanf("%lld",&a);
			q.push({i,j,a});
		}
		
	}
	for (long long i=1;i<=n;i++){
		fa[i]=i;
	}
	kruskal();
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
