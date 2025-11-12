#include<bits/stdc++.h>
using namespace std;
struct node {
	long long v, w;
};
struct node2 {
	long long v, w,flag,fa;
};
vector<node>q[100000 + 100];
bool operator<(node2 a, node2 b) {
	return a.w > b.w;
}
priority_queue<node2>que;
long long ans = 0,c[50],d[50],cnt=0,dis[100000+100];
bool vis[100000 + 100] = {0};
int main() {
	memset (dis,0x7f,sizeof(dis));
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n, m, k;
	scanf("%lld%lld%lld",&n,&m,&k);
	for (long long i = 1; i <= m; i++) {
		long long u, v, w;
		scanf("%lld%lld%lld",&u,&v,&w);
		q[u].push_back({v, w});
		q[v].push_back({u, w});
	}
	for(long long i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		d[i]=c[i];
		for(long long j=1;j<=n;j++){
			long long t;
			scanf("%lld",&t);
			q[n+i].push_back({j,t});
			q[j].push_back({n+i,t});
		}
	}
	que.push({1, 0, 0, 0});
	while (!que.empty() && cnt<n) {
		node2 t = que.top();
		que.pop();
		if(vis[t.v]==1 && t.flag!=2)continue;
		if(t.v<=n){
			cnt++;
//			cout<<t.v<<" "<<t.w<<" "<<t.flag<<" "<<t.fa<<" "<<"\n";
			vis[t.v] = 1;
			ans+=t.w;
			if(t.flag==1 && vis[t.fa]==0){
				ans+=d[t.fa-n];
				vis[t.fa]=1;
				que.push({t.fa,0,2,0});
//				cout<<t.fa<<" "<<d[t.fa-n]<<"\n";
			}
			for (long long i = 0; i < q[t.v].size(); i++) {
				node to = q[t.v][i];
				if (vis[to.v] == 0 && to.w<dis[to.v]){
					que.push({to.v, to.w,0,t.v});
					dis[to.v]=to.w;
				}
			}
		}else{
			if(t.fa!=0){
				d[t.v-n]=t.w;
				for (long long i = 0; i < q[t.v].size(); i++) {
					node to = q[t.v][i];
					if (vis[to.v] == 0 && to.w+c[t.v-n]<dis[to.v]){
						que.push({to.v, to.w+c[t.v-n],1,t.v});
						dis[to.v]=to.w+c[t.v-n];
					}
				}
			}
			else{
				d[t.v-n]=t.w;
				for (long long i = 0; i < q[t.v].size(); i++) {
					node to = q[t.v][i];
					if (vis[to.v] == 0 && to.w<dis[to.v]){
						que.push({to.v, to.w,0,t.v});
						dis[to.v]=to.w;
					}
				}
			}
		}
		
	}
	printf("%lld",ans);
	return 0;
}
/*

5 6 0
1 2 1
1 4 2
2 4 3
2 3 1
2 5 2
3 5 3

*/