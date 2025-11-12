#include <bits/stdc++.h>
using namespace std;
const int MXN = 200005;
const int MXL = 5000005 + MXN;
const int CHST = 26;
const char OFF = 'a';
int N, Q, C, L, rt[MXN][2], apos[MXN][2], qpos[MXN][2], ans[MXN];
string s1, s2, lcp, lcs;
int son[MXL][CHST];
int dfn[MXL], dfe[MXL], did;
tuple<int, int, int> tasks[MXN * 2];
pair<int, int> qs[MXN];
int T, S;

int trie_insert(int p, const string& s, bool auto_insert) {
  for (char c : s) {
    c -= OFF;
    int &q(son[p][c]);
    if (!q) {
      if (!auto_insert) return p;
      q = ++L;
    }
    p = q;
  }
  return p;
}

// s1, s2 -> new s1, new s2, reversed lcp, lcs, return color
int split(bool auto_insert) {
  int n(s1.size());
  int p(0), s(0);
  while (s1[p] == s2[p]) ++p;
  while (s1[n - 1 - s] == s2[n - 1 - s]) ++s;
  lcp = s1.substr(0, p), lcs = s1.substr(n - s, s);
  s1 = {s1.begin() + p, s1.end() - s};
  s2 = {s2.begin() + p, s2.end() - s};
  reverse(lcp.begin(), lcp.end());

  static map<pair<string, string>, int> dict;
  auto it(dict.find(make_pair(s1, s2)));
  if (it != dict.end()) return it->second;
  if (auto_insert) {
    dict[make_pair(s1, s2)] = C;
    rt[C][0] = ++L;
    rt[C][1] = ++L;
    return C++;
  }
  return -1;
}

void label(int p) {
  dfn[p] = did++;
  for (int q : son[p]) if (q) label(q);
  dfe[p] = did;
}

namespace BIT {

int sum[MXL];
void add(int p, int v) {
  for (++p; p <= L; p += p & -p) sum[p] += v;
}
int query(int p) {
  int s(0);
  for (++p; p; p -= p & -p) s += sum[p];
  return s;
}

} // namespace BIT

int main() {
  freopen("replace.in", "r", stdin);
  freopen("replace.out", "w", stdout);
  ios::sync_with_stdio(false), cin.tie(nullptr);
  cin >> N >> Q;
//long long t1(0), t2(0), t3(0);
//cerr << "offset:" << clock() * 1.0 / CLOCKS_PER_SEC << endl;
  for (int i(0); i != N; ++i) {
//  t1 -= (long long)(clock());
    cin >> s1 >> s2;
//  t1 += (long long)(clock());
    if (s1 == s2) {
      apos[i][0] = apos[i][1] = -1;
      continue;
    }
//  t2 -= (long long)(clock());
    int id(split(true));
//  t2 += (long long)(clock());
//  t3 -= (long long)(clock());
    apos[i][0] = trie_insert(rt[id][0], lcp, true);
    apos[i][1] = trie_insert(rt[id][1], lcs, true);
//  t3 += (long long)(clock());
  }
//cerr << "after apos: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
//cerr << "t1:" << t1 * 1.0 / CLOCKS_PER_SEC << endl;
//cerr << "t2:" << t2 * 1.0 / CLOCKS_PER_SEC << endl;
//cerr << "t3:" << t3 * 1.0 / CLOCKS_PER_SEC << endl;
  for (int i(0); i != Q; ++i) {
    cin >> s1 >> s2;
    if (s1.size() != s2.size()) {
      qpos[i][0] = qpos[i][1] = -1;
      continue;
    }
    int id(split(false));
    if (id == -1) {
      qpos[i][0] = qpos[i][1] = -1;
      continue;
    }
    qpos[i][0] = trie_insert(rt[id][0], lcp, false);
    qpos[i][1] = trie_insert(rt[id][1], lcs, false);
  }
//cerr << "after qpos: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
  for (int i(0); i != C; ++i) label(rt[i][0]), label(rt[i][1]);
//cerr << "before sweeping: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
  for (int i(0); i != N; ++i) {
    if (apos[i][0] == -1) continue;
    int l0(dfn[apos[i][0]]), r0(dfe[apos[i][0]]);
    tasks[T++] = {l0, i, 1};
    tasks[T++] = {r0, i, -1};
  }
  sort(tasks, tasks + T);
  for (int i(0); i != Q; ++i)
    if (~qpos[i][0]) qs[S++] = {dfn[qpos[i][0]], i};
  sort(qs, qs + S);
  for (int i(0), tid(0); i != S; ++i) {
    for (; tid != T && get<0>(tasks[tid]) <= qs[i].first; ++tid) {
      auto [pos, id, v] = tasks[tid];
      int l1(dfn[apos[id][1]]), r1(dfe[apos[id][1]]);
      BIT::add(l1, v), BIT::add(r1, -v);
    }
    int qi(qs[i].second);
    int p(dfn[qpos[qi][1]]);
    ans[qi] = BIT::query(p);
  }
  for (int i(0); i != Q; ++i) cout << ans[i] << '\n';
  return 0;
}
