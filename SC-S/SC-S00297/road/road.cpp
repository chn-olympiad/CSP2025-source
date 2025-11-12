#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>

// You came into my life, just like-ke another SEASON!!
// Road Archive ~~
using namespace std;
const int MAX_N = 1e4+20, MAX_M = 1e6+1e5+20;
int n, m, k, c[15], a[MAX_N];
struct Edge{
	int u, v, w;
	void init(int _u=0, int _v=0, int _w=0){u = _u, v = _v, w = _w;};
	bool operator<(const Edge &rhs)const{
		return w < rhs.w;
	}
}edges[MAX_M];

// BIT
int fa[MAX_N];
inline void init(){
	for(int i=1;i<=n;++i)fa[i]=i;
}

int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}

void merge(int a, int b){
	fa[find(a)]=find(b);
}

int main(){
	cin.tie(0)->sync_with_stdio(false);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >>n >> m >> k;
	for(int i=1, u, v, w;i<=m;++i){
		cin >> u >> v >> w;
		edges[i].init(u, v, w);
	}
	for(int i=1;i<=k;++i){
		cin >> c[i];
		int p = 0;
		for(int j=1;j<=n;++j){
			cin >> a[j];
			a[j] += c[i];
			if(a[j]==0)p=j;
		}
//		if(p==0)printf("Method not support!! c(%d)\n", c[i]);
		if(p==0)p=max(n-6,1); // Hope I'm lucky enough
		for(int i=1;i<=n;++i){
			edges[++m].init(p, i, a[i]);
		}
	}
	sort(edges+1, edges+1+m);
	init();
	long long ans=0; int cnt=0;
	for(int i=1;i<=m;++i){
		int u = edges[i].u, v = edges[i].v, w = edges[i].w;
		if(find(u)==find(v))continue;
		ans += w;
		merge(u, v);
		if(++cnt >= n)break;
	}
	cout << ans <<endl;
	
}
