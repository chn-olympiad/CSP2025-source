#include <bits/stdc++.h>
using namespace std;
const int MXN = 100005;
const int K = 3;
int N, val[MXN], cho[MXN], cur[K], sum;

void work() {
  cin >> N;
  sum = 0;
  for (int i(0); i != N; ++i) {
    for (int j(0); j != K; ++j) cin >> cur[j];
    cho[i] = max_element(cur, cur + K) - cur;
    int x(cur[cho[i]]);
    sum += x;
    for (int j(0); j != K; ++j) cur[j] -= x;
    sort(cur, cur + K), val[i] = cur[1];
  }
  memset(cur, 0, sizeof cur);
  for (int i(0); i != N; ++i) ++cur[cho[i]];
  int mxc(max_element(cur, cur + K) - cur);
  if (cur[mxc] <= N / 2) {
    cout << sum << '\n';
    return;
  }
  for (int i(0); i != N; ++i) if (cho[i] != mxc) val[i] = -MXN;
  sort(val, val + N);
  for (int i(N - cur[mxc] + N / 2); i != N; ++i) sum += val[i];
  cout << sum << '\n';
} 

int main() {
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);
  ios::sync_with_stdio(false), cin.tie(nullptr);
  int T(0);
  for (cin >> T; T--;) work();
  return 0;
}
