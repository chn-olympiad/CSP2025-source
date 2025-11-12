#include <bits/stdc++.h>
using namespace std;
const int N=1e4+10;
const int M=1e6+10;
struct node{
	int u,v,w;
}e[M];
int fa[N];
bool cmp(node x,node y){
	return x.w<y.w;
}
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=n;i++) fa[i]=i;
		for(int i=1;i<=m;i++){
			scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
		}
		int ret=0;
		sort(e+1,e+m+1,cmp);
		for(int i=1;i<=m;i++){
			int p=find(e[i].u);
			int q=find(e[i].v);
			if(p==q) continue;
			fa[p]=q;
			ret+=e[i].w;
		}
		printf("%d",ret);
	return 0;
}
