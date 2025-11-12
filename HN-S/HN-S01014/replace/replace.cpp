#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define sz(x) (int)(x).size()
using ll = long long;
using i128 = __int128;

const int N = 2e5 + 10, L = 5e6 + 10, C = 26;
const ll P = (ll)1e18 + 7243, B = 29262763161284093, IB = 343944063083456837;
int n, q;

mt19937_64 rng(114);
ll rand(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rng); }

ll w[C][C];
ll pw[L], ipw[L];
unordered_map<ll, vector<int>> len;

void init() {
  rep(i, 0, C - 1)
    rep(j, 0, C - 1)
      if(i != j) w[i][j] = rand(1, P - 1);
  pw[0] = ipw[0] = 1;
  rep(i, 1, L - 1) {
    pw[i] = (i128)pw[i - 1] * B % P;
    ipw[i] = (i128)ipw[i - 1] * IB % P;
  }
}

namespace bf {
string s1[N], s2[N];
int f[N];

int first(const string &s1, const string &s2) {
  rep(i, 0, sz(s1) - 1)
    if(s1[i] != s2[i]) return i;
  return sz(s1);
}

int last(const string &s1, const string &s2) {
  for(int i = sz(s1) - 1; i >= 0; --i)
    if(s1[i] != s2[i]) return i;
  return -1;
}

struct Hash {
  vector<ll> h;
  
  void init(const string &s) {
    h.resize(sz(s) + 1);
    rep(i, 0, sz(s) - 1)
      h[i + 1] = ((i128)h[i] * B + s[i]) % P;
  }

  ll get(int l, int r) {
    assert(l >= 1 && r < sz(h));
    return (h[r] + (i128)(P - h[l - 1]) * pw[r - l + 1]) % P;
  }
} a[N], b[N], c, d;

int query(const string &t1, const string &t2) {
  if(sz(t1) != sz(t2)) return 0;
  c.init(t1), d.init(t2);
  int g = first(t1, t2), gg = last(t1, t2);
  int ans = 0;
  rep(i, 1, n) {
    if(f[i] == sz(s1[i])) continue;
    int p = g - f[i];
    if(p >= 0 && p + sz(s1[i]) > gg && p + sz(s1[i]) <= sz(t1) &&
       c.get(p + 1, p + sz(s1[i])) == a[i].h.back() &&
       d.get(p + 1, p + sz(s1[i])) == b[i].h.back())
      ++ans;
  }
  return ans;
}

void solve() {
  rep(i, 1, n) {
    cin >> s1[i] >> s2[i];
    f[i] = first(s1[i], s2[i]);
    a[i].init(s1[i]), b[i].init(s2[i]);
  }
  while(q--) {
    string t1, t2;
    cin >> t1 >> t2;
    cout << query(t1, t2) << "\n";
  }
}
}

ll h(const string &s1, const string &s2) {
  ll ans = 0;
  rep(i, 0, sz(s1) - 1)
    ans = (ans + (i128)w[s1[i] - 'a'][s2[i] - 'a'] * pw[i]) % P;
  return ans;
}

int query(const string &t1, const string &t2) {
  if(sz(t1) != sz(t2)) return 0;
  ll x = h(t1, t2);
  int ans = 0;
  rep(i, 0, sz(t1) - 1) {
    auto it = len.find((i128)x * ipw[i] % P);
    if(it == end(len)) continue;
    const vector<int> &l = it->second;
    // 要求 <= sz(t1) - i
    ans += upper_bound(begin(l), end(l), sz(t1) - i) - begin(l);
  }
  return ans;
}

int main() {
  freopen("replace.in", "r", stdin);
  freopen("replace.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  init();
  cin >> n >> q;
  if((ll)n * q <= (ll)1e8) {
    bf::solve();
    return 0;
  }
  rep(i, 1, n) {
    string s1, s2;
    cin >> s1 >> s2;
    if(s1 != s2) len[h(s1, s2)].push_back(sz(s1));
  }
  for(auto &[h, l] : len) sort(begin(l), end(l));
  while(q--) {
    string t1, t2;
    cin >> t1 >> t2;
    cout << query(t1, t2) << "\n";
  }
}