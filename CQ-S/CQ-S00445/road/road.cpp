#include <bits/stdc++.h>
using namespace std;

#define int long long
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

const int N = 2e6 + 5;


int n, m, k, tot, tot3, idx = n, p[N], res, val[11], a[11][10005], U[N], V[N], W[N], vv[N], sz[N];
int id[N];

struct edge {
  int u, v, w;
}ed[N], ed2[N], ed3[N];
int tot2;

int find(int x) {
  if (p[x] != x) p[x] = find(p[x]);
  return p[x];
}

struct ffa {
  int val, id;
}ff[N]; 


signed main() {
//  freopen("road3.in", "r", stdin);
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);
  cin >> n >> m >> k; 
  _for(i, 1, m) {
    int u, v, w;
    u = read(), v = read(), w = read();
    U[i] = u, V[i] = v, W[i] = w;
    ed[++tot] = {u, v, w};
  }
  sort(ed + 1, ed + tot + 1, [](edge x, edge y) {
    return x.w < y.w; 
  });
  _for(i, 1, k) {
    val[i] = read(); id[i] = i; vv[i] = 2e9;
    _for(j, 1, n) a[i][j] = read(), vv[i] = min(vv[i], a[i][j]); 
    ff[i] = {vv[i] + val[i], i};
  }
  sort(ff + 1, ff + k + 1, [](ffa x, ffa y) {
    return x.val < y.val;
  });
  int maxn = 2e18;
  if (k <= 5) {
    _for(cas, 0, (1 << k) - 1) {
      int idx = n, res = 0; tot2 = 0;
      _for(i, 0, k - 1) {
        if (cas >> i & 1) {
          idx++; res += val[i + 1];
          _for(j, 1, n) ed2[++tot2] = {idx, j, a[i + 1][j]};
        }
      } 
      sort(ed2 + 1, ed2 + tot2 + 1, [](edge x, edge y) {
        return x.w < y.w; 
      });
      tot3 = 0;
      int l = 1, r = 1;
      while (l <= tot && r <= tot2) {
        if (ed[l].w < ed2[r].w) ed3[++tot3] = ed[l], l++;
        else ed3[++tot3] = ed2[r], r++;
      }
      while (l <= tot) ed3[++tot3] = ed[l], l++;
      while (r <= tot2) ed3[++tot3] = ed2[r], r++; 
      _for(i, 1, idx) p[i] = i, sz[i] = 1;
      _for(i, 1, tot3) {
        int u = ed3[i].u, v = ed3[i].v, w = ed3[i].w;
        int fx = find(u), fy = find(v);
        if (sz[fx] > sz[fy]) swap(fx, fy);
        if (fx != fy) p[fx] = fy, res += w, sz[fy] += sz[fx]; 
      }
      maxn = min(maxn, res);
    } 
    cout << maxn << endl;
    return 0;
  }
  _for(cas, 1, k) {
    int idx = n, res = 0; tot2 = 0;
    _for(i, 1, cas) {
      idx++; res += val[ff[i].id];
      _for(j, 1, n) ed2[++tot2] = {idx, j, a[ff[i].id][j]};
    } 
    sort(ed2 + 1, ed2 + tot2 + 1, [](edge x, edge y) {
      return x.w < y.w; 
    });
    tot3 = 0;
    int l = 1, r = 1;
    while (l <= tot && r <= tot2) {
      if (ed[l].w < ed2[r].w) ed3[++tot3] = ed[l], l++;
      else ed3[++tot3] = ed2[r], r++;
    }
    while (l <= tot) ed3[++tot3] = ed[l], l++;
    while (r <= tot2) ed3[++tot3] = ed2[r], r++; 
    _for(i, 1, idx) p[i] = i, sz[i] = 1;
    _for(i, 1, tot3) {
      int u = ed3[i].u, v = ed3[i].v, w = ed3[i].w;
      int fx = find(u), fy = find(v);
      if (sz[fx] > sz[fy]) swap(fx, fy);
      if (fx != fy) p[fx] = fy, res += w, sz[fy] += sz[fx]; 
    }
    maxn = min(maxn, res);
  }
  _for(cas, 0, (1 << k) - 1) {
    int idx = n, res = 0; tot2 = 0;
    if (k - __builtin_popcount(cas) > 1) continue;
    _for(i, 0, k - 1) {
      if (cas >> i & 1) {
        idx++; res += val[i + 1];
        _for(j, 1, n) ed2[++tot2] = {idx, j, a[i + 1][j]};
      }
    } 
    sort(ed2 + 1, ed2 + tot2 + 1, [](edge x, edge y) {
      return x.w < y.w; 
    });
    tot3 = 0;
    int l = 1, r = 1;
    while (l <= tot && r <= tot2) {
      if (ed[l].w < ed2[r].w) ed3[++tot3] = ed[l], l++;
      else ed3[++tot3] = ed2[r], r++;
    }
    while (l <= tot) ed3[++tot3] = ed[l], l++;
    while (r <= tot2) ed3[++tot3] = ed2[r], r++; 
    _for(i, 1, idx) p[i] = i, sz[i] = 1;
    _for(i, 1, tot3) {
      int u = ed3[i].u, v = ed3[i].v, w = ed3[i].w;
      int fx = find(u), fy = find(v);
      if (sz[fx] > sz[fy]) swap(fx, fy);
      if (fx != fy) p[fx] = fy, res += w, sz[fy] += sz[fx]; 
    }
    maxn = min(maxn, res);
  } 
  _for(cas, 0, (1 << k) - 1) {
    int idx = n, res = 0; tot2 = 0;
    if (__builtin_popcount(cas) > 2) continue;
    _for(i, 0, k - 1) {
      if (cas >> i & 1) {
        idx++; res += val[i + 1];
        _for(j, 1, n) ed2[++tot2] = {idx, j, a[i + 1][j]};
      }
    } 
    sort(ed2 + 1, ed2 + tot2 + 1, [](edge x, edge y) {
      return x.w < y.w; 
    });
    tot3 = 0;
    int l = 1, r = 1;
    while (l <= tot && r <= tot2) {
      if (ed[l].w < ed2[r].w) ed3[++tot3] = ed[l], l++;
      else ed3[++tot3] = ed2[r], r++;
    }
    while (l <= tot) ed3[++tot3] = ed[l], l++;
    while (r <= tot2) ed3[++tot3] = ed2[r], r++; 
    _for(i, 1, idx) p[i] = i, sz[i] = 1;
    _for(i, 1, tot3) {
      int u = ed3[i].u, v = ed3[i].v, w = ed3[i].w;
      int fx = find(u), fy = find(v);
      if (sz[fx] > sz[fy]) swap(fx, fy);
      if (fx != fy) p[fx] = fy, res += w, sz[fy] += sz[fx]; 
    }
    maxn = min(maxn, res);
  } 
  cout << maxn << endl;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/
