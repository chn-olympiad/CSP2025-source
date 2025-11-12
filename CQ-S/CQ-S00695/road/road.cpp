#include<bits/stdc++.h>
#define int long long
using namespace std;
struct st{
	int u,v,w;
}tu[1000005];
bool cmp(st A,st B){
	return A.w<B.w;
}
int father[10005]={};
int bingchaji(int x){
	if(father[x]==x) return x;
	else{
		father[x]=bingchaji(father[x]);
		return father[x];
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n=0,m=0,k=0;
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n;i++) father[i]=i;
	for(int i=1;i<=m;i++){
		int u=0,v=0,w=0;
		scanf("%lld%lld%lld",&u,&v,&w);
		tu[i*2-1].u=u,tu[i*2-1].v=v,tu[i*2-1].w=w;
		tu[i*2].u=v,tu[i*2].v=u,tu[i*2].w=w;
	}
	sort(tu+1,tu+2*m+1,cmp);
	int sum=0;
	for(int i=1,gs=0;i<=2*m;i++){
		int u=bingchaji(tu[i].u),v=bingchaji(tu[i].v);
		if(u!=v){
			father[v]=u;
			sum+=tu[i].w;
			gs++;
		}
		if(gs==n-1) break;
	}
	printf("%lld",sum);
}
