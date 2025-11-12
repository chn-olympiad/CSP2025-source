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
int n ,m ,k ,cnt ,answer ,fa[N] ,val[N] ,lt;
bool vis[N];
struct Point {
  int u ,v ,w ,val ,l;
  bool operator < (const Point &a) const {
    if(val * vis[l] + w != a.val * vis[a.l] + a.w)return val * vis[l] + w > a.val * vis[a.l] + a.w;
    else if(vis[l] == 1 && vis[a.l] != 1) return 0;
    else if(vis[l] != 1 && vis[a.l] == 1) return 1;
    else return val > a.val;
  }
}qy[N];
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
vector<int>vtf;
signed main() {
  freopen("road.in" ,"r" ,stdin);
  freopen("road.out" ,"w" ,stdout);
  n = read();
  m = read() ,k = read();
  for(int i = 1 ,u ,v ,w;i <= m;++ i) {
    u = read() ,v = read() ,w = read();
    qy[i] = Point {u ,v ,w ,0 ,0};
    que.push(i);
  }
  int t = m;
  for(int i = 1;i <= k;++ i) {
    vis[i] = 1;
    val[i] = read();
    for(int j = 1;j <= n;++ j) {
      qy[++ t] = Point{n + i ,j ,read() ,val[i] ,i};
      que.push(t);
    }
  }
  for(int i = 1;i <= n + k;++ i) fa[i] = i;
  for(int i = 1;i <= t;++ i) {
    int idt = que.top();
    que.pop();
    int t1 = find(qy[idt].u) ,tt = find(qy[idt].v);
    if(t1 == tt) continue;
    fa[t1] = tt;
    answer += qy[idt].val * vis[qy[idt].l] + qy[idt].w;
    if(t1 > n) {
      vis[qy[idt].l] = 0;
      ++ lt;
      if(lt == Leng) {
        lt = 0;
        while(!que.empty()) {
          vtf.push_back(que.top());
          que.pop();
        }
        for(auto it:vtf) que.push(it);
      }
    }
    else ++ cnt;
    if(cnt == n - 1) break;
  }
  cout << answer;
  return 0;
}