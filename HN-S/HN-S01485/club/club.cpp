#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

void file () {
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);
}

const int kN = 1e5 + 5;
const int inf = 2e9;

int n;
int a[kN][3], chs[kN];

void fakemain () {
  cin >> n; 
  ll sum = 0; 
  for (int i = 1; i <= n; ++i) {
    cin >> a[i][0] >> a[i][1] >> a[i][2];
    chs[i] = 0; 
    for (int j = 0; j < 3; ++j) {
      if (a[i][j] > a[i][chs[i]]) {
        chs[i] = j;
      }
    }
    sum += a[i][chs[i]];
  }
  int cnt[3] = {0, 0, 0};
  for (int i = 1; i <= n; ++i) {
    ++cnt[chs[i]];
  }
  int mx = max(max(cnt[0], cnt[1]), cnt[2]);
  if (mx > n / 2) {
    int id = 0; 
    for (int i = 0; i < 3; ++i) {
      if (cnt[i] == mx) id = i;
    }
    vector<int> v;
    for (int i = 1; i <= n; ++i) {
      if (chs[i] == id) {
        int del = -inf;
        for (int j = 0; j < 3; ++j) {
          if (j != id) {
            del = max(del, a[i][j] - a[i][id]);
          }
        }
        v.push_back(del);
      }
    }
    sort(v.begin(), v.end(), greater<int>());
    for (int i = 0; i < int(v.size()) - (n / 2); ++i) {
      sum += v[i];
    }
  }
  cout << sum << '\n';
}

int main () {
  file();
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) fakemain();
  return 0; 
}