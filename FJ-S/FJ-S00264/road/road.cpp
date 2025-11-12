#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
//#define int long long
//#define int unsigned long long
#define PII pair<int,int>
using namespace std;
const int N = 1e6+10;
int cnt,head[N],k,n,m,dis[N],vis[N],ka[N];
struct Edge {
	int to,next,w,KK;
}e[N];
void add(int u,int v,int w,int K) {
	e[++cnt] = {v,head[u],w,K};
	head[u] = cnt;
}
void Prim() {
	dis[1] = 0;
	memset(dis,0x3f,sizeof dis);
	priority_queue <PII,vector <PII>,greater <PII> > q;
	q.push({0,1});
	while(!q.empty()) {
		int u = q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(int i = head[u]; i; i = e[i].next) {
			int v = e[i].to;
			if(dis[v] > e[i].w) {
				if(e[v].KK != -1) dis[v] = e[i].w - ka[e[i].KK];
				else dis[v] = e[i].w;
				q.push({dis[v],v});
			}
		}
	}
}
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++) {
		int x,y,z;
		cin >> x >> y >> z;
		add(x,y,z,-1);
		add(y,x,z,-1);
	}
	for(int i = 1; i <= k; i++) {
		int tmp;
		cin >> tmp;
		ka[i] = tmp;
		add(0,i,tmp,i);
		add(i,0,tmp,i);
		for(int j = 1; j <= n; j++) {
			int ww;
			cin >> ww;
			if(i == j) continue;
			add(i,j,ww+tmp,i);
			add(j,i,ww+tmp,i);
		}
	}
	Prim();
	int ans = 0;
	for(int i = 0; i <= n; i++) {
		if(dis[i] != 0x3f3f3f3f) {
			ans += dis[i];
		}
	}
	cout << ans;
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
