#include <bits/stdc++.h>

/* if all need long long? */
#define int long long

#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define lop(i, b, a) for(int i = (b); i >= (a); i--)
#define vec vector
#define p_b push_back
#define pii pair<int, int>
#define mem(a, x) memset(a, x, sizeof a)
#define mep(a, x) memcpy(a, x, sizeof a)
#define gtt getchar
#define ptt putchar
bool AT;
namespace IO {
	template<typename T> inline void rd(T &x) {
		x = 0; int f = 1;
		char ch = gtt();
		for(; ch < '0' || ch > '9'; ch = gtt()) if(ch == '-') f = -1;
		for(; ch >= '0' && ch <= '9'; ch = gtt()) x = (x << 1) + (x << 3) + (ch ^ 48);
		x *= f;
	}
	template<typename T> inline T rd() {
		T x = 0; int f = 1;
		char ch = gtt();
		for(; ch < '0' || ch > '9'; ch = gtt()) if(ch == '-') f = -1;
		for(; ch >= '0' && ch <= '9'; ch = gtt()) x = (x << 1) + (x << 3) + (ch ^ 48);
		return x * f;
	}
	
	template<typename T> void wr(T x) {
		if(x < 0) x = -x, ptt('-');
		if(x > 9) wr(x / 10);
		ptt(x % 10 + '0');
	}
	inline void wr(char s) { ptt(s); }
	inline void wr(const char *s) { std::cout << s; }
	
	template<typename T> void wbg(T x) { std::cerr << x; }
	
	template<typename T, typename ...Args>
	inline void rd(T &x, Args &...args) { rd(x); rd(args...); }

	template<typename T, typename ...Args>
	inline void wr(T x, Args ...args) { wr(x); wr(args...); }	
	
	template<typename T, typename ...Args>
	inline void wbg(T x, Args ...args) { wbg(x); wbg(args...); }		
} using namespace IO;
inline void FREopen(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
}
const int N = 1e4 + 5, M = 2.5e6 + 5;
int n, m, k;
std::vec<int> e[N];
int c[15][N];
int tot;
struct edge {
	int u, v, w;
} g[M];
namespace dsu {
	int fa[N];
	void init() {
		rep(i, 1, n) fa[i] = i;
	}
	int fnd(int x) {
		return x == fa[x] ? x : fa[x] = fnd(fa[x]);
	}
}
int get_mst() {
	dsu::init();
	std::sort(g + 1, g + 1 + tot, [&](const edge &x, const edge &y) {
		return x.w <= y.w;
	});
	int mst = 0, chos = 0;
	rep(i, 1, tot) {
		int u = dsu::fnd(g[i].u), v = dsu::fnd(g[i].v);
		if(u != v) {
			mst += g[i].w;
			dsu::fa[u] = v;
			if(++chos == n - 1) break;
		}
	}
	return mst;
}
namespace TaskA {
	bool chk() {
		int cnt = k * (n + 1);
		rep(j, 1, k)
			rep(i, 0, n)
				cnt -= !c[j][i];
		
		cnt = k;
		rep(j, 1, k) cnt -= !c[j][0];
				
		return cnt == 0;
	}
	void sol() {
		rep(j, 1, k)
			rep(i, 0, n) if(i) g[++tot] = {j, i, c[j][i]};
		wr(get_mst(), '\n');
	}
}
bool ED;
signed main() {
	FREopen();
//	freopen("D:\\down\\road\\road3.in", "r", stdin);
	wbg((&ED - &AT) / 1024.0 / 1024, "\n");
	rd(n, m, k);
	rep(i, 1, m) {
		int u = rd<int>(), v = rd<int>(), w = rd<int>();
		e[u].p_b(v), e[v].p_b(u);
		g[++tot] = {u, v, w};
	}
	rep(j, 1, k) {
		rep(i, 0, n) rd(c[j][i]);
	}
	if(!k) wr(get_mst(), '\n');
	else if(TaskA::chk()) TaskA::sol();
	return 0;
}
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
