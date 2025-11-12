#include <bits/stdc++.h>
#define _rep(i, x, y) for(int i = x; i <= y; ++i)
#define _req(i, x, y) for(int i = x; i >= y; --i)
#define fi first
#define se second
#define mst(f, i) memset(f, i, sizeof f)
#define pb push_back
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr);
using namespace std;
typedef long long ll;
typedef pair<ll, ll> PII;
namespace fastio{
	template<typename T> inline void read(T &t){
		T x = 0, f = 1;
		char c = getchar();
		while(!isdigit(c)){
			if(c == '-') f = -f;
			c = getchar();
		}
		while(isdigit(c)) x = x * 10 + c - '0', c = getchar();
		t = x * f;
	}
	template<typename T, typename ... Args> inline void read(T &t, Args &...args){
		read(t), read(args...);
	}
	void write(int x){printf("%d", x);}
	void writes(int x){printf("%d ", x);}
	void writeln(int x){printf("%d\n", x);}
	void write(ll x){printf("%lld", x);}
	void writes(ll x){printf("%lld ", x);}
	void writeln(ll x){printf("%lld\n", x);}
}
using namespace fastio;
#define multitest() int T; read(T); for(int tCase = 1; tCase <= T; ++tCase)
const int N = 5e6 + 5, M = 2e5 + 5, kN = 5e6 + 5;
int n, q;
char s[kN], t[kN];
const ll mod = 1e9 + 9, mod2 = 1e9 + 7, base = 133;
map<PII, int> mp;
namespace ACAM{
	int num, rt[M];
	struct node{
		int len, fail, nxt[26];
	}a[N];
	vector<int> h[N];
	vector<PII> hh[N];
	void ins(int id){
		scanf("%s%s", s + 1, t + 1);
		int len = strlen(s + 1), pos = 0, pos2 = 0;
		_rep(i, 1, len) if(s[i] != t[i]){
			pos = i;
			break;
		}
		_req(i, len, 1) if(s[i] != t[i]){
			pos2 = i;
			break;
		}
		if(!pos) return;
		ll cur1 = 0, cur2 = 0;
		_rep(i, pos, pos2) cur1 = (cur1 * base + s[i]) % mod, cur2 = (cur2 * base + s[i]) % mod2;
		ll vl = cur1 * 1000000000ll + cur2;
		cur1 = 0, cur2 = 0;
		_rep(i, pos, pos2) cur1 = (cur1 * base + t[i]) % mod, cur2 = (cur2 * base + t[i]) % mod2;
		ll vr = cur1 * 1000000000ll + cur2;
		if(!mp[make_pair(vl, vr)]) mp[make_pair(vl, vr)] = ++num;
		int x = mp[make_pair(vl, vr)];
		_rep(i, 1, len){
			if(i >= pos && i <= pos2) continue;
			int c = s[i] - 'a';
			if(!a[x].nxt[c]) a[x].nxt[c] = ++num, a[num].len = a[x].len + 1;
			x = a[x].nxt[c];
		}
		h[len - pos2].pb(x);
	}
	vector<int> G[N];
	int id, dfn[N], siz[N];
	void dfs(int u){
		dfn[u] = ++id, siz[u] = 1;
		for(auto &v : G[u]) dfs(v), siz[u] += siz[v];
	}
	void build(){
		queue<int> q;
		for(auto &i : mp){
			int x = i.se;
			_rep(j, 0, 25){
				if(!a[x].nxt[j]) a[x].nxt[j] = x;
				else q.push(a[x].nxt[j]), a[a[x].nxt[j]].fail = x;
			}
		}
		while(q.size()){
			int u = q.front(); q.pop();
			_rep(i, 0, 25){
				int v = a[u].nxt[i];
				if(v) a[v].fail = a[a[u].fail].nxt[i], q.push(v);
				else a[u].nxt[i] = a[a[u].fail].nxt[i];
			}
		} 
		_rep(i, 1, num) if(a[i].fail) G[a[i].fail].pb(i);
		for(auto &i : mp) dfs(i.se);
	}
}
using namespace ACAM;
int ans[M];
namespace bit{
	int c[N];
	void modify(int x, int val){for(; x <= id; x += x & -x) c[x] += val;}
	int ask(int x){int res = 0; for(; x; x -= x & -x) res += c[x]; return res;}
}
using namespace bit;
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
//	int tt = clock();
//	work();
	read(n, q);
	_rep(i, 1, n) ins(i);
	build();
//	debug("use %.3lfs\n", 1.00 * (clock() - tt) / CLOCKS_PER_SEC);
	_rep(i, 1, q){
		scanf("%s%s", s + 1, t + 1);
		int len = strlen(s + 1), lent = strlen(t + 1);
		if(len != lent) continue;
		int pos = 0, pos2 = 0;
		_rep(i, 1, len) if(s[i] != t[i]){
			pos = i;
			break;
		}
		_req(i, len, 1) if(s[i] != t[i]){
			pos2 = i;
			break;
		}
		ll cur1 = 0, cur2 = 0;
		_rep(i, pos, pos2) cur1 = (cur1 * base + s[i]) % mod, cur2 = (cur2 * base + s[i]) % mod2;
		ll vl = cur1 * 1000000000ll + cur2;
		cur1 = 0, cur2 = 0;
		_rep(i, pos, pos2) cur1 = (cur1 * base + t[i]) % mod, cur2 = (cur2 * base + t[i]) % mod2;
		ll vr = cur1 * 1000000000ll + cur2;
		int x = mp[make_pair(vl, vr)];
		if(!x) continue;
		if(pos == 1){
			int now = 0;
			hh[now].pb({x, i});
//			for(int u = x; u; u = a[u].fail) for(auto &o : h[u]) ans[i] += o == now;
		}
		_rep(j, 1, len){
			int c = s[j] - 'a';
			if(j >= pos && j <= pos2) continue;
			x = a[x].nxt[c];
			if(j >= pos - 1){
				int now = j == pos - 1 ? 0 : j - pos2;
				hh[now].pb({x, i});
//				for(int u = x; u; u = a[u].fail) for(auto &o : h[u]) ans[i] += o == now;
			}
		}
	}
	int maxl = 5000000;
	_rep(i, 0, maxl){
		for(auto &j : h[i]) modify(dfn[j], 1), modify(dfn[j] + siz[j], -1);
		for(auto &j : hh[i]) ans[j.se] += ask(dfn[j.fi]);
		for(auto &j : h[i]) modify(dfn[j], -1), modify(dfn[j] + siz[j], 1);
	}
//	debug("use %.3lfs\n", 1.00 * (clock() - tt) / CLOCKS_PER_SEC);
	_rep(i, 1, q) writeln(ans[i]);
//	work();
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
1 1
xabcx xadex
xabcx xadex

2
0

3 4
a b
b c
c d
aa bb
aa b
a c
b a

0
0
0
0

*/
