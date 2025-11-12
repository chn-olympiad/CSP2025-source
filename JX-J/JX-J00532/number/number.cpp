#include<bits/stdc++.h>
using namespace std;
// please the person who read my code follow luogu uid:103390

// I forgot to write something about this contest
// I finally passed four problems and accepted the pretest
// It's my last time for CSP-J
// Because of my silly mistake, I missed it twice
// But now, I can say I got it!
// with the time 1 hour and 20 minutes, I think I am full scores
// I think it will be the easiest one for CSP-J
// It's a really amazing day!

int mp[10];

void solve() {
  string s; cin >> s;
  int n = s.length(); s = ' ' + s;
  for(int i = 1; i <= n; i++) {
    if(isdigit(s[i])) mp[s[i] - '0']++;
  }
  for(int i = 9; i >= 0; i--) {
    for(int j = 1; j <= mp[i]; j++) cout << i;
  }
  cout << '\n';
}

int main() {
  freopen("number.in", "r", stdin);
  freopen("number.out", "w", stdout);
  ios::sync_with_stdio(false);
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int t = 1;
  // cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}