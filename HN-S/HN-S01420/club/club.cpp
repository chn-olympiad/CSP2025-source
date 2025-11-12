#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll kM = 2e5 + 5;
ll q, n, a[kM][5], cnt[5], ans, p[kM], tot;
int main(){
  ios::sync_with_stdio(0), cin.tie(0),cout.tie(0);
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);
  cin >> q;
  while(q--){
    cin >> n;
    cnt[1] = cnt[2] = cnt[3] = ans = tot = 0;
    for(ll i = 1; i <= n; i++){
      cin >> a[i][1] >> a[i][2] >> a[i][3];
      ll ma = max({a[i][1],a[i][2],a[i][3]});
      ans += ma;
      if(a[i][1] == ma) cnt[1]++;
      else if(a[i][2] == ma) cnt[2]++;
      else cnt[3]++;
    }
    if(max({cnt[1], cnt[2], cnt[3]}) <= n / 2){
      cout << ans << "\n";
      continue;
    }
    for(ll i = 1; i <= n; i++){
      ll ma = max({a[i][1],a[i][2],a[i][3]});
      if(a[i][1] == ma && cnt[1] > n / 2) p[++tot] = ma - max(a[i][2], a[i][3]);
      else if(a[i][2] == ma && cnt[2] > n / 2) p[++tot] = ma - max(a[i][1], a[i][3]);
      else if(a[i][3] == ma && cnt[3] > n / 2) p[++tot] = ma - max(a[i][2], a[i][1]);
    }
    sort(p + 1, p + 1 + tot);
    for(ll i = 1; i + (n / 2) <= tot; i++){
      ans -= p[i];
    }
    cout << ans << "\n";
  }
  return 0;
}