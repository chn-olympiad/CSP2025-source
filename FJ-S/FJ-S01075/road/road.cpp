#include<bits/stdc++.h>
using namespace std;
long long n,m,k,c[15],a[15][10015],mn[15],dis[10015],frt,qtm[10015],ans=0x3f3f3f3f3f3f3f3fll,fa[10015],cost,
sn[10015];
bool vis[10015],vis2[10015];
struct edge{
	long long v;
	long long w;
};
vector<edge>e[10015],t[10015];
queue<long long>q;
void dfs(long long x){
	vis[x]=1;
	for(auto i:e[x]){
		if(!vis[i.v]&&dis[i.v]>=dis[x]+i.w){
			t[x].push_back(i);
			t[i.v].push_back({x,i.w});
			dfs(i.v);
		}
	}
	return;
}
void dfs2(long long x){
	vis2[x]=1;
	for(int i=0;i<t[x].size();i++){
		if(!vis2[t[x][i].v]){
			sn[x]=t[x][i].v;
			dfs2(t[x][i].v);
		}
		if(vis2[t[x][i].v]){
			fa[x]=i;
		}
	}
	return;
}
//void solve(long long cnty){
//	if(cnty==k+1){
//		long long res=0;
//		for(long long i=1;i<=n;i++){
//			for(auto j:t[i]){
//				res+=j.w;
//			}
//		}
//		ans=min(ans,res);
//		return;
//	}
//	vector<edge>tmp[10015];
//	for(long long i=1;i<n+k;i++){
//		for(auto j:t[i]){
//			tmp[i].push_back(j);
//		}
//	}
//	solve(cnty+1);
//	dfs2(mn[cnty]);
//	fa[mn[cnty]]=t[mn[cnty]].size();
//	t[mn[cnty]].push_back({cnty+n,a[cnty][mn[cnty]]});
//	int cstmp=cost;
//	cost+=c[cnty];
//	for(int i=1;i<=n+k;i++){
//		if(t[i][fa[i]].w>a[cnty][i]){
//			t[t[i][fa[i]].v][sn[i]]={t[i][fa[i]].v,0};
//			t[i][fa[i]].v=n+cnty;
//			t[i][fa[i]].w=a[cnty][i];
//			t[n+cnty].push_back({i,a[cnty][i]});
//		}
//	}
//	solve(cnty+1);
//	for(long long i=1;i<n+k;i++){
//		t[i].clear();
//		for(auto j:tmp[i]){
//			t[i].push_back(j);
//		}
//	}
//	cost=cstmp;
//	return;
//}
int main(){
	memset(dis,63,sizeof(dis));
	dis[1]=0;
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=n+1;i<=n+k;i++){
		for(int j=n+1;j<=n+k;j++){
			a[i][j]=0x3f3f3f3f3f3f3f3fll;
		}
	}
	for(long long i=1,u,v,w;i<=m;i++){
		scanf("%lld%lld%lld",&u,&v,&w);
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	for(long long i=1;i<=k;i++){
		scanf("%lld",c+i);
		for(long long j=1;j<=n;j++){
			scanf("%lld",&a[i][j]);
			if(j==1){
				mn[i]=1;
			}
			else{
				if(a[i][mn[i]]>a[i][j]){
					mn[i]=j;
				}
			}
		}
	}
	q.push(1);
	qtm[1]++;
	while(!q.empty()){
		while(!q.empty()){
			frt=q.front();
			q.pop();
			if(!--qtm[frt]){
				for(auto i:e[frt]){
					if(dis[frt]+i.w<dis[i.v]){
						dis[i.v]=dis[frt]+i.w;
						qtm[i.v]++;
						q.push(i.v);
					}
				}
			}
		}
	}
	dfs(1);
//	solve(1);
ans=0;
for(int i=1;i<=n;i++){
	for(auto j:t[i]){
		ans+=j.w;
	}
}
	printf("%lld",ans/2);
	return 0;
}
