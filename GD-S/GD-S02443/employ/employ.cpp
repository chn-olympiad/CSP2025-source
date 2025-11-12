#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e3 + 10;
const int MOD = 998244353;
ll n, m;
string s;
ll c[N], jc[N];
vector<ll> zero;
bool hv1, hv0;

int main() {
  freopen("employ.in", "r", stdin);
  freopen("employ.out", "w", stdout);
  cin >> n >> m;
  cin >> s;
  jc[0] = 1;
  for (ll i = 1; i <= n; i++) jc[i] = jc[i - 1] * i % MOD;
  for (ll i = 0; i < s.size(); i++) {
    if (s[i] == '1')
      hv1 = 1;
    else
      hv0 = 1;
  }
  for (ll i = 1; i <= n; i++) {
    cin >> c[i];
    if (c[i] == 0) zero.push_back(i);
  }
  if (m == 1) {
    if (hv1)
      cout << jc[n];
    else
      cout << 0;
  } else if (!hv0) {
    if (n - zero.size() >= m)
      cout << jc[n];
    else
      cout << 0;
  }
  return 0;
}