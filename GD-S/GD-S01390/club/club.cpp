#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define cfor(i, a, b) for (int i = a; i <= b; i++)
#define ofor(i, a, b) for (int i = a; i < b; i++)
#define bfor(i, a, b) for (int i = a; i >= b; i--)
#define mset(a, x) memset(a, x, sizeof(a))
const int X = 1e5 + 5;
const int inf = 0x3f3f3f3f;

int T, n, ans;
vector<int> a[3];
int cnt[3];

void init() {
  ans = 0;
  mset(cnt, 0);
  cfor (i, 0, 2) a[i].clear();
  return;
}

int main() {
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);
  ios::sync_with_stdio(false); cin.tie(nullptr);
  cin >> T;
  while (T--) {
    init();
    cin >> n;
    cfor (i, 1, n) {
      vector<pair<int, int>> cand;
      cfor (j, 0, 2) {
        int val;
        cin >> val;
        cand.push_back({val, j});
      }
      sort(cand.begin(), cand.end());
      ans += cand[2].first;
      a[cand[2].second].push_back({cand[2].first - cand[1].first});
      cnt[cand[2].second]++;
    }
    int K = -1;
    cfor (i, 0, 2)
      if (a[i].size() > n / 2)
        K = i;
    if (K != -1) {
      sort(a[K].begin(), a[K].end());
      ofor (i, 0, a[K].size() - n / 2)
        ans -= a[K][i];
    }
    cout << ans << "\n";
  }
  return 0;
}