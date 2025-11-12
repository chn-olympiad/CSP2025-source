#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1e4 + 5;

void solve();
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	solve();
	return 0;
}
int n,m,k;
using edge = unsigned long long;
edge turn_into_edge(int w,short u,short v) {
	edge ret = w;
	ret = ret * (1ll<<32) | (int)(u) * (1ll<<16) | v;
	return ret;
}
#define w(x) ((x) >> 32)
#define u(x) (((x) >> 16) & 0xffff)
#define v(x) ((x) & 0xffff)
set<edge>ggg;
int c[15];
int a[15][maxn];
//---dsu begin
short fa[maxn];
short sz[maxn];
void init() {
	for(int i = 1; i<=n; ++i)fa[i] = i,sz[i] = 1;
}
void merge(int x,int y) {
	if(sz[x]>sz[y])swap(x,y);
	fa[x] = y;
	sz[y] += sz[x];
}
int find(int x) {
	return (fa[x] != x) ? find(fa[x]) : x;
}
//---dsu end
inline ll kruscal() {
	init();
	int cnt = n;
	ll ans(0);
	for(edge i : ggg) {
		if(cnt == (1+k)) return ans;
		int fx = find(u(i)),fy = find(v(i));
		if(fx != fy) {
			--cnt;
			merge(fx,fy);
			ans += w(i);
		}
	}
	return ans;
}
ll ans= 1e18;
void solve() {
	cin>>n>>m>>k;
	for(int i = 0; i<m; ++i) {
		int p,q,r;
		cin>>p>>q>>r;
		ggg.insert(turn_into_edge(r,p,q) );
	}
	cout<<kruscal();
}

