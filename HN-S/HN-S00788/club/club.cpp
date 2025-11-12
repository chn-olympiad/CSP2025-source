#include<bits/stdc++.h>
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
const int N = 1e5 + 5;
int n ,answer ,t ,f[205][205];
struct Point {
  int t[4];
  bool operator <(const Point &a) const {
    if(max(t[0] ,t[1]) != max(a.t[0] ,a.t[1])) return max(t[0] ,t[1]) > max(a.t[0] ,a.t[1]);
    if(min(t[0] ,t[1]) != min(a.t[0] ,a.t[1])) return min(t[0] ,t[1]) > min(a.t[0] ,a.t[1]);
    return t[2] < a.t[2];
  }
}a[N];
priority_queue<int>que;
void solve() {
  n = read();
  bool flag = 0 ,_flag = 0;
  for(int i = 1;i <= n;++ i) {
    a[i].t[0] = read();
    a[i].t[1] = read();
    a[i].t[2] = read();
    if(a[i].t[1] >= 1 || a[i].t[2] >= 1) flag = 1;
    if(a[i].t[2] >= 1) _flag = 1;
    que.push(a[i].t[0]);
  }
  if(!flag) {
    int answer = 0;
    for(int i = 1;i <= n / 2;++ i) {
      answer += que.top();
      que.pop();
    }
    cout << answer << '\n';
    return ;
  }
  if(!_flag) {
    memset(f ,0 ,sizeof f);
    answer = 0;
    for(int i = 1;i <= n;++ i) {
      for(int j = min(n / 2 ,i);j >= 0;-- j) {
        int k = i - j;
        int l = i - j - k;
        if(l > n / 2 || k > n / 2) continue;
        if(j >= 1) f[j][k] = max(f[j][k] ,f[j - 1][k] + a[i].t[0]);
        if(k >= 1) f[j][k] = max(f[j][k] ,f[j][k - 1] + a[i].t[1]);
        answer = max(answer ,f[j][k]);
      }
    }
    cout << answer << '\n';
    return ;
  }
  sort(a + 1 ,a + n + 1);
  memset(f ,0 ,sizeof f);
  answer = 0;
  for(int i = 1;i <= n;++ i) {
    for(int j = min(n / 2 ,i);j >= 0;-- j) {
      for(int k = min(n / 2 ,i - j);k >= 0;-- k) {
        int l = i - j - k;
        if(l > n / 2) continue;
        if(l >= 1) f[j][k] = max(f[j][k] ,f[j][k] + a[i].t[2]);
        if(j >= 1) f[j][k] = max(f[j][k] ,f[j - 1][k] + a[i].t[0]);
        if(k >= 1) f[j][k] = max(f[j][k] ,f[j][k - 1] + a[i].t[1]);
        answer = max(answer ,f[j][k]);
      }
    }
  }
  cout << answer << '\n';
  return ;
}
signed main() {
  freopen("club.in" ,"r" ,stdin);
  freopen("club.out" ,"w" ,stdout);
  t = read();
  while(t --) {solve();}
  return 0;
}
/*
    for(int j = min(n / 2 ,i);j >= 0;-- j) {
      int k = i - j;
      int l = i - j - k;
      if(j >= 1) f[j][k] = max(f[j][k] ,f[j - 1][k] + a[i][0]);
      if(k >= 1) f[j][k] = max(f[j][k] ,f[j][k - 1] + a[i][1]);
      answer = max(answer ,f[j][k]);
    }
*/