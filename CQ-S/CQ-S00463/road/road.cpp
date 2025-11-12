#include <bits/stdc++.h>
#define re register
#define int long long
#define chmin(a,b) (a = min(a,b))

using namespace std;

const int N = 2e4 + 10,M = 1e6 + 10;
const int K = 24,P = (1 << 10) + 10;
const int inf = (int)(1e18) + 10;
int n,m,k,ans;
int fp[N],cst[K],p[K][N];

struct Edge{
	int u,v,w;
	
	bool friend operator <(const Edge &a,const Edge &b){ return a.w < b.w; }
}E[M];
vector<Edge> fe[P];

inline int read(){
	int r = 0,w = 1;
	char c = getchar();
	while (c < '0' || c > '9'){
		if (c == '-') w = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9'){
		r = (r << 1) + (r << 3) + (c ^ 48);
		c = getchar();
	}
	return r * w;
}

inline int find(int x){
	if (x == fp[x]) return fp[x];
	else return fp[x] = find(fp[x]);
}

inline void merge(int a,int b){
	int x = find(a),y = find(b);
	if (x != y) fp[x] = y;
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n = read(),m = read(),k = read();
	for (re int i = 1;i <= n;i++) fp[i] = i;
	for (re int i = 1,a,b,c;i <= m;i++){
		a = read(),b = read(),c = read();
		E[i] = {a,b,c};
	} sort(E + 1,E + m + 1);
	for (re int i = 1;i <= k;i++){
		cst[i] = read();
		for (re int j = 1;j <= n;j++) p[i][j] = read();
	}
	for (re int i = 1;i <= m;i++){
		int u = E[i].u,v = E[i].v;
		if (find(u) == find(v)) continue;
		fe[0].push_back(E[i]);
		ans += E[i].w; merge(u,v);
	}
//	cerr << ans << " ???\n";
	for (re int st = 1;st < (1 << k);st++){
		int res = 0;
		for (re int i = 1;i <= k;i++){
			if ((st >> (i - 1)) & 1) res += cst[i];
		}
		for (re int i = 1;i <= k;i++){
			if ((st >> (i - 1)) & 1){
				vector<Edge> F;
				fe[st] = fe[st ^ (1 << (i - 1))];
				for (re int i = 1;i <= n + k;i++) fp[i] = i;
				for (re int j = 1;j <= n;j++) fe[st].push_back({i + n,j,p[i][j]});
				sort(fe[st].begin(),fe[st].end());
				for (Edge e:fe[st]){
					int u = e.u,v = e.v;
					if (find(u) == find(v)) continue;
//					if (st == 1) cerr << u << " " << v << " " << e.w << " !!!\n";
					res += e.w; merge(u,v); F.push_back(e);
				} swap(fe[st],F);
				break;
			}
		} chmin(ans,res);
//		cerr << st << " " << res << " ???\n";
	} printf("%lld",ans);
	return 0;
}

/*
2^k * nk log nk => 80pts
*/
