#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define PII pair<int, int>
#define _for(i, a, b) for (int i = (a); i <= (b); i++)
#define _pfor(i, a, b) for (int i = (a); i >= (b); i--)

int read() {
  char c;
  int x = 0, f = 1;
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + c - '0';
    c = getchar();
  }
  return x * f;
}

void wr(int x) {
  if (x < 0) x = -x, putchar('-');
  if (x > 9) wr(x / 10);
  putchar(x % 10 + '0');
}

const int N = 5e6 + 5, mod = 998244359;

int n, q;
char a[N], b[N], s[N], t[N];
int h[N], base[N];
map<pair<int, int>, int> vis;
int idx;

struct node {
  int l, r;
  int lh, rh, id;
};

vector<node> has[N]; 


int get_calc(int l, int r) {
  return (1ll * h[r] - 1ll * h[l - 1] * base[r - l + 1] % mod + mod) % mod;
}

map<pair<int, int>, int> vvw, cnt; 
int U[N], V[N];

signed main() {
//  freopen("replace4.in", "r", stdin);
//  freopen("replace4.out", "w", stdout);
  freopen("replace.in", "r", stdin);
  freopen("replace.out", "w", stdout);
  cin >> n >> q;
  base[0] = 1;
  _for(i, 1, N - 5) base[i] = 1ll * base[i - 1] * 131 % mod; 
  _for(i, 1, n) {
    scanf("%s%s", (a + 1), (b + 1)); int sz = strlen(a + 1);
    int l = 1;
    while (l <= sz && a[l] == b[l]) l++;
    int r = sz;
    while (r >= 1 && a[r] == b[r]) r--;
    if (l > r) {
      continue;
    }
    else {
      int ta = 0, tb = 0;
      _for(j, l, r) ta = (1ll * ta * 131 + a[j]) % mod;
      _for(j, l, r) tb = (1ll * tb * 131 + b[j]) % mod;
      int tc = 0, td = 0;
      _for(j, 1, sz) tc = (1ll * tc * 131 + a[j]) % mod;
      _for(j, 1, sz) td = (1ll * td * 131 + b[j]) % mod;
      U[i] = tc; V[i] = td;
      if (!vis[{ta, tb}]) vis[{ta, tb}] = ++idx;
      int t1 = 0, t2 = 0;
      _for(j, 1, l - 1) t1 = (1ll * t1 * 131 + a[j]) % mod;
      _for(j, r + 1, sz) t2 = (1ll * t2 * 131 + a[j]) % mod;
      if (vvw[{tc, td}] == 0) {
        has[vis[{ta, tb}]].push_back({l - 1, sz - r, t1, t2, i});
      }
        vvw[{tc, td}] ++; 
//      cout << l << ' ' << r << ' ' << ta << ' ' << tb << ' ' << t1 << ' ' << t2 << ' ' << idx << endl; 
    }
  } 
  while (q--) {
    scanf("%s%s", (s + 1), (t + 1));
    if (strlen(s + 1) != strlen(t + 1)) puts("0");
    else {
      int sz = strlen(s + 1);
      int l = 1;
      while (l <= sz && s[l] == t[l]) l++;
      int r = sz;
      while (r >= 1 && s[r] == t[r]) r--;
      int ta = 0, tb = 0;
      _for(j, l, r) ta = (1ll * ta * 131 + s[j]) % mod;
      _for(j, l, r) tb = (1ll * tb * 131 + t[j]) % mod;
//      cout << l << ' ' << r << ' ' << ta  << ' ' << tb << endl;
      if (!vis[{ta, tb}]) vis[{ta, tb}] = ++idx;
      h[0] = 0;
      _for(i, 1, sz) h[i] = (1ll * h[i - 1] * 131 + s[i]) % mod;
      int res = 0;
//      cout << "f=" << has[vis[{ta, tb}]].size() << endl;
      for (auto e : has[vis[{ta, tb}]]) {
        int L = e.l, R = e.r; int lh = e.lh, rh = e.rh, id = e.id;
//        cout << "f=" << L << ' ' << R << ' ' << lh << ' ' << rh << endl;
        if (L > l || R > sz - r) continue;
//        cout << r + 1 << ' ' << r + R << ' ' << get_calc(r + 1, r + R) << endl;
        if (get_calc(l - 1 - L + 1, l - 1) == lh && get_calc(r + 1, r + R) == rh) res += vvw[{U[id], V[id]}];
      }
      wr(res); putchar('\n');
    }
  }
}
