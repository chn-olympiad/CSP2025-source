#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const int kMaxN = 1e5 + 5;

struct A {
  LL id, x;

  bool operator< (const A &a) const {
    return x > a.x;
  }
} a[kMaxN][3];

LL v[kMaxN], ans, n, t;

void Calc() {
  cin >> n;
  int cnt[3] = {}, tot = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> a[i][j].x;
      a[i][j].id = j;
    }
    sort(a[i], a[i] + 3);
    ans += a[i][0].x;
    cnt[a[i][0].id]++;
  }
  int op = -1;
  for (int i = 0; i < 3; i++) {
    if (cnt[i] > n / 2) {
      op = i;
    }
  }
  if (op == -1) {
    cout << ans << "\n";
  } else {
    for (int i = 1; i <= n; i++) {
      if (a[i][0].id == op) {
        v[++tot] = a[i][1].x - a[i][0].x;
      }
    }
    sort(v + 1, v + tot + 1, greater<LL> ());
    for (int i = 1; i <= cnt[op] - n / 2; i++) {
      ans += v[i];
    }
    cout << ans << "\n";
  }
}

void Init() {
  ans = 0;
}

int main() {
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);
  ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
  for (cin >> t; t; t--) {
    Calc();
    Init();
  }
  return 0;
}
// g++ club.cpp -o club -std=c++14 -O2 -Wall && ./club