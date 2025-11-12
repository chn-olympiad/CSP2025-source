#include<bits/stdc++.h>
using namespace std;
#define LL long long

struct edge{
	LL v,w;
};

struct city{
	LL w;
};

const int N = 10 * 1e6 + 5;
LL n,m,k;
vector<edge> e[2 * N];
LL fa[2 * N],vis[N];

LL find(LL x){
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}

void unionset(LL x,LL y){
	x = find(x),y = find(y);
	if(x == y) return;
	fa[x] = y;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(LL i = 1;i <= n;i++) fa[i] = i;
	for(LL i = 1;i <= m;i++){
		LL u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	vector<LL> c(k + 1);
	vector<city> min_w(n + 1); 
	for(LL i = 1;i <= k;i++){
		scanf("%lld",&c[i + n]);
		for(LL j = 1;j <= n;j++){
			scanf("%lld",&min_w[i].w);
			e[i + n].push_back({j,min_w[i].w});
			e[j].push_back({i + n,min_w[i].w});
		} 
	}
	//Dijkstra
	LL d[N],cnt = 0;
	for(LL i = 1;i <= n;i++) d[i] = 0x3f3f3f3f;
	priority_queue< pair<LL,LL> > q;
	d[1] = 0;
	q.push({0,1});
	while(!q.empty()){
		LL dis_u = -q.top().first;
		LL u = q.top().second;
		q.pop();
		if(vis[u] || dis_u > d[u]) continue;
		vis[u] = 1;
		for(auto ed : e[u]){
			cnt = 0;
			LL v = ed.v,w = ed.w;
			if(v > n){
				if(cnt == 0){
					if(d[v] > d[u] + w + c[u]){
						d[v] = d[u] + w + c[u];
						q.push({-d[v],v});
						cnt++;
					}
				}
			}else{
				if(d[v] > d[u] + w){
					d[v] = d[u] + w;
					q.push({-d[v],v});
				}
			}
		}
	}
	cout << d[n] << endl;
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
