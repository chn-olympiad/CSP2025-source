#include <bits/stdc++.h>

using namespace std;

#define int long long
/*
Ren5Jie4Di4Ling5%
*/
const int N = 1e5 + 5;

struct node {
  int x, id;
} a[N][4], b[N];

int t, n, cnt[4], m;

bool cmp(node _x, node _y) {
  return _x.x > _y.x;
}

void print() {
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += a[i][1].x;
  }
  cout << ans << "\n";
}

void Solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 3; j++) {
      cin >> a[i][j].x;
      a[i][j].id = j;
    }
  }
  cnt[1] = cnt[2] = cnt[3] = 0;
  for (int i = 1; i <= n; i++) {
    sort(a[i] + 1, a[i] + 3 + 1, cmp);
    cnt[a[i][1].id]++;
  }
  int p;
  if (cnt[1] > cnt[2] && cnt[1] > cnt[3]) {
    p = 1;
  }
  else if (cnt[2] > cnt[1] && cnt[2] > cnt[3]) {
    p = 2;
  }
  else p = 3;
  if (cnt[p] < n / 2) {
    print();
    return ;
  }
  m = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i][1].id == p) {
      b[++m] = {max(a[i][2].x - a[i][1].x, a[i][3].x - a[i][1].x), i};
    }
  }
  sort(b + 1, b + m + 1, cmp);
  for (int i = 1; i <= cnt[p] - n / 2; i++) {
    //cout << b[i].id << "\n";
    if (b[i].x == a[b[i].id][2].x - a[b[i].id][1].x) {
      swap(a[b[i].id][1], a[b[i].id][2]);
    }
    else swap(a[b[i].id][1], a[b[i].id][3]);
  }
  print();
}

signed main() {
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);
  cin >> t;
  while (t--) {
    Solve();
  }
  return 0;
}
/*
1
2
10 9 8
4 0 0
*/
