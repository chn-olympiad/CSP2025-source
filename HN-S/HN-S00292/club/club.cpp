#include <bits/stdc++.h>
using namespace std;
void File(){
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);
}
#define int long long
const int kN = 1e5 + 7;
int n, ans, vis[kN], vis2[kN];
struct node{
  int b[3];
}a[kN];
struct node2{
  int v, op, id;
  bool friend operator < (node2 x, node2 y){
    return x.v < y.v;
  }
}b[kN * 3];
priority_queue<node2>que[3];
void solve(){
  cin >> n;
  for(int i = 0; i <= 2; i++) while(!que[i].empty()) que[i].pop();
  for(int i = 1; i <= n; i++){
    cin >> a[i].b[0] >> a[i].b[1] >> a[i].b[2];
  }
  ans = 0;
  for(int i = 1; i <= n; i++){
    int x = a[i].b[0], y = a[i].b[1], z = a[i].b[2];
    int op = 0;
    if(a[i].b[1] > a[i].b[op]) op = 1;
    if(a[i].b[2] > a[i].b[op]) op = 2;
    if(que[op].size() < n / 2){
      int mx = 0, mx2 = 0;          
      for(int j = 0; j <= 2; j++){
        if(j != op){
          if(a[i].b[j] > mx){
            mx = a[i].b[j], mx2 = j;
          }
        }
      }
      que[op].push({-a[i].b[op] + mx, mx2, i});
      ans += a[i].b[op];
    }
    else{
      int nv = que[op].top().v, nop = que[op].top().op, nid = que[op].top().id;
      int tmp = 0;
      for(int j = 0; j <= 2; j++){
        if(j != op) tmp = max(tmp, a[i].b[j]);
      }
      if(nv + a[i].b[op] > tmp){
        que[op].pop();
        ans += nv + a[i].b[op];
        int mx = 0, mx2 = 0;
        for(int j = 0; j <= 2; j++){
          if(j != op){
            if(a[i].b[j] > mx){
              mx = a[i].b[j], mx2 = j;
            }
          }
        }
        que[op].push({-a[i].b[op] + mx, mx2, i});
        que[nop].push({nv, nop, nid});
      }
      else{
        int mx = 0, mx2 = 0;
        for(int j = 0; j <= 2; j++){
          if(j != op){
            if(a[i].b[j] > mx){
              mx = a[i].b[j], mx2 = j;
            }
          }
        }
        que[mx2].push({mx, mx2, i});
        ans += mx;
      }
    }
  }
  cout << ans << '\n';
}
signed main(){
  File();
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int T = 1;
  cin >> T;
  while(T--) solve();
  return 0;
}