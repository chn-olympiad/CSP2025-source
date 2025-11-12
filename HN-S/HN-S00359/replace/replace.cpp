#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

const int MAXL = 5000005, B = 31, MOD = int(1e9) + 7;

int n, q, pre[MAXL], pre2[MAXL], P[MAXL];
map<pii, int> mp;
bool subB = 1;

bool checkspecial(const string &s) {
  int cnt = 0;
  for(char c : s) {
    if(c != 'a' && c != 'b') {
      return 0;
    }
    cnt += (c == 'b');
  }
  return cnt == 1;
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  freopen("replace.in", "r", stdin);
  freopen("replace.out", "w", stdout);
  P[0] = 1;
  for(int i = 1; i < MAXL; ++i) {
    P[i] = 1ll * P[i - 1] * B % MOD;
  }
  cin >> n >> q;
  for(int i = 1; i <= n; ++i) {
    string s1, s2;
    cin >> s1 >> s2;
    int sum1 = 0, sum2 = 0;
    for(char c : s1) {
      sum1 = (1ll * B * sum1 + c - 'a' + 1) % MOD;
    }
    for(char c : s2) {
      sum2 = (1ll * B * sum2 + c - 'a' + 1) % MOD;
    }
    mp[{sum1, sum2}]++;
    subB &= (checkspecial(s1) & checkspecial(s2));
  }
  for(int _ = 1; _ <= q; ++_) {
    string t1, t2;
    cin >> t1 >> t2;
    int m = t1.size();
    t1 = " " + t1, t2 = " " + t2;
    int f = 0, e;
    for(int i = 1; i <= m; ++i) {
      pre[i] = (1ll * pre[i - 1] * B + t1[i] - 'a' + 1) % MOD;
      pre2[i] = (1ll * pre2[i - 1] * B + t2[i] - 'a' + 1) % MOD;
      if(!f && t1[i] != t2[i]) {
        f = i;
      }
      if(t1[i] != t2[i]) {
        e = i;
      }
    }
    int ans = 0;
    for(int i = 1; i <= f; ++i) {
      for(int j = e; j <= m; ++j) {
        ans += mp[{(pre[j] - 1ll * P[j - i + 1] * pre[i - 1] % MOD + MOD) % MOD, (pre2[j] - 1ll * P[j - i + 1] * pre2[i - 1] % MOD + MOD) % MOD}];
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
