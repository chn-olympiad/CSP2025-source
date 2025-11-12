#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read() {
  int x = 0 ,f = 1;
  char ch = getchar();
  while('0' > ch || ch > '9') {
    if(ch == '-') f = -1;
    ch = getchar();
  }
  while('0' <= ch && ch <= '9') {
    x = (x << 3) + (x << 1) + (ch & 15);
    ch = getchar();
  }
  return x * f;
}
const int N = 2e6 + 5 ,Leng = 100;
int n ,m ,k ,cnt ,answer ,fa[N] ,val[N] ,lt ,anst;
bool vis[N];
struct Point {
  int u ,v ,w;
  bool operator < (const Point &a) const {
    return w < a.w;
  }
}qy[N] ,qt[N];
struct Cmp {
  bool operator ()(const int &a ,const int &b) const {
    return qy[a] < qy[b];
  }
};
priority_queue<int ,vector<int> ,Cmp> que;
int find(int a) {
  if(a == fa[a]) return a;
  return fa[a] = find(fa[a]);
}
vector<int>vt[N];
signed main() {
  freopen("road2.in" ,"r" ,stdin);
  freopen("road.out" ,"w" ,stdout);
  n = read() ,m = read() ,k = read();
  for(int i = 1 ,u ,v ,w;i <= m;++ i) {
    u = read() ,v = read() ,w = read();
    qy[i] = Point {u ,v ,w};
  }
  sort(qy + 1 ,qy + m + 1);
  for(int i = 1;i <= n;++ i) fa[i] = i;
  for(int i = 1;i <= m;++ i) {
    int t1 = find(qy[i].u) ,tt = find(qy[i].v);
    if(t1 == tt) continue;
    fa[t1] = tt;
    anst += qy[i].w;
    if(++ cnt == n - 1) break;
  }
  for(int i = 1;i <= k;++ i) {
    vis[i] = 1;
    vt[i].push_back(read());
    for(int j = 1;j <= n;++ j) {
      vt[i].push_back(read());
    }
  }
  for(int i = 1;i < (1 << k);++ i) {
    int res = 0 ,l = 0;
    int t = m;
    memcpy(qt ,qy ,sizeof qy);
    for(int j = 1;j <= k;++ j) {
      res += ((i & (1 << (j - 1))) != 0) * vt[j][0];
      if(((i & (1 << (j - 1))) != 0)) {
        ++ l;
        for(int k = 1;k <= n;++ k)
          qt[++ t] = Point{n + j ,k ,vt[j][k]};
      }
    }
    if(res >= anst) continue;
    sort(qt + 1 ,qt + t + 1);
    for(int i = 1;i <= n + k;++ i) fa[i] = i;
    answer = 0;cnt = 0;
    for(int i = 1;i <= t;++ i) {
      int t1 = find(qt[i].u) ,tt = find(qt[i].v);
      if(t1 == tt) continue;
      fa[t1] = tt;
      answer += qt[i].w;
      if(++ cnt == n + l - 1) break;
    }
    anst = min(answer + res ,anst);
  }
  cout << anst;
  return 0;
}