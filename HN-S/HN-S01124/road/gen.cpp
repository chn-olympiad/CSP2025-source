#include <iostream>
#include <random>
#include <chrono>

using namespace std;

mt19937 rnd(chrono::steady_clock().now().time_since_epoch().count());

int n = 1e4, m = 1e6, k = 10, v = 1e9;

int gen_v() { return rnd() % (v + 1); }

int main() {
  freopen("road.in", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  cout << n << ' ' << m << ' ' << k << '\n';
  for (int i = 2; i <= n; ++i) {
    cout << i << ' ' << rnd() % (i - 1) + 1 << ' ' << gen_v() << '\n';
  }
  for (int i = n; i <= m; ++i) {
    int x, y;
    do {
      x = rnd() % n + 1, y = rnd() % n + 1;
    } while (x == y);
    cout << x << ' ' << y << ' ' << gen_v() << '\n';
  }
  for (int i = 1; i <= k; ++i) {
    for (int j = 0; j <= n; ++j) {
      cout << gen_v() << ' ';
    }
    cout << '\n';
  }
  return 0;
}