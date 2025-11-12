#include <bits/stdc++.h>
#define int long long
using namespace std;

int t, n, a[100010][3], sum, id, mx, val[100010], cnt[3];
priority_queue<int> q;
signed main() {
  freopen ("club.in", "r", stdin);
  freopen ("club.out", "w", stdout);
  scanf ("%lld", &t);
  while (t--) {
    scanf ("%lld", &n);
    sum = cnt[0] = cnt[1] = cnt[2] = 0;
    for (int i = 1; i <= n; i++) {
      val[i] = 0;
      for (int j = 0; j < 3; j++) {
        scanf ("%lld", &a[i][j]);
        if (a[i][j] > a[i][val[i]])
          val[i] = j;
      }
      sum += a[i][val[i]];
      cnt[val[i]]++;
    }
    if (cnt[0] <= n / 2 && cnt[1] <= n / 2 && cnt[2] <= n / 2) {
      printf ("%lld\n", sum);
      continue;
    }
    while (!q.empty())
      q.pop();
    for (int j = 0; j < 3; j++)
      if (cnt[j] > n / 2)
        id = j;
    for (int i = 1; i <= n; i++)
      if (val[i] == id) {
        mx = 0;
        for (int j = 0; j < 3; j++)
          if (j != val[i])
            mx = max (mx, a[i][j]);
        q.push (mx - a[i][val[i]]);
      }
    while (cnt[id] > n / 2) {
      sum += q.top();
      q.pop();
      cnt[id]--;
    }
    printf ("%lld\n", sum);
  }
  return 0;
}

