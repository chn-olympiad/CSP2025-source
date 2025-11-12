#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Pii = pair<int, int>;

const int N = 1e5 + 5;

int t, n, a[N][3], b[N], c[3], h[N];
priority_queue<Pii> pq;
ll r;

int main() {
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);
  cin.tie(0)->ios::sync_with_stdio(0);
  for (cin >> t; t--; r = c[0] = c[1] = c[2] = 0) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i][0] >> a[i][1] >> a[i][2];
      c[b[i] = max_element(a[i], a[i] + 3) - a[i]]++;
      r += max({a[i][0], a[i][1], a[i][2]});
    }
    if (c[0] > n / 2) {
      for (int i = 1; i <= n; i++) {
        if (!b[i]) {
          pq.push({a[i][1] - a[i][0], i});
          pq.push({a[i][2] - a[i][0], i});
        }
      }
      for (; c[0] > n / 2; c[0]--, pq.pop()) {
        for (; h[pq.top().second]; pq.pop()) {
        }
        r += pq.top().first;
        h[pq.top().second] = 1;
      }
    } else if (c[1] > n / 2) {
      for (int i = 1; i <= n; i++) {
        if (b[i] == 1) {
          pq.push({a[i][2] - a[i][1], i});
          pq.push({a[i][0] - a[i][1], i});
        }
      }
      for (; c[1] > n / 2; c[1]--, pq.pop()) {
        for (; h[pq.top().second]; pq.pop()) {
        }
        r += pq.top().first;
        h[pq.top().second] = 1;
      }
    } else if (c[2] > n / 2) {
      for (int i = 1; i <= n; i++) {
        if (b[i] == 2) {
          pq.push({a[i][1] - a[i][2], i});
          pq.push({a[i][0] - a[i][2], i});
        }
      }
      for (; c[2] > n / 2; c[2]--, pq.pop()) {
        for (; h[pq.top().second]; pq.pop()) {
        }
        r += pq.top().first;
        h[pq.top().second] = 1;
      }
    }
    cout << r << '\n';
    fill(h, h + n + 1, 0);
    for (; pq.size(); pq.pop()) {
    }
  }
  return 0;
}
/*
g++ club.cpp -o club -std=c++14 -O2 && ./club
 */