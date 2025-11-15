#include <bits/stdc++.h>
using namespace std;

int main()
{
  freopen("employ.in", "r", stdin);
  freopen("employ.out", "w", stdout);
  long long int i, n, m, cnt=0;
  string s;
  cin >> n >> m >> s;
  long long int a[n], c[n], ans = 0;
  for(i=0; i<n; i++) a[i] = i;
  for(i=0; i<n; i++) cin >> c[i];
  do
  {
    cnt++;
    long long int gg = 0, ppl = 0;
    for(int i=0; i<n; i++)
    {
      if(gg<c[a[i]] && s[i]=='1') ppl++;
      else gg++;
    }
    if(ppl>=m) ans++;
  }
  while(next_permutation(a, a+n));
  cout << ans % 998244353 << "\n";
  return 0;
}