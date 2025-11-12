#include<bits/stdc++.h>
using namespace std;
int fa[10005];
long long c[15][10005];
int n,m,k;
struct node{
	int u,v;
	long long w;
};
long long ans;
vector<node> g;
void in(){
	for(int i=1; i<=n; i++){
		fa[i]=i;
	}
	return;
}
int get(int x){
	if(fa[x]==x) return x;
	fa[x]=get(fa[x]);
	return fa[x];
}
void merge(int o,int p){
	int s=get(o);
	int t=get(p);
	if(s!=t){
		fa[s]=t;
	}
	return;
}
bool cmp(node c,node d){
	return c.w<d.w;
}
void K(){
	int cnt=0;
	for(int i=0; i<m; i++){
		int o=g[i].u,p=g[i].v;
		if(get(o)!=get(p)){
			ans+=g[i].w;
			merge(o,p);
			cnt++;
		}
		if(cnt==n-1){
			return;
		}
	}	
	return;
} 
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	in();
	for(int i=1; i<=m; i++){
		int x,y;
		long long z;
		scanf("%d %d %lld",&x,&y,&z);
//		G[x].push_back({y,z});
//		G[y].push_back({x,z});
		g.push_back({x,y,z});
	}
	sort(g.begin(),g.end(),cmp);
	bool f=0;
	for(int i=1; i<=k; i++){
		for(int j=1; j<=n; j++){
			scanf("%lld",&c[i][j]);
			if(c[i][j]!=0) f=1;
		}
	}
	if(f==0){
		printf("0");
		return 0;
	}
	K();
	printf("%lld",ans);
	return 0;
}
