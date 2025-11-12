//大概AK了。如果这题不M和T的话。
//"There is no god. Wonderful new world."
#include <bits/stdc++.h>
using namespace std;
#define _rep(i,a,b) for(int i = a; i <= b; ++i)
using ll = long long;
using pii = pair<int,int>;
// auto st = chrono::system_clock::now(); // -------------------------
char buf[1<<23],*p1=buf,*p2=buf;
char gc(void) {
	if(p1==p2)p1=buf,p2=buf+fread(buf,1,1<<23,stdin);
	return *p1++;
}
int in(void) {
	int x=0,c=gc();
	while(!isdigit(c))c=gc();
	while(isdigit(c))x=x*10+c-'0',c=gc();
	return x;
}
const int kN = 2550000;
struct ACAM {
	int ch[kN][26], fail[kN], nc;
	int extend(int last, char c) {
		if(!ch[last][c - 'a']) ch[last][c - 'a'] = ++nc; 
		return ch[last][c - 'a'];
	}
	int que[kN], hd, tl;
	vector<int> g[kN];
	int dfn[kN], siz[kN], dfs_clock;
	void dfs(int u) {
		dfn[u] = ++dfs_clock, siz[u] = 1;
		for(auto &v : g[u]) dfs(v), siz[u] += siz[v];
	}
	void build(void) {
		_rep(i,0,25) if(ch[1][i]) que[++tl] = ch[1][i], fail[ch[1][i]] = 1; else ch[1][i] = 1;
		while(hd < tl) {
			int u = que[++hd];
			_rep(i,0,25) if(ch[u][i]) fail[ch[u][i]] = ch[fail[u]][i], que[++tl] = ch[u][i];
				else ch[u][i] = ch[fail[u]][i];
		}
		_rep(i,2,nc) g[fail[i]].push_back(i);
		_rep(i,1,nc) g[i].shrink_to_fit();
		dfs(1);
	}
} a, b;
vector<int> M[kN];
vector<pii> Q[kN];
int n, q;
ll ans[kN];
char s[kN * 2], t[kN * 2];
int c[kN];
void add(int x, int y) { for(; x < kN; x += x & -x) c[x] += y; }
int query(int x) { int r = 0; for(; x; x -= x & -x) r += c[x]; return r; }
void dfs(int u) {
	for(auto &v : M[u]) add(b.dfn[v], 1), add(b.dfn[v] + b.siz[v], -1);
	for(auto &v : Q[u]) if(v.second > 0) ans[v.second] += query(b.dfn[v.first]); else ans[-v.second] -= query(b.dfn[v.first]);
	for(auto &v : a.g[u]) dfs(v);
	for(auto &v : M[u]) add(b.dfn[v], -1), add(b.dfn[v] + b.siz[v], 1);
}
void ins(char *s) {
	while(!isalpha(*s = gc()));
	while(isalpha(*++s = gc()));
	*s = '\0';
}
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	a.nc = b.nc = 1;
	n = in(), q = in();
	_rep(i,1,n) {
		ins(s + 1), ins(t + 1);
		int l = strlen(s + 1);
		int x = 1, y = 1;
		_rep(j,1,l) {
			x = a.extend(x, s[j]);
			y = b.extend(y, t[j]);
		}
		M[x].push_back(y);
	}
	_rep(i,1,a.nc) M[i].shrink_to_fit();
	a.build(), b.build(); int ti = 0;
	_rep(i,1,q) {
		ins(s + 1), ins(t + 1);
		int l = strlen(s + 1);
		if(strlen(t + 1) != l) continue;
		int x = 1, y = 1;
		int X = 1, Y = 1; 
		int L = 1, R = l;
		while(s[L] == t[L]) ++L;
		while(s[R] == t[R]) --R;
		_rep(j,1,l) {
			x = a.ch[x][s[j] - 'a'], y = b.ch[y][t[j] - 'a'];
			if(j > L) X = a.ch[X][s[j] - 'a'], Y = b.ch[Y][t[j] - 'a'];
			if(j >= R) 
				Q[x].emplace_back(y, i), Q[X].emplace_back(Y, -i), ti += 2;
		}
		// cout << ti << endl;
	}
	dfs(1);
	_rep(i,1,q) printf("%lld\n", ans[i]);
	// chrono::duration<double> tot = chrono::system_clock::now() - st;
	// fprintf(stderr, "Time used = %.5lfs\n", tot.count());
	return 0;
}