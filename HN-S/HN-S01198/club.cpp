#include<bits/stdc++.h>

using namespace std;
const int MAXN = 1e5 + 5;
int n, dp[2][MAXN][4];
struct Node{
  int a[4];
}a[MAXN];
struct bNode{
  int x[4], sum;
  bool operator<(const bNode &i)const{
    return sum > i.sum;
  }
};

bool checkai2andai3iszero(){
  for (int i = 1; i <= n; i++){
    if (a[i].a[2] + a[i].a[3]){
      return 0;
    }
  }
  return 1;
}

void Solve(){
  cin >> n;
  for (int i = 1; i <= n; i++){
    cin >> a[i].a[1] >> a[i].a[2] >> a[i].a[3]; 
  }
  if (checkai2andai3iszero()){
    vector<int> b;
    for (int i = 1; i <= n; i++){
      b.push_back(a[i].a[1]);
    }
    sort(b.begin(), b.end());
    int ans = 0;
    for (int i = 0; i < n / 2; i++){
      ans += b[i];
    }
    cout << ans << '\n';
    return ;
  } 
  vector<bNode> p, q;
  p.push_back({{0, 0, 0, 0}, 0});
  for (int i = 1; i <= n; i++){
    int cnt = 0;
    sort(p.begin(), p.end());
    for (auto v : p){
      cnt++;
      if (cnt >= 60000){
        break;
      }
//      cerr << i << ' ' << v.x[1] << ' ' << v.x[2] << ' ' << v.x[3] << ' ' << v.sum << '\n';
      for (int k = 1; k <= 3; k++){
        if (v.x[k] < n / 2){
          v.x[k]++;
          v.sum += a[i].a[k];
          q.push_back(v);
          v.x[k]--, v.sum -= a[i].a[k];
        }
      }
    }
//    cerr << "\n\n";
    swap(p, q);
    vector<bNode> ().swap(q);
//    cerr << p.size() << '\n';
  }
  int ans = 0;
  for (auto v : p){
    ans = max(ans, v.sum);
//    cerr << v.x[1] << ' ' << v.x[2] << ' ' << v.x[3] << ' ' << v.sum << '\n';
  }
  cout << ans << '\n';
}
signed main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  #ifndef QWQ
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);
  #endif
  int t = 1;
  cin >> t;
  while (t--){
    Solve();
  }
  return 0;
}
/*
1
4
4 2 1
3 2 4
5 3 4
3 5 1
*/

/*
本题预计得分：[25,45] 
*/


/*
也是开始写小作文了。 

今年也是被第一题创s了

应该也是最后一次参加 CSP-S 了吧

应该今年打完 NOIP 后一切就都结束了

再见，OI

再不见，OI

这无比珍视过的一切。

洛谷 UID752485 天边的生活/tbdsh

到，天边去生活？ 
*/
