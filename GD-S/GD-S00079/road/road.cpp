#include <bits/stdc++.h>
using namespace std;
int f[10005];
int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
} 
struct node{
	int u,v;
	long long w;
}e[1000005];
bool  cmp(node x,node y){
	return x.w<y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++){
		scanf("%d%d%lld",&e[i].u,&e[i].v,&e[i].w);
	}
	sort(e+1,e+m+1,cmp);
	long long ans=0,cnt=0;;
	for(int i=1;i<=n;i++){
		int x=find(e[i].u),y=find(e[i].v);
		if(x!=y){
			f[x]=y;
			ans+=e[i].w;
			cnt++;
			if(cnt==n-1) break;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
