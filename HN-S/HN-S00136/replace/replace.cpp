#include<bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); i ++) 
#define per(i, a, b) for(int i = (a); i >= (b); i --)
// #define int long long
#define RD read()
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while(ch < '0' || ch > '9') { if(ch == '-') f = -1; ch = getchar(); }
  while('0' <= ch && ch <= '9') { x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar(); }
  return x * f;
}

int const N = 2e5 + 5, M = 5e6 + 5, P = 1e9 + 9, Base = 131;

int n, m;
char s[M], t[M];
int h1[M], h2[M], pw[M], a[N], val[N << 1], tot, b[N];
int hsh[N];
int getHash(int h[], int l, int r) { 
  return (h[r] - 1ll * h[l - 1] * pw[r - l + 1] % P + P) % P;
}

pair<int, int> deal() {
  scanf("%s", s + 1);
  scanf("%s", t + 1);
  int len = strlen(s + 1);
  rep(i, 1, len) h1[i] = (1ll * h1[i - 1] * Base % P + s[i] - 'a' + 1) % P;
  rep(i, 1, len) h2[i] = (1ll * h2[i - 1] * Base % P + t[i] - 'a' + 1) % P;
  int l = 0, r = 0;
  rep(i, 1, len) {
    if(s[i] ^ t[i]) break;
    l = i;
  }
  per(i, len, 1) {
    if(s[i] ^ t[i]) break;
    r = len - i + 1;
  }
  return {l, r};
}

struct info {
  int l, r, len, v;
} p[N], q[N];

struct tag {
  int l, v, id;
} ;
vector<tag> A[M], Q[M];

int rt[N << 1];
namespace ds {
  struct node {
    int l, r, s;
  } t[N * 20 * 2];
  int idx;
  #define ls t[k].l
  #define rs t[k].r
  #define mid ((L + R) >> 1)
  void insert(int &k, int L, int R, int x, int v) {
    if(!k) k = ++ idx;
    if(L == R) return t[k].s += v, void();
    x <= mid ? insert(ls, L, mid, x, v) : insert(rs, mid + 1, R, x, v);
    t[k].s = t[ls].s + t[rs].s;
  }
  int query(int k, int L, int R, int x, int y) {
    if(y < L || x > R || !k) return 0;
    if(x <= L && R <= y) return t[k].s;
    return query(ls, L, mid, x, y) + query(rs, mid + 1, R, x, y);
  }
}
using ds :: insert;
using ds :: query;

// namespace ACAM {
//   int ch[M][26];
//   int idx = 1, cnt[M];
//   void insert(char s[]) {
//     int len = strlen(s + 1);
//     int p = 1;
//     rep(i, 1, len) {
//       int v = s[i] - 'a';
//       if(!ch[p][v]) ch[p][v] = ++ idx;
//       p = ch[p][v];
//     } cnt[p] ++;
//   }
//   int fail[M];
//   void build() {
//     rep(i, 0, 25) ch[0][i] = 1;
//     queue<int> q; q.push(1);
//     while(q.size()) {
//       int u = q.front(); q.pop();
//       cnt[u] += cnt[fail[u]];
//       rep(i, 0, 25) {
//         if(!ch[u][i]) ch[u][i] = ch[fail[u]][i];
//         else fail[ch[u][i]] = ch[fail[u]][i], q.push(ch[u][i]);
//       }
//     }
//   }
//   int query(char s[], int l, int r) {
//     int p = 1, res = 0;
//     rep(i, l, r) {
//       int v = s[i] - 'a';
//       p = ch[p][v];
//       res += cnt[p];
//     } return res;
//   }
// }

int ans[N];

