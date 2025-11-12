#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10, INF = 2e9;

int t, n, cnt[5], ans1, ans, a[MAXN][5];

struct E{
  int x, id;
  bool operator< (const E &i) const{
    return x > i.x;
  }
} cz[MAXN];

void S1(int id0, int id1, int id2){
  for(int i = 1; i <= n; i++){
    if(cnt[id0] == n / 2){
      if(a[cz[i].id][id2] >= a[cz[i].id][id1]){
        cnt[id2]++, ans1 += a[cz[i].id][id2];
      } else {
        cnt[id1]++, ans1 += a[cz[i].id][id1];
      }
    } else {
      if(cnt[id2] < n / 2 && a[cz[i].id][id2] >= a[cz[i].id][id0]){
        cnt[id2]++, ans1 += a[cz[i].id][id2];
      } else {
        cnt[id0]++, ans1 += a[cz[i].id][id0];
      }
    }
  }
}

void Solve(){
  cin >> n;

  for(int i = 1; i <= n; i++){
    cin >> a[i][0] >> a[i][1] >> a[i][2];
    cz[i] = {a[i][0] - a[i][1], i};
  }
  sort(cz + 1, cz + n + 1);
  S1(0, 1, 2);
  if(cnt[0] > n / 2 || cnt[1] > n / 2 || cnt[2] > n / 2) ans1 = -INF;
  ans = max(ans, ans1);

  cnt[0] = cnt[1] = cnt[2] = ans1 = 0;

  for(int i = 1; i <= n; i++){
    cz[i] = {a[i][0] - a[i][2], i};
  }
  sort(cz + 1, cz + n + 1);
  S1(0, 2, 1);
  if(cnt[0] > n / 2 || cnt[1] > n / 2 || cnt[2] > n / 2) ans1 = -INF;
  ans = max(ans, ans1);
  cnt[0] = cnt[1] = cnt[2] = ans1 = 0;



  for(int i = 1; i <= n; i++){
    cz[i] = {a[i][1] - a[i][0], i};
  }
  sort(cz + 1, cz + n + 1);
  S1(1, 0, 2);
  if(cnt[0] > n / 2 || cnt[1] > n / 2 || cnt[2] > n / 2) ans1 = -INF;
  ans = max(ans, ans1);
  cnt[0] = cnt[1] = cnt[2] = ans1 = 0;



  for(int i = 1; i <= n; i++){
    cz[i] = {a[i][1] - a[i][2], i};
  }
  sort(cz + 1, cz + n + 1);
  S1(1, 2, 0);
  if(cnt[0] > n / 2 || cnt[1] > n / 2 || cnt[2] > n / 2) ans1 = -INF;
  ans = max(ans, ans1);
  cnt[0] = cnt[1] = cnt[2] = ans1 = 0;



  for(int i = 1; i <= n; i++){
    cz[i] = {a[i][2] - a[i][0], i};
  }
  sort(cz + 1, cz + n + 1);
  S1(2, 0, 1);
  if(cnt[0] > n / 2 || cnt[1] > n / 2 || cnt[2] > n / 2) ans1 = -INF;
  ans = max(ans, ans1);
  cnt[0] = cnt[1] = cnt[2] = ans1 = 0;



  for(int i = 1; i <= n; i++){
    cz[i] = {a[i][2] - a[i][1], i};
  }
  sort(cz + 1, cz + n + 1);
  S1(2, 1, 0);
  if(cnt[0] > n / 2 || cnt[1] > n / 2 || cnt[2] > n / 2) ans1 = -INF;
  ans = max(ans, ans1);
  cnt[0] = cnt[1] = cnt[2] = ans1 = 0;

  for(int i = 1; i <= n; i++){
    if(a[i][0] >= a[i][1] && a[i][0] >= a[i][2]){
      cnt[0]++, ans1 += a[i][0];
    } else if(a[i][1] >= a[i][0] && a[i][1] >= a[i][2]){
      cnt[1]++, ans1 += a[i][1];
    } else {
      cnt[2]++, ans1 += a[i][2];
    }
  }
  if(cnt[0] > n / 2 || cnt[1] > n / 2 || cnt[2] > n / 2) ans1 = -INF;
  ans = max(ans, ans1);
  cnt[0] = cnt[1] = cnt[2] = ans1 = 0;

  cout << ans << '\n';
  ans = -INF;
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);
  cin >> t;
  while(t--){
    Solve();
  }
  return 0;
}
