#include<bits/stdc++.h>

using namespace std;
const int MAXN = 2e5 + 5;
int n, q;
struct Node{
  string a, b;
}a[MAXN];
bool check(string s, string t, int x){
  for (int i = x; i - x + 1 <= t.size(); i++){
    if (s[i] != t[i - x]){
      return 0;
    }
  }
  return 1;
}
string Find(string s, string t, int x){
  string p;
  for (int i = 0; i < x; i++){
    p.push_back(s[i]);
  }
  for (auto v : t){
    p.push_back(v);
  }
  for (int i = x + t.size(); i < s.size(); i++){
    p.push_back(s[i]);
  }
  return p;
}
void Solve(){
  string s, t;
  cin >> s >> t;
  int ans = 0;
  for (int i = 1; i <= n; i++){
    if (a[i].a.size() > s.size()){
      continue;
    }
    for (int j = 0; j + a[i].a.size() - 1 < s.size(); j++){
      if (check(s, a[i].a, j)){
//        cerr << i << ' ' << j << ' ' << Find(s, a[i].b, j) << ' ' << s << ' ' << a[i].b << '\n';
        ans += Find(s, a[i].b, j) == t;
      }
    }
  }
  cout << ans << '\n';
}
signed main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  #ifndef QWQ
  freopen("replace.in", "r", stdin);
  freopen("replace.out", "w", stdout);
  #endif
  cin >> n >> q;
  for (int i = 1; i <= n; i++){
    cin >> a[i].a >> a[i].b;
  }
  while (q--){
    Solve();
  }
  return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/

/*
第三题继续被创s

可能只有 10 分  
*/
