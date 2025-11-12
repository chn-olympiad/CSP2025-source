#include<bits/stdc++.h>
using namespace std;

const int NN = 2e5 + 5, N = 2.5e6 + 5, C = 26;
int n, Q, ans[NN], q[N], ql, qr;
int col[NN];
char x[N], y[N];
int dfn[N], ed[N], df;
struct ASK{int x, typ, id;};
vector<ASK> ask[N];
vector<int> id[N];
vector<ASK> qwq[N];

namespace BIT{
	int t[N];
	inline void upd(int a, int k) {for(; a < N; a += a & -a) t[a] += k;}
	inline int qry(int a) {int res = 0; for(; a > 0; a -= a & -a) res += t[a]; return res;}
};
struct ACAM{
	int trie[N][C], tot, fail[N], pos[NN], len[N];
	vector<int> to[N];
	
	inline void ins(char c[], int idd, bool pd){
		int m = strlen(c + 1), u = 0;
		for(int i = 1; i <= m; ++i){
			int ch = c[i] - 'a';
			if(!trie[u][ch]) trie[u][ch] = ++tot, len[tot] = i;
			u = trie[u][ch];			
		}
		if(pd) id[u].push_back(idd);
		pos[idd] = u;
	}
	inline void init(bool pd){
		ql = 1, qr = 0;
		for(int i = 0; i < 26; ++i)
			if(trie[0][i]) fail[trie[0][i]] = 0, q[++qr] = trie[0][i];
		while(ql <= qr){
			int u = q[ql]; ++ql;
			for(int i = 0; i < 26; ++i)
				if(trie[u][i]) fail[trie[u][i]] = trie[fail[u]][i], q[++qr] = trie[u][i];
				else trie[u][i] = trie[fail[u]][i];
		}
		for(int i = 1; i <= tot; ++i) to[fail[i]].push_back(i);
	}
	inline void ddfs(int u){
		q[++qr] = u;
		for(auto _ : qwq[u]){
			if(len[q[1]] < _.x){
				int L = 1, R = qr + 1, mid;
				while(L + 1 < R){
					mid = (L + R) >> 1;
					if(len[q[mid]] < _.x) L = mid;
					else R = mid;
				}
				ask[q[L]].push_back({_.typ, -1, _.id});
			} 
		}
		for(auto v : to[u]) ddfs(v);
		--qr;
	}
} T1, T2;
inline void calc(int ua, int ub, int lim, int ID){
	ask[ua].push_back({ub, 1, ID});
	if(lim > 1) qwq[ua].push_back({lim, ub, ID});
}
inline void dfsb(int u){
	dfn[u] = ++df;
	for(auto v : T2.to[u]) dfsb(v);
	ed[u] = df;
}
inline void dfsa(int u){
	for(auto i : id[u]){
		int ub = T2.pos[i];
		BIT::upd(dfn[ub], 1);
		BIT::upd(ed[ub] + 1, -1);
	}
	for(auto _ : ask[u]){
		ans[_.id] += _.typ * BIT::qry(dfn[_.x]);
	}
	for(auto v : T1.to[u]) dfsa(v);
	for(auto i : id[u]){
		int ub = T2.pos[i];
		BIT::upd(dfn[ub], -1);
		BIT::upd(ed[ub] + 1, 1);
	}
}
signed main(){
//	system("fc replace.out replace4.ans"); return 0;
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> Q;
	int alen = 0, blen = 0;
	for(int i = 1; i <= n; ++i){
		scanf("%s%s", x + 1, y + 1);
		T1.ins(x, i, 1);
		T2.ins(y, i, 0);
	}
	T1.init(1), T2.init(0);
	dfsb(0);
	for(int i = 1; i <= Q; ++i){
		scanf("%s%s", x + 1, y + 1);
		int plen = 0, spos = 0, len = strlen(x + 1);
		if(len ^ strlen(y + 1)) {ans[i] = 0; continue;}
		for(int j = 1; j <= len + 1; ++j) if(j == len + 1 || x[j] ^ y[j]) {plen = j - 1; break;}
		for(int j = len; j >= 0; --j) if(!j || x[j] ^ y[j]) {spos = j; break;}
		int now = 0, noww = 0, ct = 0;
		for(int j = 1; j <= len; ++j){
			now = T1.trie[now][x[j] - 'a'];
			noww = T2.trie[noww][y[j] - 'a'];
			if(j >= spos) calc(now, noww, j - plen, i);
		}
	}
	qr = 0;
	T1.ddfs(0);
	dfsa(0);
	for(int i = 1; i <= Q; ++i) printf("%d\n", ans[i]);
	return 0;
}
