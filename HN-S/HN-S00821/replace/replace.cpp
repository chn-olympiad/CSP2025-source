#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Pii = pair<int, int>;

const int N = 1e5 + 5, M = 1e7 + 5;

struct H {
  int sn[26], fl, sz;

  H() {
    memset(sn, 0, sizeof(sn));
    fl = sz = 0;
  }
} st;

struct A {
  int hd = 1, tl;
  vector<H> sn;
  vector<int> q;

  A() {
    sn.emplace_back(st);
    q.emplace_back(0);
  }

  void I(string &s) {
    int p = 0;
    for (char i : s) {
      if (!sn[p].sn[i - 'a']) {
        sn[p].sn[i - 'a'] = sn.size();
        sn.emplace_back(st);
      }
      p = sn[p].sn[i - 'a'];
    }
    sn[p].sz++;
  }

  void B() {
    for (int j = 0; j < 26; j++) {
      if (sn[0].sn[j]) {
        q.emplace_back(sn[0].sn[j]);
        tl++;
      }
    }
    for (; hd <= tl;) {
      int x = q[hd++];
      for (int j = 0; j < 26; j++) {
        if (sn[x].sn[j]) {
          sn[sn[x].sn[j]].fl = sn[sn[x].fl].sn[j];
          q.emplace_back(sn[x].sn[j]);
          tl++;
        } else {
          sn[x].sn[j] = sn[sn[x].fl].sn[j];
        }
      }
    }
    for (int i = 1; i <= tl; i++) {
      sn[q[i]].sz += sn[sn[q[i]].fl].sz;
    }
  }
} a[N];

int n, q, sn[M][26], ct = 1, h[M];
string s, t, g;

int I(string &s, int x) {
  int p = 1;
  for (char i : s) {
    if (!sn[p][i - 'a']) {
      if (!x) {
        return 0;
      }
      sn[p][i - 'a'] = ++ct;
    }
    p = sn[p][i - 'a'];
  }
  return h[p] = !h[p] ? x : h[p];
}

int main() {
  freopen("replace.in", "r", stdin);
  freopen("replace.out", "w", stdout);
  cin.tie(0)->ios::sync_with_stdio(0);
  cin >> n >> q;
  for (int i = 1, l, r, p; i <= n; i++) {
    cin >> s >> t;
    l = -1;
    r = s.size();
    if (s == t) {
      continue;
    }
    for (; l < (int)s.size() && s[l + 1] == t[l + 1]; l++) {
    }
    for (; r && s[r - 1] == t[r - 1]; r--) {
    }
    for (int j = l + 1; j < r; j++) {
      g.push_back(s[j]);
    }
    for (int j = l + 1; j < r; j++) {
      g.push_back(t[j]);
    }
    p = I(g, i);
    g.clear();
    for (int j = 0; j <= l; j++) {
      g.push_back(s[j]);
    }
    for (int j = r; j < s.size(); j++) {
      g.push_back(s[j]);
    }
    a[p].I(g);
    g.clear();
  }
  for (int i = 1; i <= n; i++) {
    a[i].B();
  }
  for (int l, r, p; q--; g.clear()) {
    cin >> s >> t;
    if (s.size() != t.size()) {
      cout << "0\n";
      continue;
    }
    l = -1;
    r = s.size();
    for (; l < (int)s.size() && s[l + 1] == t[l + 1]; l++) {
    }
    for (; r && s[r - 1] == t[r - 1]; r--) {
    }
    for (int j = l + 1; j < r; j++) {
      g.push_back(s[j]);
    }
    for (int j = l + 1; j < r; j++) {
      g.push_back(t[j]);
    }
    p = I(g, 0);
    g.clear();
    if (!p) {
      cout << "0\n";
      continue;
    }
    for (int j = 0; j <= l; j++) {
      g.push_back(s[j]);
    }
    for (int j = r; j < s.size(); j++) {
      g.push_back(s[j]);
    }
    int d = (l == -1) * a[p].sn[0].sz, w = 0;
    for (char i = 0; i < g.size(); i++) {
      w = a[p].sn[w].sn[g[i] - 'a'];
      d += (i >= l - 1) * a[p].sn[w].sz;
    }
    g.clear();
    for (int j = r; j < s.size(); j++) {
      g.push_back(s[j]);
    }
    w = 0;
    for (char i = 0; i < g.size(); i++) {
      w = a[p].sn[w].sn[g[i] - 'a'];
      d -= a[p].sn[w].sz;
    }
    g.clear();
    cout << d << '\n';
  }
  return 0;
}
/*
g++ replace.cpp -o replace -std=c++14 -O2 -Wall -Wextra  && ./replace
 */