#include <bits/stdc++.h>

constexpr int pMod = 998244353;
constexpr int maxN = 501;

template<typename T>
int Add(T x) {
  return x;
}

template<typename T, typename ...Ts>
int Add(T x, Ts ...y) {
  if ((x += Add(y...)) >= pMod) { x -= pMod; }
  return x;
}

template<typename T, typename ...Ts>
void AddC(T &x, Ts ...y) {
  x = Add(x, y...);
}

template<typename T>
int Mul(T x) {
  return x;
}

template<typename T, typename ...Ts>
int Mul(T x, Ts ...y) {
  return int(1LL * x * Mul(y...) % pMod);
}

template<typename T, typename ...Ts>
void MulC(T &x, Ts ...y) {
  x = Mul(x, y...);
}

int main() {
  freopen("employ.in", "r", stdin);
  freopen("employ.out", "w", stdout);
  freopen("employ.err", "w", stderr);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int N, M;
  std::string S;
  std::cin >> N >> M >> S, M = N - M;
  std::vector<int> cnt(N + 1);
  for (int i = 0, x; i < N; i++) { std::cin >> x, cnt[x]++; }
  for (int i = 1; i <= N; i++) { cnt[i] += cnt[i - 1]; }

  std::vector<std::vector<int>> dp(N + 1, std::vector<int>(N + 1));
  dp[0][0] = 1;

  for (auto ty: S) {
    std::vector<std::vector<int>> ndp(N + 1, std::vector<int>(N + 1));
    if (ty == '0') {
      for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
          int val = dp[i][j];
          if (!val) { continue; }
          AddC(ndp[i + 1][j], val);
        }
      }
    } else {
      for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
          int val = dp[i][j];
          if (!val) { continue; }
          if (cnt[i] >= j) {
            AddC(ndp[i + 1][j + 1], Mul(val, cnt[i] - j));
            AddC(ndp[i][j + 1], pMod - Mul(val, cnt[i] - j));
          }
          AddC(ndp[i][j], val);
        }
      }
    }
    std::swap(dp, ndp);
  }

  std::vector<int> fac(N + 1);
  fac[0] = 1;
  for (int i = 1; i <= N; i++) { fac[i] = Mul(fac[i - 1], i); }

  int ans = 0;
  for (int i = 0; i <= M; i++) {
    for (int j = 0; j <= N; j++) { AddC(ans, Mul(dp[i][j], fac[N - j])); }
  }
  std::cout << ans << '\n';

  return 0;
}

/*
g++ employ.cpp -o employ -O2 -std=c++14 -static && 
ulimit -t 1 &&
ulimit -v 256000 &&
cp employ1.in employ.in && ./employ && diff employ.out employ1.ans &&
cp employ2.in employ.in && ./employ && diff employ.out employ2.ans &&
cp employ3.in employ.in && ./employ && diff employ.out employ3.ans &&
cp employ4.in employ.in && ./employ && diff employ.out employ4.ans &&
cp employ5.in employ.in && ./employ && diff employ.out employ5.ans &&
echo Accepted!
*/