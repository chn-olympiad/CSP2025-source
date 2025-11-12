#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll ans;
const int N=1e4+5,M=5e6+5;
int n,m,k,fa[N],c[11][N],vs[N];
struct wl{
	int u,v,w,nxt;
	bool f;
}e[M];
bool cmp(wl a,wl b){
	return a.w<b.w;
}
int head[N],e_cnt;
void add(int u,int v,int w){
	e[++e_cnt].v=v;
	e[e_cnt].u=u;
	e[e_cnt].w=w;
	e[e_cnt].nxt=head[u];
	head[u]++;
}
int find(int x){
	if(x==fa[x]){
		return x;
	}
	return fa[x]=find(fa[x]);
}
void solvea(){
	int cnt=0;
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++){
		if(find(e[i].u)!=find(e[i].v)){
			fa[e[i].u]=e[i].v;
			cnt++;
			ans+=e[i].w;
		}
		if(cnt==n-1){
			break;
		}
	}printf("%lld",ans);
}
void solveb(){
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			scanf("%d",&c[i][j]);
		}
	}
	for(int x=1;x<=k;x++){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				m++;
				add(i,j,c[x][i]+c[x][j]);
				e[e_cnt].f=x;
			}
		}
	}
	int cnt=0;
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++){
		if(find(e[i].u)!=find(e[i].v)){
			fa[e[i].u]=e[i].v;
			cnt++;
			if(e[i].f&&(!vs[e[i].f])){
				ans+=c[e[i].f][0];
				vs[e[i].f]=1;
			}
			ans+=e[i].w;
		}
		if(cnt==n-1){
			break;
		}
	}printf("%lld",ans);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
		e[e_cnt].f=0;
	}
	if(k==0){
		solvea();
	}else{
		solveb();
	}
	return 0;
}
