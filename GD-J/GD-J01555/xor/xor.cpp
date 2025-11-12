#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define cfor(i, a, b) for (int i = a; i <= b; i++)
#define ofor(i, a, b) for (int i = a; i < b; i++)
#define bfor(i, a, b) for (int i = a; i >= b; i--)
#define mset(a, x) memset(a, x, sizeof(a))
const int X = (1 << 20) + 5;
const int inf = 0x3f3f3f3f;

int n, K, a[X], ans, last[X];

int main() {
  freopen("xor.in", "r", stdin);
  freopen("xor.out", "w", stdout);
  ios::sync_with_stdio(false); cin.tie(nullptr);
  mset(last, -1);
  cin >> n >> K;
  cfor (i, 1, n) cin >> a[i];
  int sum = 0, pos = 0;
  last[0] = 0;
  cfor (i, 1, n) {
    sum ^= a[i];
    if (last[sum ^ K] >= pos) {
      ans++;
      pos = i;
    }
    last[sum] = i;
  }
  cout << ans;
  return 0;
}