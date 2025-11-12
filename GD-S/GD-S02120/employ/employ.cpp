#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using u32 = unsigned int;

constexpr int N = 505, mod = 998244353;
int n, K, c;
char s[N];
int a[N], cnt[N];
int f[N][N][N];

void add(int& x, int y) {
  if ((x += y) >= mod) x -= mod;
}

int used[N], S, ans, fail;

void dfs(int x) {
  if (x == n + 1) {
    if (S >= K) ++ans;
    return;
  }
  for (int i = 1; i <= n; i++) if (!used[i]) {
    used[i] = 1;
    int add = a[i] > fail && s[x];
    if (add) S++;
    else fail++;
    dfs(x + 1);
    if (add) S--;
    else fail--;
    used[i] = 0;
  }
}

int main() {
  freopen("employ.in", "r", stdin);
  freopen("employ.out", "w", stdout);

  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> K;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    s[i] -= '0';
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  for (int i = n; i >= 0; i--) {
    cnt[i] += cnt[i + 1];
  }
  // ???
  if (K == n) {
    if (count(s + 1, s + n + 1, 1) != n || cnt[1] != n) {
      cout << 0 << endl;
      return 0;
    } else {
      int ans = 1;
      for (int i = 1; i <= n; i++) {
        ans = 1ll * ans * i % mod;
      }
      cout << ans << endl;
      return 0;
    }
  }
  if (n <= 10) {dfs(1), cout << ans << endl;return 0;}
  if (K==1) {
    int ans =1,cc=0;for(int i=1;i<=n;i++) {
      if(s[i]) {
        ans = 1ll * ans * (n -cnt[i] - cc) % mod;
        ++cc;
      }
    }
    int c=0;for(int i=1;i<=n;i++)c+=!s[i];
    for(int i=1;i<=c;i++)ans=1ll*ans*i%mod;
    int all=1;for(int i=1;i<=n;i++)all=1ll*all*i%mod;
    cout <<(all+mod-ans)%mod<<endl;
    return 0;
  }
  // for (int k = K; k <= n; k++) {
  //   f[0][0][k] = 1;
  // }
  // for (int i = 1; i <= n; i++) {
  //   for (int j = 0; j < i; j++) {
  //     for (int k = 0; k < n - i; k++) {

  //     }
  //   }
  // }
  // for (int j = 0; j <= n; j++) if (n - j >= K) {
  //   f[n + 1][j][0] = 1;
  // }
  // for (int i = n; i >= 1; i--) {
  //   if (s[i] == 0) {
  //     for (int j = 1; j <= i; j++) {
  //       for (int k = 0; k <= n - i; k++) {
  //         add(f[i][j - 1][k], f[i + 1][j][k]);
  //       }
  //     }
  //   } else {
  //     for (int j = 0; j < i; j++) {
  //       for (int k = 0; k <= n - i; k++) {
  //         int z = cnt[j + 1] - k;
  //         if (z < 0) break;
  //         add(f[i][j][k + 1], (ll)f[i + 1][j][k] * z % mod);
  //         add(f[i][j][k], (ll)f[i + 1][j + 1][k] * (n - c - z) % mod);
  //       }
  //     }
  //   }
  //   c += s[i];
  // }
  // int ans = 0;
  // for (int i = K; i <= n; i++) {
  //   add(ans, f[1][0][i]);
  // }
  // c = n - c;
  // for (int i = 1; i <= c; i++) {
  //   ans = 1ll * ans * i % mod;
  // }
  // cout << ans << endl;

  return 0;
}