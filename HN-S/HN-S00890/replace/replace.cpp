#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;
const int mod = 534553;
const int base = 450479;

int n, q, tot, ans;
string s, t, s1[N], s2[N];
map<string, int> mp;
vector<int> e[N];

void dfs(string s) {
  if (s == t) {
    ans++;
    return;
  }
}

int main() {
  freopen("replace.in", "r", stdin);
  freopen("replace.out", "w", stdout);
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> s1[i] >> s2[i];
  }
  while (q--) {
    cin >> s >> t;
    cout << "0\n";
  }
  return 0;
}
