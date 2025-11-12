#include <bits/stdc++.h>
#define int long long //
#define file_in(x) (freopen(#x".in", "r", stdin))
#define file_out(x) (freopen(#x".out", "w", stdout))

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

const int N = 1e5 + 5, inf = 1e18;

int t_c, n, a[N][4], p[N], c[4], b[N], tot;

bool END;

bool cmp(int x, int y) {return x > y;}

signed main() {
  file_in(club), file_out(club);
  IN(t_c);
  while (t_c--) {
    IN(n);
    memset(c, 0, sizeof c);
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
      p[i] = 0;
      for (int j = 1; j <= 3; ++j) {
	IN(a[i][j]);
	if (a[i][j] >= a[i][p[i]]) p[i] = j;
      }
      c[p[i]]++, ans += a[i][p[i]];
    }
    int x = 0;
    for (int i = 1; i <= 3; ++i) if (c[i] > n / 2) x = i;
    if (x) {
      tot = 0;
      for (int i = 1; i <= n; ++i)
	if (p[i] == x) {
	  int mx = -inf;
	  for (int o = 1; o <= 3; ++o)
	    if (o ^ x) mx = max(mx, a[i][o] - a[i][x]);
	  b[++tot] = mx;
	}
      sort(b + 1, b + 1 + tot, cmp);
      for (int i = 1; i <= c[x] - n / 2; ++i) ans += b[i];
    }
    write(ans);
  }
  return 0;
}
