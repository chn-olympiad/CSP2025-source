#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

void file () {
  freopen("employ.in", "r", stdin);
  freopen("employ.out", "w", stdout);
}

const int N = 505;
const int kN = N + 5;
const int Mod = 998244353;

int n, m;
int a[kN], b[kN]; 

namespace SolveA {
  const int S = (1 << 18);

  int f[S][20];

  void main () {
    f[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
      for (int s = 0; s < (1 << n); ++s) {
        if (__builtin_popcount(s) != i - 1) {
          continue;
        } 
        for (int j = 1; j <= n; ++j) {
          if ((s >> (j - 1)) & 1) continue;
          for (int k = 0; k < i; ++k) {
            int _k = k;
            if (!a[i] || k >= b[j]) ++_k; 
            int t = s | (1 << (j - 1));
            f[t][_k] = (f[t][_k] + f[s][k]) % Mod; 
          }
        }
      }
    }
    int ans = 0; 
    for (int i = 0; i <= n - m; ++i) {
      ans = (ans + f[(1 << n) - 1][i]) % Mod;
    }
    cout << ans << '\n';
  }
}

namespace SolveB {
  void main () {
    int now = 0; 
    for (int i = 1; i <= n; ++i) {
      now += !a[i];
    } 
    sort(b + 1, b + n + 1);
    int p = n;
    int ans = 1;
    for (int i = n; i; --i) {
      while (true) {
        if (!p) break;
        if (!a[p]) {
          --p;
          continue;
        }
        if (p > b[i]) {
          ++now;
          --p;
        }
        else {
          break;
        }
      }
      ans = ll(ans) * now % Mod;
      --now;
    }
    int all = 1;
    for (int i = 1; i <= n; ++i) {
      all = ll(all) * i % Mod;
    }
    ans = (all - ans + Mod) % Mod;
    cout << ans << '\n';
  }
}

namespace SolveC {
  void main () {
    for (int i = 1; i <= n; ++i) {
      if (!a[i] || !b[i]) {
        cout << 0 << '\n';
        return; 
      }
    }
    int ans = 1;
    for (int i = 1; i <= n; ++i) {
      ans = ll(ans) * i % Mod;
    }
    cout << ans << '\n';
  }
}

namespace SolveD {
  const int tN = 105;

  int f[tN][tN][tN], g[kN][kN];

  void main () {
    sort(b + 1, b + n + 1);
    g[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j < i; ++j) {
        for (int k = 0; j + k < i; ++k) {
          int v = f[i - 1][j][k];
          f[i][j][k] = (f[i][j][k] + ll(v) * (i - k)) % Mod;
          for (int x = 1; x <= k; ++x) {
            if (x + j >= b[i]) {
              f[i][j][k + 1] = (f[i][j][k + 1] + v) % Mod;
            }
            else {
              f[i][j + x][k - x] = (f[i][j + x][k - x] + v) % Mod;
            }
          }
        }
      }
      for (int j = 0; j < i; ++j) {
        int v = g[i - 1][j];
        for (int x = 0; x <= j; ++x) {
          if (x >= b[i]) {
            g[i][j + 1] = (g[i][j + 1] + v) % Mod;
          }
          else {
            f[i][x][j - x] = (f[i][x][j - x] + v) % Mod;
          }
        }
      }
    }
    int ans = 0; 
    for (int j = 0; j <= n - m; ++j) {
      ans = (ans + g[n][j]) % Mod;
    }
    for (int j = 0; j <= n - m; ++j) {
      for (int k = 0; j + k <= n - m; ++k) {
        ans = (ans + f[n][j][k]) % Mod;
      }
    }
    cout << ans << '\n';
  }
}

void fakemain () {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    char c;
    cin >> c;
    a[i] = c - '0';
  }
  for (int i = 1; i <= n; ++i) {
    cin >> b[i];
  }
  if (n <= 18) {
    SolveA::main();
    return;
  }
  if (m == 1) {
    SolveB::main();
    return;
  }
  if (m == n) {
    SolveC::main();
    return;
  }
  bool fl = 1;
  for (int i = 1; i <= n; ++i) {
    fl &= a[i] == 1;
  }
  if (fl) {
    SolveD::main();
    return; 
  }
}

int main () {
  file();
  cin.tie(0)->sync_with_stdio(0);
  fakemain();
  return 0; 
}