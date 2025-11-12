// mouse_boy 2025.11 CSP
#include<bits/stdc++.h>
#define ll long long

using namespace std;

ifstream fin("employ.in");
ofstream fout("employ.out");

const int kMaxN = 505, mod = 998244353;
ll a[kMaxN], b[kMaxN], n, m, ans;
string s;
bool vis[kMaxN];

bool check(ll cnt = 0, ll sum = 0) {
  for(int i = 1; i <= n; i++) {
    if(cnt >= a[b[i]] || s[i] == '0') cnt++;
    else sum++;
  }
  return sum >= m;
}

void dfs(ll x) {
  if(x == n + 1) ans = (ans + check()) % mod;
  for(int i = 1; i <= n; i++) {
    if(!vis[i]) {
      vis[i] = 1, b[x] = i, dfs(x + 1), vis[i] = 0;
    }
  }
}

int main() {
  ios::sync_with_stdio(0), fin.tie(0);
  fin >> n >> m >> s, s = " " + s;
  for(int i = 1; i <= n; i++) {
    fin >> a[i];
  }
  if(n == m) {
    for(int i = 1; i <= n; i++) {
      if(s[i] == '0') {
        return fout << "0\n", 0;
      }
    }
  }
  if(n <= 10) {
    dfs(1);
    fout << ans << '\n';
  } else {
    ans = 1;
    ll cnt = 0;
    for(int i = 1; i <= n; i++) {
      if(a[i] == 0) {
        cnt++;
      }
    }
    if(n - cnt < m) return fout << "0\n", 0;
    for(int i = 1; i <= n; i++) {
      ans = ans * i % mod;
    } 
    fout << ans << '\n';
  }
  return 0;
}
/*

cd /home/noilinux/HN-S00235/employ && ulimit -s 102400 && g++ employ.cpp -o employ -O2 -Wall && time ./employ && size ./employ && ./employ && diff employ.out ans.out -Bb

*/
