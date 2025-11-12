#include <bits/stdc++.h>

using LL = long long;
using namespace std;

const int N = 1e5 + 10;
int a[N][3], b[N], pos[N];

int main() {
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < 3; j++) {
        cin >> a[i][j];
      }
    }
    LL sum = 0;
    int cnt[3] {};
    for (int i = 1; i <= n; i++) {
      int mx = 0, p = 0;
      for (int j = 0; j < 3; j++) {
        if (a[i][j] > mx) {
          p = i;
          mx = a[i][j], p = j;
        }
      }
      cnt[p]++;
      pos[i] = p;
      b[i] = mx;
      sum += mx;
    }
    priority_queue<int> pq;
    int mxp = *max_element(cnt, cnt + 3), q = 0;
    if (mxp > n / 2) {
      q = max_element(cnt, cnt + 3) - cnt;
      for (int i = 1; i <= n; i++) {
        if (pos[i] == q) {
          int sec = 0;
          for (int j = 0; j < 3; j++) {
            if (j != pos[i]) {
              sec = max(sec, a[i][j]);
            }
          }
          pq.emplace(sec - b[i]);
        }
      }
      for (int i = 0; i < mxp - n / 2; i++) {
        sum += pq.top();
        pq.pop();
      }
    }
    cout << sum << '\n';
  }
  return 0;
}