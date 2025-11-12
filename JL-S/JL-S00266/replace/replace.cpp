#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
// #define int LL
int n, q;
const int maxn = 2010;
typedef unsigned long long uLL;
const uLL B = 13331;
uLL pw[maxn];
pair<uLL, uLL>s[maxn]; 
#define x first
#define y second
uLL s1[maxn], s2[maxn];
inline uLL hv(uLL h[], int l, int r) {
  if(l > r) return 0; 
  return h[r] - h[l - 1] * pw[r - l + 1]; 
}
map<pair<uLL, uLL>, int>mp;
signed main() {
  freopen("replace.in", "r", stdin);
  freopen("replace.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n >> q;
  pw[0] = 1uLL;
  for(int i = 1; i < maxn; ++ i) pw[i] = pw[i - 1] * B; 
  for(int i = 1; i <= n; ++ i) {
    string s; cin >> s;
    uLL v1 = 0, v2 = 0; 
    for(auto c : s) v1 = v1 * B + c - 'a' + 1;
    cin >> s;
    for(auto c : s) v2 = v2 * B + c - 'a' + 1;  
    mp[make_pair(v1, v2)] ++ ;
  }
  for(int i = 1; i <= q; ++ i) {
    string str1, str2;
    cin >> str1 >> str2;
    uLL v2 = 0; 
    int m = str1.size(); 
    for(int i = 0; i < m; ++ i) s1[i + 1] = s1[i] * B + str1[i] - 'a' + 1;
    for(int i = 0; i < m; ++ i) s2[i + 1] = s2[i] * B + str2[i] - 'a' + 1;
    int ans = 0; 
    for(int l = 1; l <= m; ++ l)
      for(int r = l; r <= m; ++ r) {
        bool suc1 = 0, suc2 = 0;
        if(hv(s1, 1, l - 1) == hv(s2, 1, l - 1)) suc1 = 1;
        if(hv(s1, r + 1, n) == hv(s2, r + 1, n)) suc2 = 1;
        if(suc1 && suc2) {
          uLL v1 = hv(s1, l, r);
          uLL v2 = hv(s2, l, r);
          if(mp.count(make_pair(v1, v2))) ans += mp[make_pair(v1, v2)];
        }
      }
    cout << ans << '\n'; 
  }
  return 0; 
}