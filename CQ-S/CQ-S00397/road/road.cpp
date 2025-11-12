#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 20086, M = 2000086, inf = 0x3f3f3f3f, mod = 998244353;
struct node{
	int to, w, nxt;
}ed[M];
int head[N], cnt = 0;
void addedge(int u, int v, int w){
	ed[++cnt] = (node){v, w, head[u]};
	head[u] = cnt;
}
int n, m, k, c[N], a[13][N];
struct qwq{
	int u, v, w;
	bool operator < (const qwq ttt) const{
		return w > ttt.w;
	}
};
int fa[N];
int find(int x){
	if(!fa[x]) return fa[x] = x;
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}
priority_queue <qwq> q;



int mn[1002][1002], mx = 0;
int main(){//20~32
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= m; i++){
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		addedge(u, v, w);
		addedge(v, u, w);
		q.push((qwq){u, v, w});
	}
	for(int i = 1; i <= k; i++){
		scanf("%d", &c[i]);
		mx = max(mx, c[i]);
		for(int j = 1; j <= n; j++) scanf("%d", &a[i][j]);
	}
	if(k == 0){
		ll ans = 0;
		int cnt = 0;
		while(q.size()){
			qwq t = q.top();
			q.pop();
			if(find(t.u) != find(t.v)){fa[find(t.u)] =  find(t.v); ans += t.w; cnt++;}
		}
		printf("%lld", ans);
	}
	else if(mx == 0){
		if(n <= 1000){
			memset(mn, inf, sizeof mn);
			for(int i = 1; i <= k; i++)
				for(int u = 1; u <= n; u++)
					for(int v = u + 1; v <= n; v++)
						mn[u][v] = min(mn[u][v], a[i][u] + a[i][v]);
			for(int u = 1; u <= n; u++)
				for(int v = u + 1; v <= n; v++)	{
					q.push((qwq){u, v, mn[u][v]});
					q.push((qwq){v, u, mn[u][v]});
				}
			ll ans = 0;
			int cnt = 0;
			while(q.size() && cnt < n - 1){
				qwq t = q.top();
				q.pop();
				if(find(t.u) != find(t.v)){fa[find(t.u)] =  find(t.v); ans += t.w, cnt++;}
			}
			printf("%lld", ans);		
		}
		
	}
	return 0;
	
	
	
}
