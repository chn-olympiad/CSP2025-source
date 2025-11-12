#include<bits/stdc++.h>
#define ll long long
#define rint register int
#define For(i,l,r) for(rint i=l;i<=r;++i)
#define FOR(i,r,l) for(rint i=r;i>=l;--i)
#define mod 99824353

using namespace std;

const int N = 2e6 + 10;

struct Node {
  int u, v, w;
} e[N];

int n, m, k, f[N], c[N], a[15][N];

bool b1 = 1;

bool cmp(Node x, Node y) {
  return x.w < y.w;
}

int find(int x) {
  return (x == f[x] ? x : f[x] = find(f[x]));
}

void solve1() {
  int tot = m;
  ll ans = 0;
  For(i,1,k) {
    For(j,1,n) e[++tot] = {n+i, j, a[i][j]};
  }
  sort(e + 1, e + tot + 1, cmp);
  For(i,1,m) {
    int fu = find(e[i].u), fv = find(e[i].v);
    if(fu != fv) {
      f[fu] = fv;
      ans += e[i].w;
    }
  }
  cout << ans << '\n';
  return ;
}

void solve2() {
  ll ans = 0;
  sort(e + 1, e + m + 1, cmp);
  For(i,1,m) {
    int fu = find(e[i].u), fv = find(e[i].v);
    if(fu != fv) {
      f[fu] = fv;
      ans += e[i].w;
    }
  }
  cout << ans << '\n';
  return ;
}

signed main() {
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n >> m >> k;
  For(i,1,10 * n) f[i] = i;
  For(i,1,m) {
    int u, v, w;
    cin >> u >> v >> w;
    e[i] = (Node){u, v, w};
  }
  For(i,1,k) {
    cin >> c[i];
    b1 &= (c[i] == 0);
    For(j,1,n) cin >> a[i][j];
  }
  if(b1) {
    solve1();
    return 0;
  } else if(k == 0) {
    solve2();
    return 0;
  } else {
    solve1();
    return 0;
  }
  return 0;
}
/*
我不会在给自己留遗憾了，就算失败也值得，因为这就是我独有的人生，风光而璀璨
*/