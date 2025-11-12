#include<bits/stdc++.h>

using namespace std;

const int bna = 37;
const int mod = 1145141;

int n, q;
string s1, s2, t1, t2;
map<pair<long long, long long>, int> mp;

int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  freopen("replace.in", "r", stdin);
  freopen("replace.out", "w", stdout);
  cin >> n >> q;
  for(int i = 1; i <= n; i++){
    cin >> s1 >> s2;
    long long sum = 0, sum2 = 0;
    for(int j = 0; j < s1.size(); j++){
      sum = sum * bna + int(s1[j] - 'a' + 1);
      sum %= mod;
    }
    for(int j = 0; j < s2.size(); j++){
      sum2 = sum2 * bna + int(s2[j] - 'a' + 1);
      sum2 %= mod;
    }
    mp[{sum, sum2}]++;
  }
  int n1 = 0, n2 = 0;
  for(int i = 1; i <= q; i++){
    cin >> t1 >> t2;
    if(t1.size() != t2.size()){
      cout << 0 << '\n';
      continue;
    }
    n1 = t1.size(), n2 = t2.size();
    t1 = ' ' + t1, t2 = ' ' + t2;
    int l = 1;
    while(l <= n1 && t1[l] == t2[l]){
      l++;
    }
    l = min(l, n1);
    int r = n1;
    while(r && t1[r] == t2[r]){
      r--;
    }
    r = max(r, 1);
    long long ans = 0;
    for(int sl = 1; sl <= l; sl++){
      long long now = 0, now2 = 0;
      for(int j = sl; j < max(r, sl); j++){
        now = now * bna + int(t1[j] - 'a' + 1);
        now2 = now2 * bna + int(t2[j] - 'a' + 1);
        now %= mod, now2 %= mod;
      }
      for(int sr = max(r, sl); sr <= n1; sr++){
        now = now * bna + int(t1[sr] - 'a' + 1);
        now2 = now2 * bna + int(t2[sr] - 'a' + 1);
        now %= mod, now2 %= mod;
        if(mp.find({now, now2}) != mp.end()){
          ans += mp[{now, now2}];
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
