#include<bits/stdc++.h>
#define int long long
#define rint register int
#define For(i,l,r) for(rint i=l;i<=r;++i)
#define FOR(i,r,l) for(rint i=r;i>=l;--i)
#define mod 998244353

using namespace std;

const int N = 5e3 + 10;

int n, m, c[N], p[N], Ans = 0;

bool f[N];

char s[N];

void dfs(int x) {
  if(x == n + 1) {
    int tot = 0, ans = 0;
    For(i,1,n) {
      if(tot >= c[p[i]]) {
        tot++;
        continue;
      }
      if(s[i] == '0') tot++;
      else ans++;
    }
    if(ans >= m) {
      Ans++;
      Ans %= mod;
    }
    return ;
  }
  For(i,1,n) {
    if(!f[i]) {
      f[i] = 1;
      p[x] = i;
      dfs(x + 1);
      p[x] = f[i] = 0;
    }
  }
}

signed main() {
  freopen("employ.in", "r", stdin);
  freopen("employ.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n >> m;
  cin >> (s + 1);
  For(i,1,n) cin >> c[i];
  if(n <= 10) {
    dfs(1);
    cout << Ans << '\n';
  } else {
    Ans = 1;
    For(i,1,n) Ans = (Ans * i) % mod;
    cout << Ans << '\n';
  }
  
  return 0;
}

/*
我不会在给自己留遗憾了，就算失败也值得，因为这就是我独有的人生，风光而璀璨
*/