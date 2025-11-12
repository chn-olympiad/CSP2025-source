#include <bits/stdc++.h>

#define i64 long long

#define pii pair<int, int>
#define fi first
#define se second
#define mp make_pair
#define eb emplace_back

using namespace std;

inline int Read() {int res; return scanf("%d", &res), res; }
inline i64 Read64() {i64 res; return scanf("%lld", &res), res; }

const int N = 200000 + 5, M = 5000000 + 5, Mod = 1000000007, P = 13331;
const int INF_32 = 1e9;

int n, q, sz[N], le[N], ri[N], id[M], tt = 0;
int cnt = 1, rt = 1;
int fai[M], ed[M][26];
int qq[M], he = 0, ta = 0;
map<pii, int> G[N], H;
int Head[M], End[M], Nex[M], tot = 0; 
int L[N], R[N], ans[N], cc[N];
int idd[M], z = 0;
vector<int> F[M], K[M];

void Connect(int u, int v) {
	End[++ tot] = v, Nex[tot] = Head[u], Head[u] = tot;
}

void DFS(int u) {
	if(id[u]) {
		for(auto x : G[id[u]]) H[x.fi] += x.se;
	}
	if(idd[u]) {
//		cout << u << endl;
		sort(F[idd[u]].begin(), F[idd[u]].end());
		F[idd[u]].erase(unique(F[idd[u]].begin(), F[idd[u]].end()), F[idd[u]].end());
		K[idd[u]].resize((int)F[idd[u]].size()); 
		int ty = 0;
		for(int x : F[idd[u]]) {
			cc[x] ++;
			K[idd[u]][ty ++] = cc[x];
		}
	}
	for(int i = Head[u]; i; i = Nex[i]) {
		int v = End[i];
		DFS(v);
	}
	if(idd[u]) {
		int ty = 0;
//		cout << (int)K[idd[u]].size() << endl;
		for(int x : F[idd[u]]) {
//			if(x == 1941) cerr << cc[x] << " " << K[idd[u]][ty] << endl; 
			if(cc[x] == K[idd[u]][ty]) {
//				if(x == 1941) cerr << u << " " << x << endl;
				if(H.count(mp(L[x], R[x]))) ans[x] += H[mp(L[x], R[x])];
			}
			ty ++;
		}
	}
	if(id[u]) {
		for(auto x : G[id[u]]) H[x.fi] -= x.se;
	}
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	n = Read(), q = Read(); 
	
	for(int i = 1; i <= n; ++ i) {
		string s, t;
		cin >> s;
		cin >> t;
		
		int len = s.length(), minn = INF_32, maxx = -1;
		for(int j = 0; j < len; ++ j) {
			if(s[j] != t[j]) minn = min(minn, j), maxx = max(maxx, j);
		}
		sz[i] = len;
		if(minn > maxx) continue;
		for(int j = minn; j <= maxx; ++ j) {
			(le[i] = (i64)le[i] * P % Mod + s[j]) >= Mod && (le[i] -= Mod);
			(ri[i] = (i64)ri[i] * P % Mod + t[j]) >= Mod && (ri[i] -= Mod);
		}
//		if(le[i] == 1637 && ri[i] == 1516) cerr << (int)t[0] << " " << (int)t[1] << endl;
		int p = 1;
		for(int j = 0; j < len; ++ j) {
			int t = s[j] - 'a';
			if(!ed[p][t]) ed[p][t] = ++ cnt;
			p = ed[p][t];
		}
		if(!id[p]) id[p] = ++ tt;
		G[id[p]][mp(le[i], ri[i])] ++;
//		if(le[i] == 1637 && ri[i] == 1516) cerr << s << " " << t << " " << p << endl;
	}
	
	fai[1] = 1, he = 1;
	for(int i = 0; i < 26; ++ i) {
		if(!ed[1][i]) ed[1][i] = 1;
		else {
			qq[++ ta] = ed[1][i], fai[ed[1][i]] = 1; 
		}
	}
	
	while(he <= ta) {
		int u = qq[he ++];
		for(int i = 0; i < 26; ++ i) {
			if(!ed[u][i]) ed[u][i] = ed[fai[u]][i];
			else {
				fai[ed[u][i]] = ed[fai[u]][i];
				qq[++ ta] = ed[u][i];
			}
		}
	}
	
	for(int i = 2; i <= cnt; ++ i) Connect(fai[i], i);
	
	for(int i = 1; i <= q; ++ i) {
		string s, t;
		cin >> s;
		cin >> t;
		if(s.length() != t.length()) continue;
		
		int len = s.length(), minn = INF_32, maxx = -1;
		for(int j = 0; j < len; ++ j) {
			if(s[j] != t[j]) minn = min(minn, j), maxx = max(maxx, j);
		}
		if(minn > maxx) continue;
		for(int j = minn; j <= maxx; ++ j) {
			(L[i] = (i64)L[i] * P % Mod + s[j]) >= Mod && (L[i] -= Mod);
			(R[i] = (i64)R[i] * P % Mod + t[j]) >= Mod && (R[i] -= Mod);
		}
//		if(i == 1941) cerr << minn << " " << maxx << " " << s[0] << s[1] << " " << t[0] << t[1] << " " << L[i] << " " << R[i] << endl;
		int p = 1;
		for(int j = 0; j < len; ++ j) {
			int t = s[j] - 'a';
			p = ed[p][t];
			if(j >= maxx) {
				if(!idd[p]) idd[p] = ++ z;
				F[idd[p]].eb(i); 
//				if(i == 1941) cerr << fai[p] << " " << p << endl;
			}
		}
	}
	
	DFS(1);
	
	for(int i = 1; i <= q; ++ i) printf("%d\n", ans[i]);
	
	return 0;
}
/*
Ã»»îÁ¦£¨±¯£© 
*/
