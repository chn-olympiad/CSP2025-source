#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#define ll long long
#define pb push_back
using namespace std;
const int N=1e4+15, M=2e6+5;
int n, m, k, a[11][N], f[15], c[15]; // f:第一次进入村的花费
ll ans;
bool used[15], vis[N], flag;
struct E{
	int from, to, w;
	E(){}
	E(int U, int V, int W){ from=U, to=V; w=W; }
	bool operator>(const E X)const{ return w > X.w; }
};
vector<E> e[N];
priority_queue<E, vector<E>, greater<E> > h;

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d %d %d", &n, &m, &k);
	int cnt = n-1;
	for(int i=1; i<=m; i++){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		e[u].pb(E(u, v, w)); e[v].pb(E(v, u, w));
	}
	for(int i=1; i<=k; i++){
		int w;
		scanf("%d", &c[i]);
		for(int j=1; j<=n; j++){
			scanf("%d", &w);
			e[j].pb(E(j, i+n, w+c[i]));
			e[n+i].pb(E(i+n, j, w));
		}
	}
	if(!c[1] && !c[2] && !c[3]){
		vis[1] = true;
		for(int i=1; i<=k; i++){
			int p;
			for(E x: e[i+n]){
				if(!x.w) p = x.to;
			}
			for(E x: e[i+n]){
				e[p].pb(E(p, x.to, x.w));
				e[x.to].pb(E(x.to, p, x.w));
			}
		}
		for(E x: e[1]) h.push(x);
		while(cnt){
			E x = h.top(); h.pop();
			if(vis[x.to] || x.to>n) continue;
			vis[x.to] = true;
			ans += x.w;
			for(E& y: e[x.to]) h.push(y);
			cnt--;
		}
		printf("%lld", ans);
	}
	else{
		for(E& x: e[1]){ h.push(x); }
		vis[1] = true;
		while(cnt){
			E x = h.top(); h.pop();
			if(vis[x.to]) continue;
			vis[x.to] = true;
	//		printf("Add Edge %d to %d, weight = %d\n", x.from, x.to, x.w);
			ans += x.w; 
			for(E& y: e[x.to]) h.push(y);
			if(x.to > n){
				f[x.to-n] = x.w;
			}
			else cnt--;
			if(x.from > n) used[x.from-n] = true;
		}
		for(int i=1; i<=k; i++){
			if(!used[i]) ans -= f[i];
		}
		printf("%lld", ans);
	}
	return 0; 
}
