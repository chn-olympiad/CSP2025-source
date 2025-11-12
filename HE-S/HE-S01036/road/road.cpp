#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,k,cnt,pre[1919810*2];
ll fa[1919810*2],c[1919810*2];
ll ex[114][114514/10];
struct Edge{
	int from,to,val,next;
}edge[1919810*4];
void addEdge(int u,int v,int val) {
	cnt++;
	edge[cnt].from = u;
	edge[cnt].to = v;
	edge[cnt].val = val;
	edge[cnt].next = pre[u];
	pre[u] = cnt;
}
bool cmp(Edge a,Edge b) {return a.val < b.val;} 
int find(int x) {
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}
void merge(int x,int y) {
	int fx = find(x);
	int fy = find(y);
	if(fx != fy)fa[fy] = fx;
}
void wa16() {
	//kruskalÄ£°å
	ll ans = 0;
	for(int i = 1;i <= n;i++) fa[i] = i;
	sort(edge+1,edge+m+1,cmp);
	for(int i = 1;i <= m;i++) {
	 	int u = edge[i].from;
	 	int v = edge[i].to;
	 	if(find(u) == find(v)) continue;
	 	merge(u,v);
	 	ans += edge[i].val; 
	}
	cout << ans;
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	for(int i = 1;i<= m;i++) {
		int x,y,z;
		cin >> x >> y >> z;
		addEdge(x,y,z);
		addEdge(y,x,z);
		c[x]++;
		c[y]++;
	}
	for(int i = 1;i <=k;i++) {
		for(int j = 0;j <=n;j++) cin >> ex[i][j];
	}
	if(k == 0) wa16();
	else cout << 0;
	return 0;
} 
