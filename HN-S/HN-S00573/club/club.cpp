#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 5, INF = 1e9;

int n;

struct Node{
  int x, id;
  bool operator < (const Node &i) const{
    return x > i.x;
  }
}a[MAXN][3];

struct P{
  int x, p;
  bool op;
  bool operator < (const P &i) const{
    return x > i.x;
  }
};
priority_queue<P> pq[3];

void Solve(){
  cin >> n;
  int ans = 0;
  for(int i = 1; i <= n; i++){
    for(int j = 0; j < 3; j++){
      cin >> a[i][j].x;
      a[i][j].id = j;
    }
    sort(a[i], a[i] + 3);
    ans += a[i][0].x;
    pq[a[i][0].id].push({a[i][0].x - a[i][1].x, 0, i});
  }
  for(; max({pq[0].size(), pq[1].size(), pq[2].size()}) > n / 2; ){
    for(int i = 0; i < 3; i++){
      if(pq[i].size() > n / 2){
        P it = pq[i].top();
        pq[i].pop();
        ans -= it.x;
        if(it.op == 0) pq[a[it.p][1].id].push({a[it.p][1].x - a[it.p][2].x, 1, it.p});
      }
    }
  }
  cout << ans << '\n';
  for(int i = 0; i < 3; i++){
    for(; !pq[i].empty(); pq[i].pop());
  }
}

int main(){
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int T; for(cin >> T; T; Solve(), T--);
  return 0;
}
