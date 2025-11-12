#include<bits/stdc++.h>
using ll = long long;
using namespace std;
ll n, m, k, ans = 0, Final = 1e16;
ll c[12];
int Fa[10055], Siz[10055], Z;
struct node {
  int u, v;
  ll w;
  bool operator < (const node a) const {
    return w < a.w;
  }
}nd[1000005], M[20005];
vector<node> G[12], T, Ar, Al;
void Reset(int S) {
  Z = S;
  ans = 0;
  for(int i = 0; i <= S; ++i) Fa[i] = i, Siz[i] = 1;
}
int Find(int x) {
  return (Fa[x] == x ? x : Fa[x] = Find(Fa[x]));
}
void Merge(int x, int y, ll z, bool op) {
  int xx = Find(x), yy = Find(y);
  if(xx == yy) return;
  ans += z;
  if(op) G[0].push_back({x, y, z});
  --Z;
  if(Siz[xx] > Siz[yy]) Fa[yy] = xx, Siz[xx] += Siz[yy];
  else Fa[xx] = yy, Siz[yy] += Siz[xx];
}
vector<node> Solve(vector<node> A, vector<node> B) {
  int j = 0;
  vector<node> Ans;
  for(auto x : A) {
    while(j < B.size() && B[j].w < x.w) {
      Ans.push_back(B[j]);
      ++j;
    }
    Ans.push_back(x);
  }
  while(j < B.size()) Ans.push_back(B[j]), ++j;
  return Ans;
}
int main() {
  // don't forget the erase the number!!!
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);
  scanf("%lld%lld%lld", &n, &m, &k);
  for(int i = 1; i <= m; ++i) {
    scanf("%d%d%lld", &nd[i].u, &nd[i].v, &nd[i].w);
  }
  sort(nd + 1, nd + m + 1);
  Reset(n);
  for(int i = 1; i <= m; ++i) {
    if(Z == 1) break;
    Merge(nd[i].u, nd[i].v, nd[i].w, 1);
  }
  for(int i = 1; i <= k; ++i) {
    scanf("%lld", &c[i]);
    for(int j = 1; j <= n; ++j) {
      scanf("%lld", &M[j].w);
      M[j].u = i + n, M[j].v = j;
    }
    sort(M + 1, M + n + 1);
    for(int j = 1; j <= n; ++j) G[i].push_back(M[j]);
  }
  for(int i = 1; i < (1 << k + 1); ++i) {
    if((i & 1) != 1) continue;
    Al.clear(), Ar.clear(), T.clear();
    Reset(n + k);
    vector<int> Check;
    for(int j = 0; j <= k; ++j)
      if((i >> j) & 1) Check.push_back(j), ans += c[j];
    int x = Check.size();
    if(x == 1) {
      T = G[Check[0]];
    } if(x == 2 || x == 3) {
      T = Solve(G[Check[0]], G[Check[1]]);
    } if(x == 3) {
      T = Solve(T, G[Check[2]]);
    } if(x >= 4 && x <= 11) {
      Ar = Solve(G[Check[0]], G[Check[1]]);
      Al = Solve(G[Check[2]], G[Check[3]]);
      T = Solve(Ar, Al);
    } if(x == 5 || x == 10) {
      T = Solve(T, G[Check[4]]);
    } if(x == 6 || x == 11) {
      Al = Solve(G[Check[4]], G[Check[5]]);
      T = Solve(Al, T);
    } if(x == 7) {
      Ar = Solve(G[Check[4]], G[Check[5]]);
      Ar = Solve(Ar, G[Check[6]]);
      T = Solve(T, Ar);
    } if(x == 8) {
      Ar = Solve(G[Check[4]], G[Check[5]]);
      Al = Solve(G[Check[6]], G[Check[7]]);
      Ar = Solve(Ar, Al);
      T = Solve(T, Ar);
    } if(x == 9) {
      Ar = Solve(G[Check[4]], G[Check[5]]);
      Al = Solve(G[Check[6]], G[Check[7]]);
      Al = Solve(Al, G[Check[8]]);
      Al = Solve(Al, Ar);
      T = Solve(T, Al);
    } if(x == 10) {
      Ar = Solve(G[Check[5]], G[Check[6]]);
      Al = Solve(G[Check[7]], G[Check[8]]);
      Al = Solve(Al, G[Check[9]]);
      Al = Solve(Al, Ar);
      T = Solve(T, Al);
    } if(x == 11) {
      Ar = Solve(G[Check[6]], G[Check[7]]);
      Al = Solve(G[Check[8]], G[Check[9]]);
      Al = Solve(Al, G[Check[10]]);
      Al = Solve(Al, Ar);
      T = Solve(T, Al);
    }
    for(auto x : T) {
      if(Z == 1) break;
      Merge(x.u, x.v, x.w, 0);
    }
    Final = min(Final, ans);
  }
  printf("%lld", Final);
  return 0;
}
