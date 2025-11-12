#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

struct eee {
	int u , v; ll w; 
	bool operator < (const eee b){ return w < b.w; }
}yy[1000005];

namespace kkk {
	int n , m;
	eee e[200005];
	
	int fa[10055];
	int find(int x){
		if(fa[x] == x) return x;
		return fa[x] = find(fa[x]);
	}
	
	void build(int a , int b , eee c[200005]){
		n = a; m = b;
		for(int i = 1;i <= m;i++) e[i] = c[i];
	}
	
	ll run(){
		sort(e + 1 , e + 1 + m);
		for(int i = 1;i <= n;i++) fa[i] = i;
		int cnt = 0;
		ll ret = 0;
		for(int i = 1;i <= m;i++){
			int u = find(e[i].u) , v = find(e[i].v);
			if(u == v) continue;
			fa[u] = v;
			ret += e[i].w;
			if(++cnt >= n - 1) break;
		}
		return ret;
	}
}

int n , m , k , a[11][10005];

namespace shuo{
	int fa[10005];
	int find(int x){
		if(fa[x] == x) return x;
		return fa[x] = find(fa[x]);
	}
	
	eee zbj[100005];
	void run(){
		sort(yy + 1 , yy + 1 + m);
		for(int i = 1;i <= n;i++) fa[i] = i;
		int cnt = 0;
		for(int i = 1;i <= m;i++){
			int u = find(yy[i].u) , v = find(yy[i].v);
			if(u == v) continue;
			fa[u] = v;
			zbj[++cnt] = yy[i];
			if(cnt >= n - 1) break;
		}
		m = n - 1;
		for(int i = 1;i <= m;i++) yy[i] = zbj[i];
	}
}

ll solve(int x){
	ll ret = 0;
	int nem = m , nen = n;
	for(int i = 1;i <= k;i++) if(x >> (i - 1) & 1){
		ret += a[i][0];
		++nen;
		for(int j = 1;j <= n;j++) yy[++nem] = (eee){nen , j , a[i][j]};
	}
	kkk::build(nen , nem , yy);
	return ret + kkk::run();
}

ll read(){
	char c = getchar();
	ll ret = 0;
	while(c < '0' || c > '9') c = getchar();
	while(c >= '0' && c <= '9'){
		ret = ret * 10 + c - '0';
		c = getchar();
	}
	return ret;
}

int main(void){
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
//	freopen("road3.in" , "r" , stdin);
	n = read(); m = read(); k = read();
	for(int i = 1;i <= m;i++){
		yy[i].u = read();
		yy[i].v = read();
		yy[i].w = read();
	}
	for(int z = 1;z <= k;z++) for(int i = 0;i <= n;i++)
		a[z][i] = read();
	shuo::run();
	ll ans = 1e16;
	for(int i = 0;i <= (1 << k) - 1;i++)
		ans = min(ans , solve(i));
	printf("%lld\n" , ans);
	return 0;
}
