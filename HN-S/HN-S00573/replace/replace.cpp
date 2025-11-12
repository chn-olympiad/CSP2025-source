#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MAXN = 2e5 + 5, MOD = 1000000021, BASE = 64007;

int n, q;
string s[MAXN][2], t[MAXN][2];

namespace sub1{

const int MAXL = 2e3 + 5;

int h[2][MAXL], power[MAXL];
vector<pii> vec[MAXL];

bool Check(){
  int sum = 0;
  for(int i = 1; i <= q; i++){
    sum += t[i][0].size() + t[i][1].size();
  }
  return sum <= 2000;
}

void Solve(){
  for(int i = 1; i <= n; i++){
    int hx = 0, hy = 0;
    for(char ch : s[i][0]){
      hx = (1ll * hx * BASE + ch - 'a') % MOD;
    }
    for(char ch : s[i][1]){
      hy = (1ll * hy * BASE + ch - 'a') % MOD;
    }
    vec[s[i][0].size()].push_back({hx, hy});
  }
  power[0] = 1;
  for(int i = 1; i <= 2000; i++){
    power[i] = 1ll * power[i - 1] * BASE % MOD;
    sort(vec[i].begin(), vec[i].end());
  }
  for(int p = 1; p <= q; p++){
    if(t[p][0].size() != t[p][1].size()){
      cout << "0\n";
      continue;
    }
    int len = t[p][0].size();
    t[p][0] = "#" + t[p][0], t[p][1] = "#" + t[p][1];
    int lp = 1, rp = len;
    for(; t[p][0][lp] == t[p][1][lp]; lp++);
    for(; t[p][0][rp] == t[p][1][rp]; rp--);
    for(int op = 0; op < 2; op++){
      for(int i = 1; i <= len; i++){
        h[op][i] = (1ll * h[op][i - 1] * BASE + t[p][op][i] - 'a') % MOD;
      }
    }
    int ans = 0;
    for(int i = 1; i <= lp; i++){
      for(int j = rp; j <= len; j++){
        pii res;
        res.first = (h[0][j] - 1ll * h[0][i - 1] * power[j - i + 1] % MOD + MOD) % MOD;
        res.second = (h[1][j] - 1ll * h[1][i - 1] * power[j - i + 1] % MOD + MOD) % MOD;
        int l = lower_bound(vec[j - i + 1].begin(), vec[j - i + 1].end(), res) - vec[j - i + 1].begin();
        int r = upper_bound(vec[j - i + 1].begin(), vec[j - i + 1].end(), res) - vec[j - i + 1].begin();
        ans += r - l;
      }
    }
    cout << ans << '\n';
  }
}

}

namespace sub2{

const int MAXL = 5e6 + 5;

int h[2][MAXL], power[MAXL];
vector<pii> vec[MAXL];

void Solve(){
  for(int i = 1; i <= n; i++){
    int x = 0, y = 0;
    for(int j = 0; j < s[i][0].size(); j++){
      x = (1ll * x * BASE + s[i][0][j] - 'a') % MOD;
      y = (1ll * y * BASE + s[i][1][j] - 'a') % MOD;
      vec[j + 1].push_back({x, y});
    }
  }
  power[0] = 1;
  for(int i = 1; i <= 5000000; i++){
    power[i] = 1ll * power[i - 1] * BASE % MOD;
    sort(vec[i].begin(), vec[i].end());
  }
  for(int p = 1; p <= q; p++){
    if(t[p][0].size() != t[p][1].size()){
      cout << "0\n";
      continue;
    }
    int ans = 0;
    int len = t[p][0].size();
    t[p][0] = "#" + t[p][0], t[p][1] = "#" + t[p][1];
    int lp = 1, rp = len;
    for(; t[p][0][lp] == t[p][1][lp]; lp++);
    for(; t[p][0][rp] == t[p][1][rp]; rp--);
    for(int op = 0; op < 2; op++){
      for(int i = 1; i <= len; i++){
        h[op][i] = (1ll * h[op][i - 1] * BASE + t[p][op][i] - 'a') % MOD;
      }
    }
    for(int i = 1; i <= lp; i++){
      pii res;
      res.first = (h[0][rp] - 1ll * h[0][i - 1] * power[rp - i + 1] % MOD + MOD) % MOD;
      res.second = (h[1][rp] - 1ll * h[1][i - 1] * power[rp - i + 1] % MOD + MOD) % MOD;
      int l = lower_bound(vec[rp - i + 1].begin(), vec[rp - i + 1].end(), res) - vec[rp - i + 1].begin();
      int r = upper_bound(vec[rp - i + 1].begin(), vec[rp - i + 1].end(), res) - vec[rp - i + 1].begin();
      ans += r - l;
    }
    cout << ans << '\n';
  }
}

}

int main(){
  freopen("replace.in", "r", stdin);
  freopen("replace.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> q;
  for(int i = 1; i <= n; i++){
    cin >> s[i][0] >> s[i][1];
  }
  for(int i = 1; i <= q; i++){
    cin >> t[i][0] >> t[i][1];
  }
  if(sub1::Check()){
    sub1::Solve();
  }else{
    sub2::Solve();
  }
  return 0;
}
