#include <bits/stdc++.h>
#define fi first
#define se second
#define mkp(x, y) make_pair(x, y)
using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using ull = unsigned long long;

ifstream fin("replace.in");
ofstream fout("replace.out");

const int kB = 117, kMaxN = 2e5 + 5;

string s1[kMaxN], s2[kMaxN];
ull p[kMaxN];
int n, q;

ull Get_hash(string s) {
  ull ans = 0;
  for(int i : s) {
    ans = ans * kB + i;
  }
  return ans;
}

ull Get_hash_array(string s, ull h[]) {
  ull ans = 0;
  int tmp = s.size();
  s = 's' + s;
  for(int i = 1; i <= tmp; i++) {
    h[i] = h[i - 1] * kB + s[i];
  }
  return ans;
}

ull Sub(int lt, int rt, ull h[]) {
  return h[rt] - h[lt - 1] * p[rt - lt + 1];
}

namespace Solve1 {
  ull hs1[kMaxN], hs2[kMaxN], h1[kMaxN], h2[kMaxN];
  int l[kMaxN];
  void Solve1() {
    p[0] = 1;
    for(int i = 1; i <= 2e3; i++) {
      p[i] = p[i - 1] * kB;
    }
    for(int i = 1; i <= n; i++) {
      l[i] = s1[i].size();
      hs1[i] = Get_hash(s1[i]);
      hs2[i] = Get_hash(s2[i]);
    }
    for(string t1, t2; q--; ) {
      fin >> t1 >> t2;
      int len = t1.size();
      LL ans = 0;
      Get_hash_array(t1, h1), Get_hash_array(t2, h2);
      for(int i = 1; i <= len; i++) {
        for(int j = 1; j <= n; j++) {
          if(i >= l[j]) {
            ans += (Sub(i + 1, len, h1) == Sub(i + 1, len, h2) && Sub(1, i - l[j], h1) == Sub(1, i - l[j], h2) && Sub(i - l[j] + 1, i, h2) == hs2[j] && Sub(i - l[j] + 1, i, h1) == hs1[j]);
          }
        }
      }
      fout << ans << "\n";
    }
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  fin >> n >> q;
  int tot = 0;
  for(int i = 1; i <= n; i++) {
    fin >> s1[i] >> s2[i];
    tot += s1[i].size();
  }
  if(tot <= 2e3) {
    Solve1::Solve1();
  } else {
    for(int i = 1; i <= q; i++) {
      fout << "0\n";
    }
  }
  return 0;
}

