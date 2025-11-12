#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
void Add(int &x, ll y) { x = (x + y) % mod; }

const int kN = 505;
int n, m;
string s;
int pre[2][kN];

int dn[kN][kN], C[kN][kN];
int num[kN], npre[kN];
int f[2][kN][kN];
int ans[kN];

void Init(int N = kN - 2) {
  for(int i = 0; i <= N; i++) {
    dn[i][0] = 1;
    for(int j = 1; j <= N; j++) {
      dn[i][j] = (ll)dn[i][j - 1] * (i - j + 1) % mod;
    }
  }
  for(int i = 0; i <= N; i++) {
    C[i][0] = 1;
    for(int j = 1; j <= i; j++) {
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
    }
  }
}

int main() {
  freopen("employ.in", "r", stdin);
  freopen("employ.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0);
  Init();
  cin >> n >> m >> s;
  s = " " + s;
  for(int i = 1, x; i <= n; i++) cin >> x, num[x]++;
  for(int i = 0; i <= n; i++) {
    npre[i] = num[i];
    if(i) npre[i] += npre[i - 1];
  }
  for(int i = 1; i <= n; i++) {
    pre[0][i] = pre[0][i - 1];
    pre[1][i] = pre[1][i - 1];
    pre[s[i] - '0'][i]++;
  }
  f[0][0][0] = 1;
  for(int i = 0; i < n; i++) {
    int cr = (i & 1), nx = !cr;
    memset(f[nx], 0, sizeof(f[nx]));
    for(int j = 0; j <= pre[1][i]; j++) {
      for(int k = 0; k <= pre[1][i] - j; k++) {
        if(s[i + 1] == '0') {
          int cnt = pre[0][i] + j + 1;
          for(int t = 0; t <= min(k, num[cnt]); t++) {
            Add(f[nx][j][k - t], (ll)f[cr][j][k] * dn[k][t] % mod * C[num[cnt]][t]);
          }
        }else {
          Add(f[nx][j][k + 1], f[cr][j][k]); // 1 1
          int cnt = pre[0][i] + j + 1;       // 1 0
          int used = pre[1][i] - k;
          if(npre[cnt - 1] <= used) continue;
          for(int t = 0; t <= min(k, num[cnt]); t++) {
            Add(f[nx][j + 1][k - t], (ll)f[cr][j][k] * dn[k][t] % mod * C[num[cnt]][t] % mod * (npre[cnt - 1] - used));
          }
        }
      }
    }
  }
  for(int c = 0; c <= pre[1][n]; c++) {
    int cur = pre[0][n] + c;
    int cnt = 0;
    for(int j = cur + 1; j <= n; j++) cnt += num[j];
    for(int k = 0; k + c <= pre[1][n]; k++) {
      if(k > cnt) continue;
      Add(ans[pre[1][n] - c], (ll)f[n & 1][c][k] * dn[cnt][k]);
    }
  }
  int res = 0;
  for(int i = m; i <= n; i++) Add(res, ans[i]);
  cout << (ll)res * dn[pre[0][n]][pre[0][n]] % mod << "\n";
  return 0;
}