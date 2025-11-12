/*
g++ -Wall -O2 -std=c++14 -static seat.cpp -o seat && ./seat
*/
#include <bits/stdc++.h>
using namespace std;
int n, m;
struct Node {
  int idx, mrk;
};
vector<Node> a;
bool cmp(Node x, Node y) {
  return x.mrk > y.mrk;
}
signed main() {
  freopen("seat.in", "r", stdin);
  // freopen("seat3.in", "r", stdin); /////
  freopen("seat.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0);
  // snake?
  cin >> n >> m;
  a.resize(n * m);
  for (int i = 0; i < n * m; i++) {
    a[i].idx = i + 1; /////
    cin >> a[i].mrk;
  }
  sort(a.begin(), a.end(), cmp);
  // a1
  for (int i = 0; i < n * m; i++) {
    if (a[i].idx == 1) {
      int x = (i / n) + 1, y = (i % n) + 1;
      if (x % 2 == 0) { // even column
        y = n - y + 1;
      }
      cout << x << ' ' << y << '\n';
      break;
    }
  }
  return 0;
}