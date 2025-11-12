#include <bits/stdc++.h>
#define int long long
#define mod1 998244353
#define mod2 1000000007
using namespace std;

int n, q, m, m2, ans, len[200010], h1s1[200010], h2s1[200010], h1s2[200010], h2s2[200010], h1t1[5000010], h2t1[500010], h1t2[500010], h2t2[500010], pw1[5000010], pw2[5000010];
char s1[5000010], s2[5000010];
int get1 (int l, int r, const int* sh) {
  return (sh[r] - sh[l - 1] * pw1[r - l + 1] % mod1 + mod1) % mod1;
}
int get2 (int l, int r, const int* sh) {
  return (sh[r] - sh[l - 1] * pw2[r - l + 1] % mod2 + mod2) % mod2;
}
bool check (int i, int j, const int* hs1, const int* hs2, const int* h1, const int* h2) {
  int m = len[i], r = j + m - 1;
  return hs1[i] == get1 (j, r, h1) && hs2[i] == get2 (j, r, h2);
}
signed main() {
  freopen ("replace.in", "r", stdin);
  freopen ("replace.out", "w", stdout);
  pw1[0] = pw2[0] = 1;
  for (int i = 1; i <= 5000001; i++) {
    pw1[i] = pw1[i - 1] * 26 % mod1;
    pw2[i] = pw2[i - 1] * 26 % mod2;
  }
  scanf ("%lld%lld", &n, &q);
  for (int i = 1; i <= n; i++) {
    scanf ("%s%s", s1 + 1, s2 + 1);
    len[i] = strlen (s1 + 1);
    for (int j = 1; j <= len[i]; j++) {
      h1s1[i] = (h1s1[i] * 26 + s1[j] - 'a') % mod1;
      h2s1[i] = (h2s1[i] * 26 + s1[j] - 'a') % mod2;
      h1s2[i] = (h1s2[i] * 26 + s2[j] - 'a') % mod1;
      h2s2[i] = (h2s2[i] * 26 + s2[j] - 'a') % mod2;
    }
  }
  while (q--) {
    scanf ("%s%s", s1 + 1, s2 + 1);
    m = strlen (s1 + 1);
    m2 = strlen (s2 + 1);
    if (m != m2) {
      printf ("0\n");
      continue;
    }
    for (int i = 1; i <= m; i++) {
      h1t1[i] = (h1t1[i - 1] * 26 + s1[i] - 'a') % mod1;
      h2t1[i] = (h2t1[i - 1] * 26 + s1[i] - 'a') % mod2;
      h1t2[i] = (h1t2[i - 1] * 26 + s2[i] - 'a') % mod1;
      h2t2[i] = (h2t2[i - 1] * 26 + s2[i] - 'a') % mod2;
    }
    ans = 0;
    for (int i = 1; i <= n; i++)
      for (int j = 1, r = len[i]; j <= m - len[i] + 1; j++, r++)
        ans += h1t1[j - 1] == h1t2[j - 1] && h2t1[j - 1] == h2t2[j - 1]
               && get1 (r + 1, m, h1t1) == get1 (r + 1, m, h1t2)
               && get2 (r + 1, m, h2t1) == get2 (r + 1, m, h2t2)
               && check (i, j, h1s1, h2s1, h1t1, h2t1) && check (i, j, h1s2, h2s2, h1t2, h2t2);
    printf ("%lld\n", ans);
  }
  return 0;
}


