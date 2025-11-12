#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

int __T, n, a[MAXN][3], ans;
vector<int> ve[3];

void Solve() {
  cin >> n;
  ve[0].clear(), ve[1].clear(), ve[2].clear(), ans = 0;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i][0] >> a[i][1] >> a[i][2];
    int Max = max({a[i][0], a[i][1], a[i][2]});
    ans += Max;
    if(a[i][0] == Max) {
      ve[0].emplace_back(i);
    }else if(a[i][1] == Max) {
      ve[1].emplace_back(i);
    }else {
      ve[2].emplace_back(i);
    }
  }
  if(int(ve[0].size()) > n / 2) {
    vector<int> v;
    for(int x : ve[0]) {
      v.emplace_back(min(a[x][0] - a[x][1], a[x][0] - a[x][2]));
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < int(ve[0].size()) - n / 2; ++i) {
      ans -= v[i];
    }
  }else if(int(ve[1].size()) > n / 2) {
    vector<int> v;
    for(int x : ve[1]) {
      v.emplace_back(min(a[x][1] - a[x][0], a[x][1] - a[x][2]));
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < int(ve[1].size()) - n / 2; ++i) {
      ans -= v[i];
    }
  }else if(int(ve[2].size()) > n / 2) {
    vector<int> v;
    for(int x : ve[2]) {
      v.emplace_back(min(a[x][2] - a[x][0], a[x][2] - a[x][1]));
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < int(ve[2].size()) - n / 2; ++i) {
      ans -= v[i];
    }
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);
  for(cin >> __T; __T--; Solve()) {
  }
  return 0;
}
