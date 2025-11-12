#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define cfor(i, a, b) for (int i = a; i <= b; i++)
#define ofor(i, a, b) for (int i = a; i < b; i++)
#define bfor(i, a, b) for (int i = a; i >= b; i--)
#define mset(a, x) memset(a, x, sizeof(a))
const int X = 1e2 + 5;
const int inf = 0x3f3f3f3f;

int n, m;
bool ac[X];
int a[X];
int p[X];
ll ans;

int main() {
  freopen("employ.in", "r", stdin);
  freopen("employ.out", "w", stdout);
  ios::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n >> m;
  cfor (i, 1, n) {
    char x;
    cin >> x;
    if (x == '1') ac[i] = true;
  }
  cfor (i, 1, n) cin >> a[i];
  cfor (i, 1, n) p[i] = i;
  do {
    int cnt_fail = 0;
    cfor (i, 1, n)
      if ((not ac[i]) or cnt_fail >= a[p[i]])
        cnt_fail++;
    if (n - cnt_fail >= m) ans++;
  } while (next_permutation(p + 1, p + n + 1));
  cout << ans;
  return 0;
}