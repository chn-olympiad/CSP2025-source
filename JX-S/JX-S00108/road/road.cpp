#include <cstdio>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
int const N = 1e4;
int const M = 1e6;
int const K = 11;
vector<pair<int,int> > G[N+K];// first->cost , second -> to
vector<pair<int,int> > G2[N+K]; // when temp defined
int tn;
int cs[K];
int G3[K][N];
bool vis[N+K];//no of villi : N + i
unsigned long long prim(int c0){
	for(int i=0;i<N+K;i++)vis[i] = false;
	priority_queue<pair<int,int> ,vector<pair<int,int> >,greater<pair<int,int> > >pq;
	pq.push(make_pair(0,1));
	int tot = 0;
	unsigned long long cost = c0;
	while(!pq.empty()){
		pair<int,int> p = pq.top();
		pq.pop();
		if(vis[p.second]) continue;
		vis[p.second] = true;
		cost += p.first;
		tot++;
		for(int i=0;i<G[p.second].size();i++){
			pq.push(G[p.second][i]);
		}
		for(int i=0;i<G2[p.second].size();i++){
			pq.push(G2[p.second][i]);
		}
		if(tot==tn)break;
	}
	return cost;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0;i<m;i++){
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);
		G[u].push_back(make_pair(w,v));
		G[v].push_back(make_pair(w,u));
	}
	for(int i=0;i<k;i++){
		scanf("%d",cs+i);
		for(int j=1;j<=n;j++){
			scanf("%d",&G3[i][j]);
		}
	}
	unsigned long long cost = N*1LL*M;
	for(int z=0;z<1<<k;z++){
		for(int i=0;i<N+K;i++)G2[i].clear();
		int c0 = 0;
		int f0 = 0;
		for(int i=0;i<k;i++){
			if(z&(1<<i)){
				c0 += cs[i];
				f0++;
				for(int j=1;j<=n;j++){
					G2[j].push_back(make_pair(G3[i][j],N+i));
					G2[N+i].push_back(make_pair(G3[i][j],j));
				}
			}
		}
		tn = f0 + n;
		unsigned long long tt = prim(c0);
		if(tt<cost){
			cost = tt;
		}
	}
	printf("%lld",cost);
	return 0;
}