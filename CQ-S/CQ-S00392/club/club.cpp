#include <bits/stdc++.h>

int main() {
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int test;
  std::cin >> test;
  while (test--) {
    int N, ans = 0;
    std::cin >> N;
    std::vector<int> mx(N), cnt(3);
    std::vector<std::array<int, 3>> A(N);
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < 3; j++) { std::cin >> A[i][j]; }
      mx[i] = 0;
      for (int j = 1; j < 3; j++) {
        if (A[i][j] > A[i][mx[i]]) { mx[i] = j; }
      }
      ans += A[i][mx[i]], cnt[mx[i]]++;
    }
    for (int i = 0; i < 3; i++) {
      if (cnt[i] > N / 2) {
        std::vector<int> arr;
        for (int j = 0; j < N; j++) {
          if (mx[j] != i) { continue; }
          int mi = INT_MAX;
          for (int k = 0; k < 3; k++) {
            if (k != i) { mi = std::min(mi, A[j][i] - A[j][k]); }
          }
          arr.emplace_back(mi);
        }
        std::sort(arr.begin(), arr.end());
        for (int j = 0; j < cnt[i] - N / 2; j++) { ans -= arr[j]; }
      }
    }
    std::cout << ans << '\n';
  }

  return 0;
}

/*
g++ club.cpp -o club -O2 -std=c++14 -static && 
ulimit -t 1 &&
ulimit -v 256000 &&
cp club1.in club.in && ./club && diff club.out club1.ans &&
cp club2.in club.in && ./club && diff club.out club2.ans &&
cp club3.in club.in && ./club && diff club.out club3.ans &&
cp club4.in club.in && ./club && diff club.out club4.ans &&
cp club5.in club.in && ./club && diff club.out club5.ans &&
echo Accepted!
*/