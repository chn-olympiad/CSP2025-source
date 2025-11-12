#include <bits/stdc++.h>
#define file_in(x) (freopen(#x".in", "r", stdin))
#define file_out(x) (freopen(#x".out", "w", stdout))
#define ll long long
#define pc(x) (__builtin_popcount(x))
#define db double

using namespace std;

char _c; bool _f; template <class T> void IN(T & x) {
  _f = x = 0; while (_c = getchar(), !isdigit(_c)) {if (_c == '-') _f = 1;}
  while (isdigit(_c)) {x = x * 10 + _c - '0', _c = getchar();} if (_f) x = -x;
}

template <class T> void _write(T x) {
  if (x < 0) return putchar('-'), _write(-x);
  if (x > 9) _write(x / 10);
  putchar('0' + (x % 10));
}
template <class T> void write_s(T x) {_write(x), putchar(' ');}
template <class T> void write(T x) {_write(x), putchar('\n');}
template <class first, class... rest> void write(first fir, rest... res) {
  write_s(fir), write(res...);
}

#define debug(...) (_debug(#__VA_ARGS__, __VA_ARGS__))
template <class T> void _debug(const char * format, T x) {
  cerr << format << " = " << x << endl;
}
template <class first, class... rest>
void _debug(const char * format, first fir, rest... res) {
  while (*format != ',') cerr << *format++;
  cerr << " = " << fir << ',', _debug(format + 1, res...);
}

bool START;

const int N = 1e4 + 20, M = 1e6 + 5;
const ll inf = 1e18;

int n, m, k, tot;
int f[N], c[20], a[20][N], b[20][N], d[20];
ll ans;

struct edge {
  int x, y, w;
  bool operator < (const edge & o) const {return w < o.w;}
} e[M], es[M], buf[M];

bool END;

int find(int x) {return x == f[x] ? x : f[x] = find(f[x]);}

void init() {
  for (int i = 1; i <= n; ++i) f[i] = i;
  sort(e + 1, e + 1 + m);
  int idx = 0;
  for (int i = 1; i <= m; ++i) {
    int x = find(e[i].x), y = find(e[i].y);
    if (x == y) continue;
    f[x] = y, buf[++idx] = e[i];
  }
  tot = idx;
  for (int i = 1; i <= tot; ++i) e[i] = buf[i];
}

ll calc(int S) {
  ll sum = 0;
  int idx = tot;
  for (int i = 1; i <= idx; ++i) es[i] = e[i];
  for (int i = 0; i < k; ++i)
    if ((S >> i) & 1) {
      sum += c[i];
      for (int j = 1; j <= n; ++j)
	es[++idx] = {n + i + 1, j, a[i][j]};
    }

  for (int i = 1; i <= n + k; ++i) f[i] = i;
  sort(es + 1, es + 1 + idx);
  for (int i = 1; i <= idx; ++i) {
    int x = find(es[i].x), y = find(es[i].y);
    if (x == y) continue;
    f[x] = y, sum += es[i].w;
    if (sum > ans) return inf; // mention
  }
  return sum;
}

void prt(int S) {
  for (int i = 0; i < k; ++i) cout << ((S >> i) & 1);
  cout << endl;
}

bool cmp(int x, int y) {return c[x] < c[y];}

signed main() {
  file_in(road), file_out(road);
  IN(n), IN(m), IN(k);
  for (int i = 1, x, y, w; i <= m; ++i)
    IN(x), IN(y), IN(w), e[i] = {x, y, w};
  for (int i = 0; i < k; ++i) {
    IN(c[i]);
    for (int j = 1; j <= n; ++j) IN(a[i][j]);
  }
  init();
  ans = inf;
  for (int s = 0; s < (1 << k); ++s)
    ans = min(ans, calc(s));
  write(ans);
  return 0;
}
