#include <iostream>
#include <algorithm>
#include <vector>
#define int long long
using namespace std;
const int N=1e4+5,M=2e5+5,inf=1e18;
int n,m,k,ans,fa[N],a[N],lw[N],cnt;
int mp[N];
int type[N],cost[N];
bool use[N],vis1[N],vis2[N];
struct E{
	int u,v,w;
	bool operator <(const E &x){
		return w<x.w;
	}
}e1[N];
vector<E> e[N];
vector<int> p;
int fi(int u){
	if(fa[u]==u) return u;
	else return fa[u]=fi(fa[u]);
}
void dfs(int u,int fa){
	for(int i=e[u].size()-1;i>=0;i--){
		int v=e[u][i].v;
		if(v==fa) continue;
		lw[v]=e[u][i].w;
		dfs(v,u);
	}
}
void init(){
	for(int i=1;i<=n;i++) fa[i]=i;
}
void init1(){
	for(int i=1;i<=n;i++) vis2[i]=vis1[i]=0;
	p.clear();
}
int minn(){
	int minn1=inf;
	for(int q=1;q<=n;q++) if(!vis1[q]) minn1=min(minn1,mp[q]);
	return minn1;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++) scanf("%lld%lld%lld",&e1[i].u,&e1[i].v,&e1[i].w);
	sort(e1+1,e1+m+1);
	init();
	for(int i=1;i<=m;i++) {
		int u=e1[i].u,v=e1[i].v,w=e1[i].w;
		if(fi(u)!=fi(v)) {
			e1[++cnt]=e1[i];
			fa[fi(u)]=fi(v);
			ans+=w;
		}
	}
	
	for(int i=1;i<=n-1;i++){
		int u=e1[i].u,v=e1[i].v,w=e1[i].w;
		e[u].push_back({0,v,w});
		e[v].push_back({0,u,w});
	}
	
	dfs(1,0);
	for(int i=1;i<=k;i++){
		scanf("%lld",a+i);
		for(int j=1;j<=n;j++) scanf("%lld",mp+j);
		init1();
		int nowcost=0,sum1=0;
		for(int j=1;j<=k;j++){
			if(!use[j]) continue;
			int sum2=0;
			for(int q=2;q<=n;q++) if(type[q]==j) sum2+=mp[q],vis1[q]=1;
			if(sum2+sum1+minn()<=nowcost+cost[j]){
				sum1=sum2+sum1+minn(),nowcost=nowcost+cost[j];
				p.push_back(j);
				for(int q=1;q<=n;q++) if(type[q]==j) vis2[q]=1;
			}
		}
		int sum2=0;
		for(int j=2;j<=n;j++) {
			if(vis2[j]) continue;
			if(lw[j]>mp[j]) sum1+=mp[j],vis2[j]=1;
			else sum2+=lw[j];
		}
		if(sum1+sum2+minn()+a[i]<=ans) {
			cost[i]=sum1+minn()+a[i];
			use[i]=1;
			ans=sum1+sum2+minn()+a[i];
			for(int j=1;j<=n;j++) if(vis2[j]) type[j]=i,lw[j]=mp[j];
			for(int j=p.size()-1;j>=0;j--) use[j]=p[j];
		}
	}
	printf("%lld",ans);
}
