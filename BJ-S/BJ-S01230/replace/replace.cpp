// Calm down.
// Think TWICE, code ONCE.
#include<bits/stdc++.h>
#define pb push_back
#define popcnt __builtin_popcountll
#define debug printf("Passed line %d\n", __LINE__)

using namespace std;
typedef long long ll;
typedef vector<int> vint;
typedef pair<int, int> PII;

template<typename T> inline void read(T &x){
	x = 0; bool F = 0; char c = getchar();
	for (;!isdigit(c);c = getchar()) F |= (c == '-');
	for (;isdigit(c);c = getchar()) x = x*10+(c^48);
	if (F) x = -x;
}

template<typename T1, typename ...T2> inline void read(T1 &x, T2 &...y){read(x), read(y...);}

template<typename T> inline void checkmax(T &x, const T &y){if (x<y) x = y;}

template<typename T> inline void checkmin(T &x, const T &y){if (x>y) x = y;}

const int N = 2e5+5, M = 6e6, K = 26;
const ll MOD = 1e16+61, base = 550;
int ans[N], tr[M][K], dfn[M], rdfn[M], id[M], askid[M], posb[N], DFN, ASK, vec, node, rta, rtb, n, q, top;
vint mdf[N], ask[N], val[N*2];
vector<PII> ask2[N*2];
ll lsh[N];

struct Data{

	ll val;
	string a, b;

	inline void init(){
		string x, y; cin >> x >> y; val = 0;
		if (x.length()!=y.length()){val = -1; return;}
		int l = 0, r = 0, n = x.length();
		for (int i = 0;i<n;i++) if (x[i]!=y[i]){l = i; break;}
		for (int i = n-1;i>=0;i--) if (x[i]!=y[i]){r = i; break;}
		for (int i = l-1;i>=0;i--) a += x[i];
		for (int i = r+1;i<n;i++) b += y[i];
		for (int i = l;i<=r;i++) val = (val*base+x[i])%MOD;
		for (int i = l;i<=r;i++) val = (val*base+y[i])%MOD;
	}

}s[N], t[N];

inline int Get(ll x){return lower_bound(lsh+1, lsh+top+1, x)-lsh;}

inline int check(const string &a, const string &b){
	if (a.length()>b.length()) return 0;
	for (int i = 0;i<a.length();i++) if (a[i]!=b[i]) return 0;
	return 1;
}

inline void inserts(int rt, string s, int ID, int flag = 1){ // flag: vec
	int k, pos = rt;
	for (auto c: s){
		k = c-'a';
		if (!tr[pos][k]) tr[pos][k] = ++node;
		pos = tr[pos][k];
	}
	if (!flag){posb[ID] = pos; return;}
	if (!id[pos]) id[pos] = ++vec;
	val[id[pos]].pb(ID);
}

inline int insertt(int rt, string s){
	int k, pos = rt;
	for (auto c: s){
		k = c-'a';
		if (!tr[pos][k]) return pos;
		pos = tr[pos][k];
	}
	return pos;
}

void dfsb(int u){
	if (id[u]) dfn[u] = rdfn[u] = ++DFN; int t;
	for (int i = 0;i<K;i++){
		t = tr[u][i];
		if (t){
			dfsb(t);
			if (!dfn[u] && dfn[t]) dfn[u] = dfn[t];
			if (rdfn[t]) rdfn[u] = rdfn[t];
		}
	}
}

#define lowbit(x) (x&-x)

int c[N];

inline void modify(int p, int delta){
	for (;p<=DFN;p += lowbit(p)) c[p] += delta;
}

inline void modify(int l, int r, int delta){
	if (l) modify(l, delta), modify(r+1, -delta);
}

inline int query(int p){
	int ans = 0;
	for (;p;p -= lowbit(p)) ans += c[p];
	return ans;
}

void dfsa(int u){
	// printf("dfsa : %d\n", u);
	for (int i: val[id[u]]){
		modify(dfn[posb[i]], rdfn[posb[i]], 1);
	}
	for (auto x: ask2[askid[u]]){
		ans[x.first] = query(x.second);
		// printf("%d query %d\n", x.first, x.second);
	}
	int z;
	for (int i = 0;i<K;i++){
		z = tr[u][i];
		if (z) dfsa(z);
	}

	for (int i: val[id[u]]){
		modify(dfn[posb[i]], rdfn[posb[i]], -1);
	}
}

inline void solve(vint &mdf, vint &ask){
	// for (int i: ask){
	// 	for (int j: mdf){
	// 		ans[i] += (check(s[j].a, t[i].a)&&check(s[j].b, t[i].b));
	// 	}
	// }
	for (int i = 1;i<=node;i++){
		dfn[i] = rdfn[i] = id[i] = askid[i] = 0;
		memset(tr[i], 0, sizeof(tr[i]));
	}
	for (int i = 1;i<=vec;i++) val[i].clear();
	for (int i = 1;i<=ASK;i++) ask2[i].clear();
	node = vec = ASK = DFN = 0;
	rta = 1, rtb = 2, node = 2;
	for (int i: mdf) inserts(rta, s[i].a, i), inserts(rtb, s[i].b, i, 0);
	for (int i: ask){
		id[insertt(rtb, t[i].b)] = 1;
	}
	dfsb(rtb);
	for (int i = 1;i<=DFN;i++) c[i] = 0;
	int z;
	for (int i: ask){
		z = insertt(rta, t[i].a);
		if (!askid[z]) askid[z] = ++ASK;
		ask2[askid[z]].pb({i, dfn[insertt(rtb, t[i].b)]});
	}
	dfsa(rta);
}

int main(){
	// freopen("input.txt", "r", stdin); cerr << "----------------------------------- Program output -----------------------------------\n";
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> q;
	for (int i = 1;i<=n;i++) s[i].init(), lsh[i] = s[i].val;
	for (int i = 1;i<=q;i++) t[i].init(); int z;
	sort(lsh+1, lsh+n+1), top = unique(lsh+1, lsh+n+1)-lsh-1;
	for (int i = 1;i<=n;i++) mdf[Get(s[i].val)].pb(i);
	for (int i = 1;i<=q;i++){
		z = Get(t[i].val);
		if (lsh[z] == t[i].val) ask[z].pb(i);
	}
	for (int i = 1;i<=top;i++) solve(mdf[i], ask[i]);
	for (int i = 1;i<=q;i++) printf("%d\n", ans[i]);
	return 0;
}
/*
self check:
1. freopen
2. long long
3. size of array
4. code for testing
*/