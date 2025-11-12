#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

struct Node {
  int id;
  int num;
} a[5];

struct node {
  int bst;
  int bter;
} yione[N], ertwo[N], sanre[N];

int n, num1, num2, num3;
long long ans;

bool cmp(Node a, Node b) { return a.num > b.num; }

bool tmp(node a, node b) { return (a.bst - a.bter) > (b.bst - b.bter); }

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    a[1].id = 1, a[2].id = 2, a[3].id = 3;
    cin >> a[1].num >> a[2].num >> a[3].num;
    sort(a + 1, a + 3 + 1, cmp);
    // cout << i << " " << a[1].num << " " << a[2].num << " " << a[3].num << " "
    // << endl;

    if (a[1].id == 1)
      yione[++num1] = (node){a[1].num, a[2].num};
    else if (a[1].id == 2)
      ertwo[++num2] = (node){a[1].num, a[2].num};
    else
      sanre[++num3] = (node){a[1].num, a[2].num};
  }
  sort(yione + 1, yione + num1 + 1, tmp);
  sort(ertwo + 1, ertwo + num2 + 1, tmp);
  sort(sanre + 1, sanre + num3 + 1, tmp);
  int hlf = n / 2;
  // cout << num2 << endl;
  for (int i = 1; i <= num1; i++) {
    if (i > hlf)
      ans += yione[i].bter;
    else
      ans += yione[i].bst;
  }
  for (int i = 1; i <= num2; i++) {
    // cout << ertwo[i].bst << ' ' << ertwo[i].bter << endl;
    if (i > hlf)
      ans += ertwo[i].bter;
    else
      ans += ertwo[i].bst;
  }
  for (int i = 1; i <= num3; i++) {
    if (i > hlf)
      ans += sanre[i].bter;
    else
      ans += sanre[i].bst;
  }
  cout << ans << endl;
}

void init() {
  ans = 0;
  num1 = 0;
  num2 = 0;
  num3 = 0;
}

int main() {
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);
  int T;
  cin >> T;
  while (T--) {
    init();
    solve();
  }
  return 0;
}