//GZ-S00451 贵州师范大学云岩实验中学 闫峻浩
#include<bits/stdc++.h>
using namespace std;
long long n,m,k,ans;
vector<pair<long long,long long> >e[1000005];
void dij(int s){
	int dis[10005];
	bool hh[10005];
	priority_queue<long long,vector<long long>,greater<long long> > q;
	for(int i=1;i<=n+k;i++){
		dis[i]=10e14+5;
	}
	dis[s]=0;
	q.push(s);
	while(!q.empty()){
		int u=q.top();
		if(hh[u]==1) continue;
		hh[u]=1;
		q.pop();
		for(auto i:e[u]){
			int v=i.first,w=i.second;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push(v);
			}
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	long long u,v,w;
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&u,&v,&w);
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		int ci,ai;
		scanf("%lld",&ci);
		for(int j=1;j<=n;j++){
			scanf("%lld",&ai);
			e[i+n].push_back({j,ci+ai});
			e[j].push_back({i+n,ci+ai});
		}
	}
	for(int i=1;i<=n+k;i++){
		dij(i);
	}
	printf("%lld",ans);
	return 0;
} 
