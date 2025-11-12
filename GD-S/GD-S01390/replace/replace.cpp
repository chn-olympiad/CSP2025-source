#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define cfor(i, a, b) for (int i = a; i <= b; i++)
#define ofor(i, a, b) for (int i = a; i < b; i++)
#define bfor(i, a, b) for (int i = a; i >= b; i--)
#define mset(a, x) memset(a, x, sizeof(a))
const int X = 1e5 + 5;
const int inf = 0x3f3f3f3f;

struct my_hash {
  int operator()(const pair<string, string> &x) const {
    return hash<string>()(x.first) ^ hash<string>()(x.second);
  }
};

int n, Q;
unordered_map<pair<string, string>, vector<pair<string, string>>, my_hash> mp;

string d1, d2, pre, suf;
bool solve(string s1, string s2) {
  int len = s1.size();
  int l = len, r = -1;
  ofor (i, 0, len) {
    if (s1[i] == s2[i]) continue;
    l = min(l, i);
    r = max(r, i);
  }
  if (l > r) return false;
  d1 = s1.substr(l, r - l + 1), d2 = s2.substr(l, r - l + 1);
  pre = s1.substr(0, l), suf = s1.substr(r + 1, len - r - 1);
  return true;
}

bool is_suf(string s1, string s2) {
  if (s1.length() > s2.length()) return false;
  return s1 == s2.substr(s2.size() - s1.size(), s1.size());
}

bool is_pre(string s1, string s2) {
  if (s1.length() > s2.length()) return false;
  return s1 == s2.substr(0, s1.size());
}

int main() {
  freopen("replace.in", "r", stdin);
  freopen("replace.out", "w", stdout);
  ios::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n >> Q;
  cfor (i, 1, n) {
    string s1, s2;
    cin >> s1 >> s2;
    if (not solve(s1, s2)) continue;
    mp[{d1, d2}].push_back({pre, suf});
  }
  while (Q--) {
    string s1, s2;
    cin >> s1 >> s2;
    solve(s1, s2);
    int ans = 0;
    if (mp.count({d1, d2}) == 0) {
      cout << "0\n";
      continue;
    } 
    for (auto p: mp[{d1, d2}])
      if (is_suf(p.first, pre) and is_pre(p.second, suf))
        ans++; 
    cout << ans << "\n";
  }
  return 0;
}