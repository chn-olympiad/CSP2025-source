#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct edge {
  int u, v, w;
};
  
int ec, pc, fa[10010];
edge edges[1000010], tmp[1000010];
  
int findfa(int x) {return fa[x] == x? x : (fa[x] = findfa(fa[x]));}
  
pair<ll, vector<edge> > span() {
  vector<edge> result;
  ll sw = 0;
  iota(fa + 1, fa + pc + 1, 1);
  copy(edges + 1, edges + ec + 1, tmp + 1);
  sort(tmp + 1, tmp + ec + 1, [](edge a, edge b) {return a.w < b.w;});
  for(int i = 1; i <= ec; i++) {
    if(findfa(tmp[i].u) != findfa(tmp[i].v)) {
      fa[findfa(tmp[i].u)] = tmp[i].v, sw += tmp[i].w, result.push_back(tmp[i]);
    }
  }
  return make_pair(sw, result);
}

int n, m, k, u, v, w, cst[11], arr[11][10010];
ll ans = LLONG_MAX;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);
  for(cin >> n >> m >> k; m--; ) {
    cin >> u >> v >> w;
    edges[++ec] = {u, v, w};
  }
  pc = n + k + 1;
  auto ttmp = span().second;
  copy(ttmp.begin(), ttmp.end(), edges + 1), ec = ttmp.size();
  for(int i = 0; i < k; i++) {
    cin >> cst[i];
    for(int j = 1; j <= n; j++) cin >> arr[i][j];
  }
  for(int i = 0; i < (1 << k); i++) {
    ll cc = 0;
    //*
    for(int j = 0; j < k; j++) {
      if((i >> j) & 1) {
        for(int x = 1; x <= n;  x++) edges[++ec] = {n + j + 1, x, arr[j][x]};
        cc += cst[j];
      }
    }
    //*/
    if(cc <= ans) ans = min(ans, cc + span().first);
    ec = n - 1;
  }
  cout << ans << '\n';
	return 0;
}
// ·ð×æ±£ÓÓ ²»Òª±¬Õ¨ 
