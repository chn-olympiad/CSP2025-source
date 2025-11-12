#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

const int N = 2e5 + 3, P = 29, C = 2e4 + 3;

struct Node {
  int a[P];
  int l = -1, fa, n, fail = 0;
};

int n, q,tota, totb;

string s, t;

Node a[N], b[N];

void Bfs() {
  queue<int> q;
  for (int i = 0; i < 26; i ++) {
    if (a[0].a[i]) q.push(a[0].a[i]), a[0].fail = -1;
  }
  while (q.size()) {
    int t = q.front();
    q.pop();
    if (a[t].fail == -1) {
      a[t].fail = 0;
    } else {
      a[t].fail = a[a[a[t].fa].fail].a[a[t].n];
    }
    for (int i = 0; i < 26; i ++) {
      if (a[t].a[i]) q.push(a[t].a[i]);
    }
  }
  for (int i = 0; i < 26; i ++) {
    if (b[0].a[i]) q.push(b[0].a[i]), b[0].fail = -1;
  }
  while (q.size()) {
    int t = q.front();
    q.pop();
    if (b[t].fail == -1) {
      b[t].fail = 0;
    } else {
      b[t].fail = b[b[b[t].fa].fail].a[b[t].n];
    }
    for (int i = 0; i < 26; i ++) {
      if (b[t].a[i]) q.push(b[t].a[i]);
    }
  }
}

void KMP() {
  int q, p;
  q = 0;
  for (int i = 0; i < s.size(); i++) {
    if (a[q].a[s[i] - 'a']) q = a[q].a[s[i] - 'a'];
    else if (a[a[q].fa].fail) q = a[a[q].fa].fail, i--;
  }
}

void Solve() {
  cin >> s >> t;
  KMP();
  return ;
}

void Clear() {
  return ;
}

int main() {
  freopen("replace.in", "r", stdin);
  freopen("replace.out", "w", stdout);
  cin >> n >> q;
  for (int i = 1, fa;i <= n; i++) {
    cin >> s >> t;
    fa = 0;
    for (int j = 0; j < s.size(); i++) {
      if (!a[fa].a[s[j] - 'a']) a[fa].a[s[j] - 'a'] = ++tota;
      a[a[fa].a[s[j] - 'a']].fa = fa;
      a[a[fa].a[s[j] - 'a']].n = s[j] - 'a';
      fa = a[fa].a[s[j] - 'a'];
    }
    a[fa].l = i;
    fa = 0;
    for (int j = 0, fa = 0; j < t.size(); i++) {
      if (!b[fa].a[t[j] - 'a']) b[fa].a[t[j] - 'a'] = ++totb;
      b[b[fa].a[t[j] - 'a']].fa = fa;
      b[b[fa].a[t[j] - 'a']].n = t[j] - 'a';
      fa = b[fa].a[t[j] - 'a'];
    }
    b[fa].l = i;
  }
  Bfs();
  while (q--) {
    Clear();
    Solve();
  }
  return 0;
}
