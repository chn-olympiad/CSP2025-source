#include<bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
const int M = 13;
const int K = 1e4 + 5;

struct Node{
  int u, v;
  long long w;
  bool operator < (const Node &b) const{
    return w < b.w;
  }
}rd[N], rd2[K], rd3[M * K], tmp[M * K];

long long now, ans = LLONG_MAX;
int n, m, k, t, tot, tsiz, cnt, f[M + K], siz[M + K], c[M], a[M][N];

int Find(int x){
  return f[x] = (f[x] == x ? x : Find(f[x]));
}

void mymerge(int u, int v, int w){
  u = Find(u), v = Find(v);
  if(u == v) return ;
  if(siz[u] > siz[v]) swap(u, v);
  f[u] = v, siz[v] += siz[u];
  now += w, cnt--;
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);
  cin >> n >> m >> k;
  for(int i = 1; i <= m; i++){
    cin >> rd[i].u >> rd[i].v >> rd[i].w;
  }
  for(int i = 1; i <= k; i++){
    cin >> c[i];
    for(int j = 1; j <= n; j++){
      cin >> a[i][j];
    }
  }
  iota(f + 1, f + n + 1, 1);
  sort(rd + 1, rd + m + 1);
  long long sum = 0;
  for(int i = 1; i <= m; i++){
    if(Find(rd[i].u) != Find(rd[i].v)){
      rd2[++tot] = rd[i];
      f[Find(rd[i].u)] = Find(rd[i].v);
      sum += rd2[tot].w;
    }
  }
  for(int i = 1; i <= k; i++){
    for(int j = 1; j <= n; j++){
      ++t;
      rd3[t].u = i;
      rd3[t].v = j;
      rd3[t].w = a[i][j];
    }
  }
  sort(rd3 + 1, rd3 + t + 1);
  for(int i = 0; i < (1 << k); i++){
    for(int j = 1; j <= n + k; j++){
      f[j] = j, siz[j] = 1;
    }
    now = 0;
    cnt = n;
    for(int j = 1; j <= k; j++){
      if((i >> (j - 1)) & 1){
        now += c[j];
        cnt++;
      }
    }
    tsiz = 0;
    for(int j = 1; j <= t; j++){
      int nw = rd3[j].u;
      if((i >> (nw - 1)) & 1){
        tmp[++tsiz] = {nw + n, rd3[j].v, rd3[j].w};
      }
    }
    int l = 1, r = 1;
    while(l <= tot && r <= tsiz){
      if(rd2[l].w < tmp[r].w){
        mymerge(rd2[l].u, rd2[l].v, rd2[l].w);
        l++;
      }
      else{
        mymerge(tmp[r].u, tmp[r].v, tmp[r].w);
        r++;
      }
    }
    for(; l <= tot; l++){
      mymerge(rd2[l].u, rd2[l].v, rd2[l].w);
    }
    for(; r <= tsiz; r++){
      mymerge(tmp[r].u, tmp[r].v, tmp[r].w);
    }
    if(cnt == 1){
      ans = min(ans, now);
    }
  }
  cout << ans;
  return 0;
}
