#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=2e6+5;
const int N=1e4+55;
struct node{
	int u,v;
	ll w;
}edge[M],e2[M];
bool operator <(const node &A,const node &B){
	return A.w<B.w;
}
int fa[N];
ll c[15],a[15][N];
int n,m,k,cnt;
bool check(){
	bool f=1;
	for(int i=1;i<=k;i++) if(c[i]!=0) f=0;
	return f;
}
int fnd(int x){
	return fa[x]==x?x:fa[x]=fnd(fa[x]);
}
bool vis[15];
int cnt2,cnt3;
ll sol(){
	ll x=0;
	cnt2=cnt;
	cnt3=n+1;
	for(int i=1;i<=m;i++) e2[i]=edge[i];
//	for(int i=1;i<=k;i++) printf("%d ",vis[i]==1?1:0);
//	printf("\n%d\n",cnt2);
	for(int i=1;i<=k;i++){
		if(vis[i]==1){
			x+=c[i];
			cnt3++;	
			e2[++cnt2]={0,n+i,0};
			for(int j=1;j<=n;j++) e2[++cnt2]={j,n+i,a[i][j]};
		}
	}
//	printf("%d\n",cnt2);
//	printf("%d\n",cnt3);
//	for(int i=1;i<=cnt2;i++){
//		printf("%d %d %lld\n",edge[i].u,edge[i].v,edge[i].w);
//	}
	for(int i=0;i<=n+k;i++) fa[i]=i;
	sort(e2+1,e2+cnt2+1);
	for(int i=1;i<=cnt2;i++){
		if(fnd(e2[i].u)==fnd(e2[i].v)) continue;
//		printf("%d %d\n",edge[i].u,edge[i].v);
		fa[e2[i].u]=fnd(e2[i].v);
		x+=e2[i].w;
		cnt3--;
		if(cnt3==1) break;
	}
//	printf("%lld\n",x);
	return x;
}
ll ans;
ll ans2=(ll)(1e17);
void dfs(int u){
	if(u>k){
		ans2=min(ans2,sol());
		return;
	}
	vis[u]=1;
	dfs(u+1);
	vis[u]=0;
	dfs(u+1);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	scanf("%d%d%d",&n,&m,&k);
	for(ll i=1,u,v,w;i<=m;i++){
		scanf("%lld%lld%lld",&u,&v,&w);
		edge[++cnt]={(int)u,(int)v,w};
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++) scanf("%lld",&a[i][j]);
		//sort(a[i]+1,a[i]+1+n);
	}
	if(check()){
		for(int i=1;i<=k;i++){
			edge[++cnt]=(node){0,i+n,0};
			for(int j=1;j<=n;j++) edge[++cnt]=(node){i+n,j,a[i][j]};
		}
		sort(edge+1,edge+1+cnt);
		for(int i=0;i<=n+k;i++) fa[i]=i;
		for(int i=1;i<=cnt;i++){
			if(fnd(edge[i].u)==fnd(edge[i].v)) continue;
			fa[edge[i].u]=fnd(edge[i].v);
			ans+=edge[i].w;
		}
		printf("%lld",ans);
	}
	else{
		dfs(1);
		printf("%lld",ans2);
	}
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
