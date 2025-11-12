#include <bits/stdc++.h>

/* if all need long long? */
//#define int long long

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
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
}
const int N = 2e5 + 5;
int n, ans;
struct cst {
	int b[4], id;
} a[N], _a[N];
int c[N], d[N];
namespace Task1 {
	int f[3][105][105][105];
	void sol() {
		mem(f, 0);
		f[1][1][0][0] = a[1].b[1], f[1][0][1][0] = a[1].b[2], f[1][0][0][1] = a[1].b[3];
		rep(i, 2, n) {
			rep(j, 0, n / 2)
				rep(k, 0, n / 2)
					rep(l, 0, n / 2) {
						int now = i & 1, lst = now ^ 1;
						if(j) f[now][j][k][l] = std::max(f[now][j][k][l], f[lst][j - 1][k][l] + a[i].b[1]);
						if(k) f[now][j][k][l] = std::max(f[now][j][k][l], f[lst][j][k - 1][l] + a[i].b[2]);
						if(l) f[now][j][k][l] = std::max(f[now][j][k][l], f[lst][j][k][l - 1] + a[i].b[3]);
					}
		}
		
		int h1, h2, h3;
		
		rep(j, 0, n / 2)
			rep(k, 0, n / 2)
				rep(l, 0, n / 2)
					if(j + k + l == n) {
						
						if(f[n & 1][j][k][l] > ans) {
							h1 = j, h2 = k, h3 = l;
							ans = std::max(ans, f[n & 1][j][k][l]);
						}
					}
					
		wr(ans, '\n');		
	}
}
namespace Task2 {
	bool chk() {
		int cnt = 0;
		rep(i, 1, n)
			if(!a[i].b[2] && !a[i].b[3]) cnt++;
		return cnt == n;
	}
	void sol() {
		std::sort(a + 1, a + 1 + n, [&](const cst &x, const cst &y) {
			return x.b[1] > y.b[1];
		});
		rep(i, 1, n / 2) ans += a[i].b[1];
		wr(ans, '\n');
	}
}
namespace Task3 {
	void sol() {
		rep(j, 1, 3) {
			rep(i, 1, n) a[i] = _a[i];
			
			int res = 0;
			rep(i, 1, n) {
				if(j == 1) d[i] = std::max(a[i].b[2], a[i].b[3]);
				if(j == 2) d[i] = std::max(a[i].b[1], a[i].b[3]);
				if(j == 3) d[i] = std::max(a[i].b[1], a[i].b[2]);
				c[i] = a[i].b[j] - d[i];
			}
			std::priority_queue<int, std::vec<int>, std::greater<int> > q;
			
			std::sort(a + 1, a + 1 + n, [&](const cst &x, const cst &y) {
				return c[x.id] < c[y.id];
			});
			
	//		wr("id:\n");
	//		rep(i, 1, n) wr(a[i].id, ' ');
	//		wr('\n');
			
			rep(i, 1, n) {
				if(j == 1) d[i] = std::max(a[i].b[2], a[i].b[3]);
				if(j == 2) d[i] = std::max(a[i].b[1], a[i].b[3]);
				if(j == 3) d[i] = std::max(a[i].b[1], a[i].b[2]);
				c[i] = a[i].b[j] - d[i];
			}		
			
			rep(i, 1, n / 2) {
				
				
				q.push(c[i]);
				
				res += a[i].b[j];
				
			}
			rep(i, n / 2 + 1, n) {
				res += d[i];
			}
			
			ans = std::max(ans, res);
			rep(i, n / 2 + 1, n) {
				int y = q.top(); q.pop();
				res += c[i] - y;
				
				ans = std::max(ans, res);
				q.push(c[i]);
			}
		}
		wr(ans, '\n');		
	}
}
void sol() {
	rd(n), ans = 0;
	rep(i, 1, n) {
		rd(a[i].b[1], a[i].b[2], a[i].b[3]), a[i].id = i;
		_a[i] = a[i];
	}
	
	if(n <= 200) Task1::sol();
	else if(Task2::chk()) Task2::sol();
	else Task3::sol();
//	Task3::sol();
}
bool ED;
signed main() {
	FREopen();
//	freopen("dataT1.in", "r", stdin);
//	freopen("club.out", "w", stdout);
//	freopen("D:\\down\\club\\club5.in", "r", stdin);
	wbg((&ED - &AT) / 1024.0 / 1024, "\n");
	for(int T = rd<int>(); T--; sol());
	return 0;
}
/*
1
4
4 2 1
3 2 4
5 3 4
3 5 1

1
10
2020 14533 18961
2423 15344 16322
1910 6224 16178
2038 9963 19722
8375 10557 5444
3518 14615 17976
6188 13424 16615
8769 509 4394
958 3195 9953
16441 5313 10926

147325
*/
