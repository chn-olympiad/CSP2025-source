#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define cfor(i, a, b) for (int i = a; i <= b; i++)
#define ofor(i, a, b) for (int i = a; i < b; i++)
#define bfor(i, a, b) for (int i = a; i >= b; i--)
#define mset(a, x) memset(a, x, sizeof(a))
const int X = 1e6 + 5;
const int inf = 0x3f3f3f3f;

string s;
int cnt[15];

int main() {
  freopen("number.in", "r", stdin);
  freopen("number.out", "w", stdout);
  ios::sync_with_stdio(false); cin.tie(nullptr);
  cin >> s;
  for (char x: s)
    if (x >= '0' and x <= '9')
      cnt[x - '0']++;
  bfor (i, 9, 0)
    cfor (j, 1, cnt[i])
      cout << i;
  return 0;
}