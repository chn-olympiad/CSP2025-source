#include <bits/stdc++.h>
#define file_in(x) (freopen(#x".in", "r", stdin))
#define file_out(x) (freopen(#x".out", "w", stdout))
#define ll long long
#define pc(x) (__builtin_popcount(x))

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

const int N = 505, mod = 998244353;

void add(int & x, int y) {x += y; if (x >= mod) x -= mod;}
int pls(int x, int y) {x += y; if (x >= mod) x -= mod; return x;}
int mul(int x, int y) {return 1ull * x * y % mod;}

int n, m, c[N], cnt[N], sz[N];
int f[2][N][N];
int fac[N], C[N][N];
char s[N];

bool END;

signed main() {
  file_in(employ), file_out(employ);
  IN(n), IN(m), scanf(" %s", s + 1);
  for (int i = 1; i <= n; ++i) IN(c[i]), cnt[c[i]]++, sz[c[i]]++;
  for (int i = 1; i <= n; ++i) sz[i] += sz[i - 1];

  fac[0] = 1; for (int i = 1; i <= n; ++i) fac[i] = mul(fac[i - 1], i);
  C[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    C[i][0] = 1;
    for (int j = 1; j <= i; ++j) C[i][j] = pls(C[i - 1][j], C[i - 1][j - 1]);
  }

  f[0][0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    int o = (i & 1);
    for (int j = 0; j <= min(n - m, i); ++j)
      for (int p = 0; p <= i; ++p)
	f[o][j][p] = 0;
    for (int j = 0; j <= min(n - m, i - 1); ++j)
      for (int p = 0; p <= i - 1; ++p)
	if (f[o ^ 1][j][p]) {
	  if (s[i] == '1') {
	    add(f[o][j][p], f[o ^ 1][j][p]); // use
	    
	    for (int x = 0; x <= i - 1 - p; ++x) { // not use
	      int t = mul(f[o ^ 1][j][p], sz[j] - p);
	      t = mul(t, mul(C[i - 1 - p][x], mul(C[cnt[j + 1]][x], fac[x])));
	      add(f[o][j + 1][p + 1 + x], t);
	    }
	  }
	  else {
	    for (int x = 0; x <= i - 1 - p + 1; ++x) { // c > j
	      int t = f[o ^ 1][j][p];
	      t = mul(t, mul(C[i - 1 - p + 1][x], mul(C[cnt[j + 1]][x], fac[x])));
	      //	      debug(i, j + 1, p + x, x, t);
	      add(f[o][j + 1][p + x], t);
	    }
	    
	    for (int x = 0; x <= i - 1 - p; ++x) { // c <= j
	      int t = mul(f[o ^ 1][j][p], sz[j] - p);
	      t = mul(t, mul(C[i - 1 - p][x], mul(C[cnt[j + 1]][x], fac[x])));
	      //	      debug(i, j + 1, p + 1 + x, t);
	      add(f[o][j + 1][p + 1 + x], t);
	    }
	  }
	}
  }
  int ans = 0;
  for (int j = 0; n - j >= m; ++j) {
    int x = sz[n] - sz[j];
    if (x >= 0 && x <= n) add(ans, mul(f[n & 1][j][n - x], fac[x]));
  }
  write(ans);
  return 0;
}
