#include<bits/stdc++.h>
using namespace std;
const int N = 20;

int a[N][N];
pair<int, int> rev[N * N];
int p[N * N], b[N * N];

void solve() {
  int n, m; cin >> n >> m;
  int num = 0;
  for(int i = 1; i <= m; i++) {
    if(i & 1) 
      for(int j = 1; j <= n; j++) a[j][i] = ++num;
    else
      for(int j = n; j >= 1; j--) a[j][i] = ++num;
  }
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++)
      rev[a[i][j]] = {i, j};
  for(int i = 1; i <= n * m; i++)
    cin >> b[i], p[i] = i;
  sort(p + 1, p + 1 + n * m, [&](int x, int y) { return b[x] > b[y]; });
  for(int i = 1; i <= n * m; i++) {
    if(p[i] == 1) {
      cout << rev[i].second << ' ' << rev[i].first << '\n';
    }
  }
}

int main() {
  freopen("seat.in", "r", stdin);
  freopen("seat.out", "w", stdout);
  ios::sync_with_stdio(false);
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int t = 1;
  // cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}