#include<bits/stdc++.h>
using namespace std;
struct edge{
	long long u,v,w;
};
bool b[20];
long long n,m,k,c[20],a[20][10010],fa[20020],fx,fy,sum,cnt,ans=1e18;
vector<edge> g,gg;
bool cmp(edge a,edge b){
	return a.w<b.w;
}
long long find(long long x){
	if(fa[x]==x){
		return x;
	}
	fa[x]=find(fa[x]);
	return fa[x];
}
void solve(){
	sum=0;
	g=gg;
	for(int i=1;i<=k;i++){
		if(b[i]==1){
			sum+=c[i];
		}
	}
	for(int i=1;i<=k;i++){
		if(b[i]==1){
			for(int j=1;j<=n;j++){
				g.push_back({n+i,j,a[i][j]});
			}
		}
	}
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
	}
	for(int i=1;i<=k;i++){
		if(b[i]==0){
			fa[n+i]=1;
		}
	}
	sort(g.begin(),g.end(),cmp);
	for(edge x:g){
		fx=find(x.u);
		fy=find(x.v);
		if(fx!=fy){
			fa[fy]=fx;
			sum+=x.w;
		}
	}
	ans=min(ans,sum);
}
void dfs(long long x){
	if(x>k){
		solve();
		return;
	}
	dfs(x+1);
	b[x]=1;
	dfs(x+1);
	b[x]=0;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long u,v,w;
	scanf("%lld %lld %lld",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%lld %lld %lld",&u,&v,&w);
		gg.push_back({u,v,w});
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%lld",&a[i][j]);
		}
	}
	dfs(1);
	printf("%lld",ans);
	return 0;
}
