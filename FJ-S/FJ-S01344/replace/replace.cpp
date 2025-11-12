#include<bits/stdc++.h>
using ll = long long;
using namespace std;
ll mod1 = 1e9 + 9, mod2, base1 = 322777, base2;
string s, t;
int n, q;
ll Hash(string s, ll Base, ll Mod) {
  ll ans = 0, al = 1;
  for(int i = 0; i < s.size(); ++i) {
    (ans += (s[i] - 'a' + 1) * al % Mod) %= Mod;
    (al *= Base) %= Mod;
  }
  return ans;
}
struct node {
  ll a1, a2, b1, b2;
}nd[200005];
int main() {
  freopen("replace.in", "r", stdin);
  freopen("replace.out", "w", stdout);
  mt19937 my(time(0));
  mod2 = my() % (1000000000) + 11;
  base2 = my() % 322776 + 11;
  cin >> n >> q;
  for(int i = 1; i <= n; ++i) {
    cin >> s >> t;
    nd[i].a1 = Hash(s, base1, mod1);
    nd[i].a2 = Hash(s, base2, mod2);
    nd[i].b1 = Hash(t, base1, mod1);
    nd[i].b2 = Hash(t, base2, mod2);
  }
  while(q--) {
    cin >> s >> t;
    ll x1, x2, y1, y2;
    x1 = Hash(s, base1, mod1);
    x2 = Hash(s, base2, mod2);
    y1 = Hash(t, base1, mod1);
    y2 = Hash(t, base2, mod2); 
    cout << 0 << endl;
  }
  return 0;
}
