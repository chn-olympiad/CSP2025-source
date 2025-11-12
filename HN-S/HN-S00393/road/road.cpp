#include <bits/stdc++.h>
using namespace std;
int fa[200005],siz[200005];
class UnionSet {
public:
	inline void init(int n) {
		for(int i = 1;i <= n;i++) fa[i] = i,siz[i] = 1;
	}
	inline int find(int x) {
		return fa[x] == x ? x : fa[x] = find(fa[x]);
	}
	inline void merge(int a,int b) {
		a = find(a),b = find(b);
		if(siz[a] > siz[b]) fa[b] = a,siz[a] += siz[b];
		else fa[a] = b,siz[b] += siz[a];
	}
};
struct Edge {
	int u,v,w;
	inline bool operator<(const Edge i) const {
		return w < i.w;
	}
} ee[1000005];
int n,m,k;
Edge e[10005],kk[100005],tmp[110005];
int top1,top2;
int a[10005][15];
long long c[15];
long long answer = 0x3f3f3f3f3f3f3f3f;
void qwqKruskal(Edge ee[],long long ben,int siz) {
	sort(ee + 1,ee + 1 + siz);
	long long ans = ben;
	UnionSet u;
	u.init(n + k);
	for(int i = 1;i <= siz;i++) {
		if(u.find(ee[i].u) == u.find(ee[i].v)) continue;
		ans += ee[i].w;
		u.merge(ee[i].u,ee[i].v);
	}
	answer = min(answer,ans);
} 
void dfs(int u,long long ben) {
	if(u > k) {
		for(int i = 1;i <= top1;i++) tmp[i] = e[i];
		for(int i = 1;i <= top2;i++) tmp[i + top1] = kk[i];
		qwqKruskal(tmp,ben,top1 + top2);
		return;
	}
	dfs(u + 1,ben);
	for(int i = 1;i <= n;i++) {
		kk[++top2] = {u + n,i,a[i][u]};
	}
	dfs(u + 1,ben + c[u]);
	top2 -= n;
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++) {
		cin >> ee[i].u >> ee[i].v >> ee[i].w;
	}
	sort(ee + 1,ee + 1 + m);
	UnionSet u;
	u.init(n);
	for(int i = 1;i <= m;i++) {
		if(u.find(ee[i].u) == u.find(ee[i].v)) continue;
		e[++top1] = ee[i];
		u.merge(ee[i].u,ee[i].v);
	}
	for(int i = 1;i <= k;i++) {
		cin >> c[i];
		for(int j = 1;j <= n;j++) {
			cin >> a[j][i];
		}
	}
	dfs(1,0);
	cout << answer;
	return 0; 
} 
