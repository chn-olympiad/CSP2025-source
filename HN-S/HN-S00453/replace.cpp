#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128_t;

const i128 base = 1145141;
const i128 mod = 100000000000003007ll;
const int kN = 2e5 + 5, kL = 5e6 + 5;
int n, q, c;
int sl[kN], sr[kN];
int tl[kN], tr[kN];
string s[kN][2], t[kN][2];
int ans[kN];

vector<int> upd[kN], qry[kN];

int LCP(string s, string t) {
  for(int i = 0; i < s.size(); i++) {
    if(s[i] != t[i]) return i;
  }
  assert(0);
}
int LCS(string s, string t) {
  for(int i = s.size() - 1; ~i; i--) {
    if(s[i] != t[i]) return i;
  }
  assert(0);
}

ll H(string s) {
  ll sum = 0;
  for(char c : s) sum = (sum * base + c) % mod;
  return sum;
}
map<pair<ll, ll>, int> mp;

struct Trie {
  int tot = 0, tim = 0;
  int son[kL][26];
  int dfnl[kL], dfnr[kL];
  void Clear() {
    for(int i = 0; i <= tot; i++) {
      fill_n(son[i], 26, 0);
      dfnl[i] = dfnr[i] = 0;
    }
    tot = tim = 0;
  }
  void Insert(string s) {
    int p = 0;
    for(char c : s) {
      int k = c - 'a';
      if(!son[p][k]) son[p][k] = ++tot;
      p = son[p][k];
    }
  }
  int Pos(string s) {
    int p = 0;
    for(char c : s) {
      int k = c - 'a';
      if(!son[p][k]) return p;
      p = son[p][k];
    }
    return p;
  }
  void DFS(int x) {
    dfnl[x] = ++tim;
    for(int to : son[x]) {
      if(to) DFS(to);
    }
    dfnr[x] = tim;
  }
} tpre, tsuf;

struct Node {
  int x, y, type, coef;
  Node() { }
  Node(int _x, int _y, int _ty, int _co) {
    x = _x;
    y = _y;
    type = _ty;
    coef = _co;
  }
};

struct BIT {
  int tr[kL];
  void Update(int x, int v) {
    for(; x < kL; x += (x & -x)) tr[x] += v;
  }
  int Query(int x) {
    int ans = 0;
    for(; x; x &= (x - 1)) ans += tr[x];
    return ans;
  }
} bit;

void Count(vector<Node> vec) {
  sort(vec.begin(), vec.end(),
    [&](Node x, Node y) {
      return (x.x == y.x) ? (x.type < y.type) : (x.x < y.x);
    });
  for(Node k : vec) {
    if(!k.type) bit.Update(k.y, k.coef);
    else ans[k.type] += bit.Query(k.y) * k.coef;
  }
  for(Node k : vec) {
    if(!k.type) bit.Update(k.y, -k.coef);
  }
}

int main() {
  freopen("replace.in", "r", stdin);
  freopen("replace.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> q;
  for(int i = 1; i <= n; i++) {
    cin >> s[i][0] >> s[i][1];
    if(s[i][0] == s[i][1]) continue;
    sl[i] = LCP(s[i][0], s[i][1]);
    sr[i] = LCS(s[i][0], s[i][1]);
    ll hs = H(s[i][0].substr(sl[i], sr[i] - sl[i] + 1));
    ll ht = H(s[i][1].substr(sl[i], sr[i] - sl[i] + 1));
    pair<ll, ll> tmp {hs, ht};
    if(!mp.count(tmp)) mp[tmp] = ++c;
    upd[mp[tmp]].push_back(i);
  }
  for(int i = 1; i <= q; i++) {
    cin >> t[i][0] >> t[i][1];
    tl[i] = LCP(t[i][0], t[i][1]);
    tr[i] = LCS(t[i][0], t[i][1]);
    ll hs = H(t[i][0].substr(tl[i], tr[i] - tl[i] + 1));
    ll ht = H(t[i][1].substr(tl[i], tr[i] - tl[i] + 1));
    pair<ll, ll> tmp {hs, ht};
    if(!mp.count(tmp)) continue;
    qry[mp[tmp]].push_back(i);
  }
  for(int i = 1; i <= c; i++) {
    if(upd[i].empty() || qry[i].empty()) continue;
    tpre.Clear();
    tsuf.Clear();
    vector<Node> vec;
    for(int x : upd[i]) {
      string pre = s[x][0].substr(0, sl[x]);
      string suf = s[x][0].substr(sr[x] + 1);
      reverse(pre.begin(), pre.end());
      tpre.Insert(pre);
      tsuf.Insert(suf);
    }
    tpre.DFS(0), tsuf.DFS(0);
    for(int x : upd[i]) {
      string pre = s[x][0].substr(0, sl[x]);
      string suf = s[x][0].substr(sr[x] + 1);
      reverse(pre.begin(), pre.end());
      int idp = tpre.Pos(pre);
      int ids = tsuf.Pos(suf);
      vec.emplace_back(tpre.dfnl[idp], tsuf.dfnl[ids], 0, 1);
      vec.emplace_back(tpre.dfnl[idp], tsuf.dfnr[ids] + 1, 0, -1);
      vec.emplace_back(tpre.dfnr[idp] + 1, tsuf.dfnl[ids], 0, -1);
      vec.emplace_back(tpre.dfnr[idp] + 1, tsuf.dfnr[ids] + 1, 0, 1);
    }
    for(int x : qry[i]) {
      string pre = t[x][0].substr(0, tl[x]);
      string suf = t[x][0].substr(tr[x] + 1);
      reverse(pre.begin(), pre.end());
      int idp = tpre.Pos(pre);
      int ids = tsuf.Pos(suf);
      vec.emplace_back(tpre.dfnl[idp], tsuf.dfnl[ids], x, 1);
    }
    Count(vec);
  }
  for(int i = 1; i <= q; i++) cout << ans[i] << "\n";
  return 0;
}