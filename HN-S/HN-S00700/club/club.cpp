#include<bits/stdc++.h>
#define rep(i,l,r) for (int i = l; i <= r; i ++)
#define rrp(i,l,r) for (int i = l; i >= r; i --)
using namespace std;
typedef long long LL;

const int N = 5e5 + 5;

int n, a[N][3];
vector<int> id[3];
int val[N], m;

void fakemain() {
  rep (i, 0, 2) id[i].clear();
  cin >> n;
  LL sum = 0;
  rep (i, 1, n) {
    rep (c, 0, 2) cin >> a[i][c];
    int p = max_element(a[i], a[i] + 3) - a[i];
    id[p].push_back(i), sum += a[i][p];
  }
  if (max({id[0].size(), id[1].size(), id[2].size()}) <= n / 2) {
    cout << sum << '\n'; return ;
  }
  int p = 0;
  rep (i, 1, 2) if (id[i].size() > n / 2) p = i;
  m = 0;
  for (auto i : id[p]) {
    sort(a[i], a[i] + 3);
    val[++ m] = a[i][2] - a[i][1];
  }
  sort(val + 1, val + 1 + m);
  int cnt = id[p].size() - n / 2;
  rep (i, 1, cnt) sum -= val[i];
  cout << sum << '\n';
}

void file(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

signed main() {
  cin.tie(0)->ios::sync_with_stdio(0), cout.tie(0);
  file("club");
  int tc, T = 1;
  cin >> T;
  while (T --) fakemain();
  cerr << 1. * clock() / CLOCKS_PER_SEC << "s\n";
}