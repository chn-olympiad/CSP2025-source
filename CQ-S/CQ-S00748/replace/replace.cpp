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
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
}
const int N = 2e5 + 5;
int n, q;
std::string s[N][2];
std::map<std::string, std::multiset<std::string> > mp;
int pre[N], suf[N];
std::string get(std::string t, int l, int r) {
	std::string s = "";
	rep(i, l, r)
		if('a' <= t[i] && t[i] <= 'z') s.p_b(t[i]);
	return s;
}
bool ED;
signed main() {
	FREopen();
//	freopen("D:\\down\\club\\club2.in", "r", stdin);
//	freopen("dataT1.in", "r", stdin);
//	freopen("CCCLB.out", "w", stdout);
	wbg((&ED - &AT) / 1024.0 / 1024, "\n");
	rd(n, q);
	rep(i, 1, n) {
		std::cin >> s[i][0] >> s[i][1];
		mp[s[i][0]].insert(s[i][1]);
	}
	
//	wbg("SZZ\n");
//	for(auto s : mp["xabcx"]) wbg(s, '\n');
	
	for(std::string t1, t2; q--;) {
		std::cin >> t1 >> t2;
		int m = (int) t1.size(), ans = 0;
		
		mem(pre, 0), mem(suf, 0);
		
		rep(i, 0, m - 1) {
			if(t1[i] != t2[i]) pre[i] = 0;
			else {
				if(!i) pre[0] = 1;
				else pre[i] = pre[i - 1];
			}
		}
		lop(i, m - 1, 0) {
			if(t1[i] != t2[i]) suf[i] = 0;
			else {
				if(i == m - 1) suf[i] = 1;
				else suf[i] = suf[i + 1];
			}
		}
		
//		rep(i, 0, m - 1) wbg(suf[i], ' ');
//		wbg('\n');
		
		rep(i, 1, n) {
			for(int st = 0; ; st++) {
				if(st + (int) s[i][0].size() > m) break;
				int ed = st + (int) s[i][0].size();
				if(st && !pre[st - 1]) continue;
				if(ed < m - 1 && !suf[ed + 1]) continue;
				std::string a = get(t1, st, ed), b = get(t2, st, ed);
				
//				wbg(st, ' ', ed, "?? ", a, " ??", b, '\n');
				
//				wbg((int) (mp[a].size()), '\n');
				
				if(mp[a].find(b) != mp[a].end()) {
					
					
					ans += mp[a].count(b);
				}
			}
		}
		wr(ans, '\n');
	}
	return 0;
}
/*

*/
