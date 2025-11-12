#include <bits/stdc++.h>
#define F(i, l, r) for (int i = l; i <= r; i ++)
#define G(i, r, l) for (int i = r; i >= l; i --)
#define MP make_pair
using namespace std;
typedef long long LL;
typedef __int128 i128;

template <typename T>
void Fmin(T &x, T y) { x = x < y ? x : y; }
template <typename T>
void Fmax(T &x, T y) { x = x > y ? x : y; }

const int N = 2e5 + 7, M = 1e7 + 7;
const i128 P = 114514191981007219ll, bas = 19260817;

int n, q, typ, ans[N];
map<pair<i128, i128>, int> mp;
vector<int> pos[N];
vector<string> u[N][2], v[N][2];
struct node { int x, l, r, id; } qry[N * 3];
bool operator < (node x, node y) {
  if (x.x != y.x) return x.x < y.x;
  return x.r > y.r;
}

struct Trie {
  int cnt, dn, ch[M][26], dfn[M], siz[M], ed[4][N];
  void clear() {
  	dn = 0;
  	F(i, 1, cnt)
  	  F(j, 0, 25) ch[i][j] = 0;
  	cnt = 1;
  }
  void insert(string s, int x, int y) {
  	int cur = 1;
  	for (char c : s) {
  	  int op = c - 'a';
  	  if (!ch[cur][op]) ch[cur][op] = ++ cnt;
  	  cur = ch[cur][op];
	}
	ed[x][y] = cur;
  }
  void dfs(int x) {
  	dfn[x] = ++ dn, siz[x] = 1;
  	F(i, 0, 25)
  	  if (ch[x][i])
		dfs(ch[x][i]), siz[x] += siz[ch[x][i]]; 
  }
} T;
namespace BIT {
  int tr[M];
  void modify(int x, int y) {
  	for (; x < M; x += (x & -x)) tr[x] += y;
  }
  void modify(int l, int r, int x) {
  	modify(l, x), modify(r, -x);
  }
  int query(int x) {
  	int ans = 0;
  	for (; x; x -= (x & -x)) ans += tr[x];
  	return ans;
  }
}

i128 sol(string s) {
  i128 hsh = 0;
  for (char c : s) hsh = (hsh * bas + c) % P;
  return hsh;
}
void solve(string s, string t, int id) {
  if (s == t || s.size() != t.size()) return ;
  int l = -1, r = 0;
  F(i, 0, (int)s.size() - 1)
	if (s[i] != t[i]) {
	  r = i;
	  if (l == -1) l = i;
	}
  string L = s.substr(0, l), R = s.substr(r + 1);
  reverse(L.begin(), L.end());
  string A = s.substr(l, r - l + 1), B = t.substr(l, r - l + 1);
  pair<i128, i128> hsh = MP(sol(A), sol(B));
  if (!id) {
  	if (!mp[hsh]) mp[hsh] = ++ typ;
  	int opt = mp[hsh];
  	u[opt][0].push_back(L), u[opt][1].push_back(R);
  } else {
  	if (!mp[hsh]) return ;
  	int opt = mp[hsh];
  	v[opt][0].push_back(L), v[opt][1].push_back(R);
  	pos[opt].push_back(id);
  }
}

void dead_X(int x) {
  T.clear();
  int P = u[x][0].size(), Q = v[x][0].size(); 
  F(i, 0, P - 1)
  	T.insert(u[x][0][i], 0, i), T.insert(u[x][1][i], 1, i);
  F(i, 0, Q - 1)
  	T.insert(v[x][0][i], 2, i), T.insert(v[x][1][i], 3, i);
  T.dfs(1);
  int cur = 0;
  F(i, 0, P - 1) {
  	int l1 = T.dfn[T.ed[0][i]], l2 = T.dfn[T.ed[1][i]];
  	int r1 = l1 + T.siz[T.ed[0][i]], r2 = l2 + T.siz[T.ed[1][i]];
	qry[++ cur] = {l1, l2, r2, 1}, qry[++ cur] = {r1, l2, r2, -1};
  }
  F(i, 0, Q - 1) {
  	int X = T.dfn[T.ed[2][i]], Y = T.dfn[T.ed[3][i]];
  	qry[++ cur] = {X, Y, 0, pos[x][i]};
  }
  sort(qry + 1, qry + cur + 1);
  F(i, 1, cur) {
  	if (qry[i].r) BIT::modify(qry[i].l, qry[i].r, qry[i].id);
  	else ans[qry[i].id] = BIT::query(qry[i].l);
  }
} 

int main() {
  freopen("replace.in", "r", stdin);
  freopen("replace.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin >> n >> q;
  string s, t;
  F(i, 1, n)
  	cin >> s >> t, solve(s, t, 0);
  F(i, 1, q)
    cin >> s >> t, solve(s, t, i);
  F(i, 1, typ) dead_X(i);
  F(i, 1, q) cout << ans[i] << '\n';
  return 0;
}

