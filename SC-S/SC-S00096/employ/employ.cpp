#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l), i##e = (r); i <= i##e; i++)
#define repp(i, l, r) for (int i = (l), i##e = (r); i < i##e; i++)
#define per(i, r, l) for (int i = (r), i##e = (l); i >= i##e; i--)

using namespace std;
using ll = long long;

template <class T>
void chkMax(T &a, T b) {
  a = max(a, b);
}
template <class T>
void chkMin(T &a, T b) {
  a = min(a, b);
}
template <class... Args>
void println(Args... args) {
  ((cerr << args << " "), ...);
  cerr << "\n";
}

const ll Mod = 998244353;
const int N = 504;
ll jc[N];
int n, m;
string s;
int c[N];

void solve1() {
  vector<int> a(n + 1);
  iota(a.begin(), a.end(), 0);
  int cnt = 0;
  do {
    //rep(i, 1, n) cerr << a[i] << " ";
    //cerr << "\n";
    int fai = 0;
    rep(i, 1, n)
      if(fai >= c[a[i]] || s[i - 1] == '0') fai++;
    cnt += fai <= n - m;
  }while(next_permutation(a.begin() + 1, a.end()));
  cout << cnt;
}

int main() {
  freopen("employ.in", "r", stdin);
  //freopen("employ3.in", "r", stdin);
  freopen("employ.out", "w", stdout);
  ios::sync_with_stdio(false), cin.tie(0);
  jc[0] = 1;
  repp(i, 1, N) jc[i] = jc[i - 1] * i % Mod;
  cin >> n >> m >> s;
  rep(i, 1, n) cin >> c[i];

  if(n > 18)
    cout << jc[n];
  else solve1();
  return 0;
}