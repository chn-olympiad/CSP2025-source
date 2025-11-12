#include <algorithm>
#include <iostream>
#include <cstring>
#include <utility>
#include <string>
#include <vector>
#define fi first
#define se second
#define mod1 998244853
#define mod2 1000000009
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 400005, M = 5000005;
int n, q, ans[N];string a, b, c;vector<pair<ll, int>> zu, zq;
ll Hash(string s){int h1 = 0, h2 = 0;
	for (char x : s) h1 = (1ll * h1 * N + (x ^ 1919)) % mod1, h2 = (1ll * h2 * M + (x ^ 114)) % mod2;
	return 1ll * h1 * mod2 + h2;
}
struct BIT{int n, tr[N];
	BIT(){n = 0, memset(tr, 0, sizeof(tr));}
	inline void upd(int p, int x){for (;p <= n;p += p & -p) tr[p] += x;}
	inline int qry(int p){int ans = 0;for (;p;p ^= p & -p) ans += tr[p];return ans;}
}st;
struct Trie{int _c, _d, _e, to[M][26], hd1[M], hd2[M], nx[N], vl[N], L[N], R[N], P[N];
	inline int New(){_c ++, memset(to[_c], hd1[_c] = hd2[_c] = 0, 104);return _c;}
	Trie(){_c = 0, _d = 0, _e = 1, New(), memset(hd1, 0, sizeof(hd1)), memset(hd2, 0, sizeof(hd2));}
	inline void Insert1(string a, int p){int u = 1;
		for (char x : a){
			int& v = to[u][x - 'a'];
			if (!v) v = New();u = v;
		}_d ++, vl[_d] = p, nx[_d] = hd1[u], hd1[u] = _d;
	}
	inline void Insert2(string a, int p){int u = 1;
		for (char x : a){
			int& v = to[u][x - 'a'];
			if (!v) v = New();u = v;
		}_d ++, vl[_d] = p, nx[_d] = hd2[u], hd2[u] = _d;
	}
	void dfs(int u){if (hd1[u] || hd2[u]) _e ++;
		for (int o = hd1[u];o;o = nx[o]) L[vl[o]] = _e;
		for (int o = hd2[u];o;o = nx[o]) P[vl[o]] = _e;
		for (int o = 0;o < 26;o ++) if (to[u][o]) dfs(to[u][o]);
		for (int o = hd1[u];o;o = nx[o]) R[vl[o]] = _e;
	}
}sa, sb;
void Calc(vector<int>& v1, vector<int>& v2){
	vector<pii> ud, qy;int j = 0, o;
	for (int o : v1)
	ud.emplace_back(sa.L[o], o),
	ud.emplace_back(sa.R[o] + 1, -o);
	for (int o : v2)
	qy.emplace_back(sa.P[o], o);
	sort(ud.begin(), ud.end()), sort(qy.begin(), qy.end());
	for (int i = 0;i < qy.size();i ++){
		while (j < ud.size() && ud[j].fi <= qy[i].fi){o = ud[j ++].se;
			if (o > 0) st.upd(sb.L[o], 1), st.upd(sb.R[o] + 1, -1);
			else st.upd(sb.L[-o], -1), st.upd(sb.R[-o] + 1, 1);
		}ans[qy[i].se] = st.qry(sb.P[qy[i].se]);
	}while (j < ud.size()){o = ud[j ++].se;
		if (o > 0) st.upd(sb.L[o], 1), st.upd(sb.R[o] + 1, -1);
		else st.upd(sb.L[-o], -1), st.upd(sb.R[-o] + 1, 1);
	}
}
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> q;
	for (int i = 1, l, r;i <= n;i ++){cin >> a >> b;
		if (a == b){n --, i --;continue;}
		for (l = 0;a[l] == b[l];l ++);
		for (r = a.size() - 1;a[r] == b[r];r --);
		c = a.substr(l, r - l + 1) + b.substr(l, r - l + 1), zu.emplace_back(Hash(c), i);
		a = a.substr(r + 1, a.size() - r - 1), sa.Insert1(a, i);
		b = b.substr(0, l), reverse(b.begin(), b.end()), sb.Insert1(b, i);
	}
	for (int i = 1, l, r;i <= q;i ++){cin >> a >> b;
		if (a.size() != b.size()) continue;
		for (l = 0;a[l] == b[l];l ++);
		for (r = a.size() - 1;a[r] == b[r];r --);
		c = a.substr(l, r - l + 1) + b.substr(l, r - l + 1), zq.emplace_back(Hash(c), i);
		a = a.substr(r + 1, a.size() - r - 1), sa.Insert2(a, i);
		b = b.substr(0, l), reverse(b.begin(), b.end()), sb.Insert2(b, i);
	}sa.dfs(1), sb.dfs(1), st.n = sb._e;
	sort(zu.begin(), zu.end()), sort(zq.begin(), zq.end());
	for (int i = 0, j, k = 0;i < zq.size();i = j){vector<int> vu, vq;
		for (j = i;j < zq.size() && zq[i].fi == zq[j].fi;) vq.push_back(zq[j ++].se);
		while (k < zu.size() && zu[k].fi < zq[i].fi) k ++;
		while (k < zu.size() && zu[k].fi == zq[i].fi) vu.push_back(zu[k ++].se);
		Calc(vu, vq);
	}
	for (int i = 1;i <= q;i ++) cout << ans[i] << '\n';
}