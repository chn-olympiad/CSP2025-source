#include <bits/stdc++.h>
#define int long long
#define INF 0x7fffffff
using namespace std;
const int N = 1e4 + 10;
int n,m,k,ecnt,ans;
int head[N],cnt;
int c[11],cw[11][N];
int f[N];

struct Edge{
	int u, v, w;
	bool operator <(const Edge& x){
		return w < x.w;
	}
}e[200*N];


int find(int x){
	if(x != f[x]) x = find(f[x]);
	return f[x];
}


inline int read()
{
	char c; int x = 0, d = 1;
	for(;!isdigit(c);c=getchar()) if(c == '-') d = -1;
	for(;isdigit(c);c=getchar()) x = x * 10 + c - '0';
	return d * x;
}


signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	//½ö¿¼ÂÇtypeA & 1-4 
	n = read(), m = read(), k = read();
	for(int i=1;i<=n;i++) f[i] = i;
	
	for(int i=1,u,v,w;i<=m;i++){
		u = read(), v = read(), w = read();
		e[++cnt] = {u, v, w};
	}
	for(int i=1;i<=k;i++){
		c[i] = read();
		for(int j=1,w;j<=n;j++){
			w = read();
			e[++cnt] = {n + i, j, w};
		}
	}
	sort(e + 1,e + cnt + 1);	
	
	for(int i=1,u,v,w,a,b;i<=cnt;i++){
		u = e[i].u, v = e[i].v, w = e[i].w;
		a = find(u), b = find(v);
		if(a != b){
			f[a] = b, ans += w, ecnt++;
		}
		
		if(ecnt == n + k - 1) break;
	}
//	for(int i=1;i<=m;i++) printf("%d %d %d\n", e[i].u, e[i].v, e[i].w);
	
	printf("%lld", ans);
	
	return 0;
}
