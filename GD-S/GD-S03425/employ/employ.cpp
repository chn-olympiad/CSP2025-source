#include <bits/stdc++.h>
using namespace std;

const int MXN = 505;
const int P = 998244353;
int N, M, human[MXN];
string str;
int perm[MXN], ans;

int main() {
  freopen("employ.in", "r", stdin);
  freopen("employ.out", "w", stdout);
  ios::sync_with_stdio(false), cin.tie(nullptr);
  cin >> N >> M >> str;
  for (int i(0); i != N; ++i) cin >> human[i];
  iota(perm, perm + N, 0);
  do {
    int failed(0), succ(0);
    for (int i(0); i != N; ++i)
      if (str[i] == '0') ++failed;
      else if (failed >= human[perm[i]]) ++failed;
      else ++succ;
    if (succ >= M) ++ans;
  } while (next_permutation(perm, perm + N));
  cout << ans << endl;
  return 0;
}


/*

#include <bits/stdc++.h>
using namespace std;

const int MXN = 505;
const int P = 998244353;
int N, M, human[MXN];
int cnt[2][MXN][MXN];
string str;

int main() {
  freopen("employ.in", "r", stdin);
  freopen("employ.out", "w", stdout);
  ios::sync_with_stdio(false), cin.tie(nullptr);
  cin >> N >> M >> str;
  for (char &c : str) c = "10"[c - '0'];
  for (int i(0); i != N; ++i) cin >> human[i], human[i] = min(human[i], N - M + 1);
  sort(human, human + N);
  cnt[0][0][0] = 1;
  auto add = [](int &a, long long b) { a = (a + b) % P; };
  for (int i(0), hc(0); i <= N - M + 1; ++i) {
    while (hc != N && human[hc] == i) {
      // insert a human
      for (int j(0); j <= N; ++j) {
        for (int k(0); k <= hc; ++k) {
          if (j - (hc - k) > 0) add(cnt[1][j][k], cnt[0][j][k] * 1LL * (j - (hc - k))); // be chosen
          add(cnt[1][j][k + 1], cnt[0][j][k]); // stay free
        }
      }
      ++hc;
      for (int j(0); j <= N; ++j)
        for (int k(max(0, hc - 1 - j)); k <= hc; ++k)
          cnt[0][j][k] = cnt[1][j][k], cnt[1][j][k] = 0;
//    cout << "inserted human " << i << endl;
//    for (int j(0); j <= N; ++j) {
//      for (int k(0); k <= hc; ++k) {
//        cout.width(8), cout << cnt[0][j][k];
//      }
//      cout << endl;
//    }
    }
    if (i == N - M + 1) break;
    // move forward
    for (int j(0); j != N; ++j) {
      if (str[j] == '0') {
        for (int k(0); k <= hc; ++k) {
          if (k) add(cnt[1][j + 1][k - 1], cnt[0][j][k] * 1LL * k);
          add(cnt[0][j + 1][k], cnt[0][j][k]);
        }
      } else {
        for (int k(0); k <= hc; ++k) {
          if (k) add(cnt[1][j + 1][k - 1], cnt[0][j][k] * 1LL * k);
          add(cnt[1][j + 1][k], cnt[0][j][k]);
        }
      }
    }
    for (int k(0); k <= hc; ++k) add(cnt[1][N][k], cnt[0][N][k]);
    for (int j(0); j <= N; ++j)
      for (int k(0); k <= hc; ++k)
        cnt[0][j][k] = cnt[1][j][k], cnt[1][j][k] = 0;
//  cout << "moved forward " << i << endl;
//  for (int j(0); j <= N; ++j) {
//    for (int k(0); k <= hc; ++k) {
//      cout.width(8), cout << cnt[0][j][k];
//    }
//    cout << endl;
//  }
  }
  cout << cnt[0][N][0] << '\n';
  return 0;
}

*/
