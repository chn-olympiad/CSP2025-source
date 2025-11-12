#include <bits/stdc++.h>

using namespace std;
using LL = long long;
using i128 = __int128_t;

const i128 mod = 1e18 + 3, B = 1123;
const int MAXN = 2e5 + 3, MAXL = 6e6 + 3;

int n, Q;
map<LL, int> mp, _mp[MAXN];
int ls = 0, root[MAXN], tot = 0, eg[MAXL][26], sum[MAXL];
i128 Hash[MAXL], Bp[MAXL];

void Insert(i128 hs, string t){
  if(mp.find(hs) == mp.end()) mp[hs] = ls, ls++;
  int p = root[mp[hs]];
  for(int i = 0; i < t.size(); i++){
    int col = t[i] - 'a';
    if(!eg[p][col]) eg[p][col] = ++tot;
    p = eg[p][col];
  }
  sum[p]++;
}

void dfs(int rt, int x, i128 hs){
  _mp[rt][hs] = sum[x];
  for(int j = 0; j < 26; j++){
    if(eg[x][j]){
      sum[eg[x][j]] += sum[x], dfs(rt, eg[x][j], (hs * B % mod + j + 1) % mod);
    }
  }
}

i128 Get(int l, int r){
  if(l > r) return 0;
  if(l == 0) return Hash[r];
  return (Hash[r] - Hash[l - 1] * Bp[r - l + 1] % mod + mod) % mod;
}

// g++ replace.cpp -o replace -std=c++14 -O2 -g -Wall -Wextra -fsanitize=address,undefined && time ./replace
int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  freopen("replace.in", "r", stdin);
  freopen("replace.out", "w", stdout);
  cin >> n >> Q;
  for(int i = 0; i <= n; i++) root[i] = ++tot;
  for(int i = 1; i <= n; i++){
    string s, _s, t = "";
    cin >> s >> _s;
    int pos = -1;
    for(int j = 0; j < s.size(); j++) if(s[j] != _s[j]) pos = j;
    if(pos == -1){
      Insert(0, s);
    }else{
      i128 hs = 0;
      for(int j = pos; j >= 0; j--){
        hs = (hs * B % mod + s[j] - 'a' + 1) % mod;
        hs = (hs * B % mod + _s[j] - 'a' + 1) % mod;
      }
      for(int j = pos + 1; j < s.size(); j++) t.push_back(s[j]);
      Insert(hs, t);
    }
  }
  for(int id = 0; id < ls; id++){
    int p = root[id];
    dfs(id, p, 0);
  }
  Bp[0] = 1;
  for(int i = 1; i <= 5e6; i++) Bp[i] = Bp[i - 1] * B % mod;
  int qid = 0;
  while(Q--){
    qid++;
    string s, _s;
    cin >> s >> _s;
    int pos = -1;
    LL ANS = 0;
    for(int j = 0; j < s.size(); j++) if(s[j] != _s[j]) pos = j;
    if(pos == -1){
      Hash[0] = s[0] - 'a' + 1;
      for(int j = 1; j < s.size(); j++) Hash[j] = (Hash[j - 1] * B % mod + s[j] - 'a' + 1) % mod;
      for(int j = 0; j < s.size(); j++){
        if(mp.find(0) == mp.end()) continue;
        int id = mp[0];
        int l = 1, r = s.size() - j;
        while(l < r){
          int mid = (l + r + 1) >> 1;
          if(_mp[id].find(Get(j, j + mid - 1)) != _mp[id].end()){
            l = mid;
          }else r = mid - 1;
        }
        i128 w = Get(j, j + l - 1);
        if(_mp[id].find(w) != _mp[id].end()){
          ANS += _mp[id][w];
        }
      }
    }else{
      Hash[pos] = 0;
      for(int j = pos + 1; j < s.size(); j++) Hash[j] = (Hash[j - 1] * B % mod + s[j] - 'a' + 1) % mod;
      i128 hs = 0;
      int _pos = 0;
      for(int j = s.size() - 1; j >= 0; j--) if(s[j] != _s[j]) _pos = j;
      for(int j = pos; j >= 0; j--){
        hs = (hs * B % mod + s[j] - 'a' + 1) % mod;
        hs = (hs * B % mod + _s[j] - 'a' + 1) % mod;
        if(j > _pos) continue;
        if(mp.find(hs) != mp.end()){
          int id = mp[hs];
          int l = 0, r = s.size() - (pos + 1);
          while(l < r){
            int mid = (l + r + 1) >> 1;
            if(_mp[id].find(Get(pos+1, pos+1 + mid - 1)) != _mp[id].end()){
              l = mid;
            }else r = mid - 1;
          }
          LL w = Get(pos+1, pos+1 + l - 1);
          if(_mp[id].find(w) != _mp[id].end()){
            ANS += _mp[id][w];
          }
        }
      }
    }
    cout << ANS << "\n";
  }
  return 0;
}