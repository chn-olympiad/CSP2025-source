#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
struct node{
	int u,v,w;
	bool operator <(node A){
		return w<A.w;
	}
}a[MAXN];
int n,m,k,fa[MAXN];
long long ans;
int find(int x){
	if(fa[x]==x){
		return x;
	}
	return fa[x]=find(fa[x]);
}
void kruskal(){
	sort(a+1,a+m+1);
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		int fdu=find(a[i].u),fdv=find(a[i].v);
		if(fdu!=fdv){
			fa[fdu]=fdv;
													//		printf("%d %d\n",a[i].u,a[i].v,a[i].e);
			ans+=a[i].w;
		}
	}
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
	}
	kruskal();
	printf("%lld",ans);
	return 0;
} 