namespace sub1 { // qn
  void work() {
    rep(i, 1, m) {
      pair<int, int> res = deal();
      int l = res.first, r = res.second, len = strlen(s + 1);
      b[i] = (1ll * getHash(h1, l + 1, len - r) * pw[len - l - r] % P + getHash(h2, l + 1, len - r)) % P;
      val[++ tot] = b[i];
      q[i].l = l, q[i].r = r;
      // int v1 = ACAM :: query(s, 1, l);
      // int v2 = ACAM :: query(s, len - r + 1, len);
      // ans[i] += v1 + v2;
      rep(j, 1, n) if(~a[j] && p[j].l <= l && p[j].r <= r) {
        if(p[j].len - p[j].l - p[j].r != len - l - r) continue;
        int now = (1ll * getHash(h1, l - p[j].l + 1, len - r + p[j].r) * pw[p[j].len] % P + 
        getHash(h2, l - p[j].l + 1, len - r + p[j].r)) % P;
        if(now == hsh[j]) ans[i] ++;
        // printf()
      }
      printf("%d\n", ans[i]);
    }
  }
}

namespace sub2 { // B
  void work() {
    rep(i, 1, m) {
      pair<int, int> res = deal();
      int l = res.first, r = res.second, len = strlen(s + 1);
      assert(l + r < len);
      b[i] = (1ll * getHash(h1, l + 1, len - r) * pw[len - l - r] % P + getHash(h2, l + 1, len - r)) % P;
      val[++ tot] = b[i];
      q[i].l = l, q[i].r = r;
      // if(i == 173) {
      //   cout << s + 1 << endl;
      //   cout << t + 1 << endl;
      // }
    }

    sort(val + 1, val + 1 + tot);
    tot = unique(val + 1, val + 1 + tot) - val - 1;

    rep(i, 1, n) if(~a[i]) {
      int v = lower_bound(val + 1, val + 1 + tot, a[i]) - val;
      p[i].v = v;
    }
    rep(i, 1, m) {
      int v = lower_bound(val + 1, val + 1 + tot, b[i]) - val;
      q[i].v = v;
    }

    // rep(i, 1, n) if(p[i].v == 311 && (~a[i])) printf("i = %d, (%d, %d, %d)\n", i, p[i].l, p[i].r, p[i].v);
    // rep(i, 1, m) if(i == 173) printf("i = %d, (%d, %d, %d)\n", i, q[i].l, q[i].r, q[i].v);
    
    rep(i, 1, n) if(~a[i]) A[p[i].r].push_back({p[i].l, p[i].v, i});
    rep(i, 1, m) Q[q[i].r].push_back({q[i].l, q[i].v, i});

    rep(i, 0, M - 2) if(A[i].size() || Q[i].size()) {
      for(tag x : A[i]) {
        // if(x.v == 311) printf("ins i = %d, l = %d\n", i, x.l);
        insert(rt[x.v], 0, 5e6, x.l, 1);
      }
      for(tag x : Q[i]) {
        // if(x.id == 173) printf("Q i = %d, l = %d\n", i,/);
        int res = query(rt[x.v], 0, 5e6, 0, x.l);
        ans[x.id] += res;
      }
    }

    // cerr << "idx = " << ds :: idx << endl;
    rep(i, 1, m) printf("%d\n", ans[i]);
  }
}

signed main() {
  freopen("replace.in", "r", stdin);
  freopen("replace.out", "w", stdout);

  n = RD, m = RD;
  
  pw[0] = 1;
  rep(i, 1, M - 2) pw[i] = 1ll * pw[i - 1] * Base % P;
  rep(i, 1, n) {
    pair<int, int> res = deal();
    int l = res.first, r = res.second, len = strlen(s + 1);
    if(l == len) {
      a[i] = -1;
    } else {
      assert(l + r < len);
      a[i] = (1ll * getHash(h1, l + 1, len - r) * pw[len - l - r] % P + getHash(h2, l + 1, len - r)) % P;
      val[++ tot] = a[i];
      p[i].l = l, p[i].r = r;
      hsh[i] = (1ll * h1[len] * pw[len] % P + h2[len]) % P;
      // printf("hash = %d\n", a[i]);
      p[i].len = len;
    }
  }

  // ACAM :: build();

  // sub1 :: work();
  
  if(n * m <= 1e8) sub1 :: work();
  else sub2 :: work();

  return 0;
}