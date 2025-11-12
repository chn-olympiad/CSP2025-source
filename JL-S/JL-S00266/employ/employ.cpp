#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
// #define int LL
int n;
const int maxn = 20;
const int maxs = 1 << 18;
int a[maxn], c[maxn]; 
int ans, p[maxn];
int m;
char s[maxn];

signed main() {
  freopen("employ.in", "r", stdin);
  freopen("employ.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n >> m;
  cin >> s + 1;
  for(int i = 1; i <= n; ++ i) a[i] = s[i] - '0';
  for(int i = 1; i <= n; ++ i) cin >> c[i]; 
  for(int i = 1; i <= n; ++ i) p[i] = i;
  do {  
    int cnt = 0; 
    for(int i = 1; i <= n; ++ i) {
      int left = i - 1 - cnt;
      if(left >= c[p[i]]) continue ;
      cnt += a[i];
    }
    ans += (cnt >= m); 
  } while(next_permutation(p + 1, p + 1 + n)); 
  cout << ans << '\n'; 
  return 0; 
}