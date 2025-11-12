#include<bits/stdc++.h>
#define rep(i,l,r) for (int i = l; i <= r; i ++)
#define rrp(i,l,r) for (int i = l; i >= r; i --)
using namespace std;
typedef long long LL;
mt19937 rnd(random_device{}());

const int N = 5e5 + 5;

void fakemain() {

}

void file(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

signed main() {
  cin.tie(0)->ios::sync_with_stdio(0), cout.tie(0);
  file("task");
  int tc, T = 1;
  // cin >> tc >> T;
  while (T --) fakemain();
  cerr << 1. * clock() / CLOCKS_PER_SEC << "s\n";
}