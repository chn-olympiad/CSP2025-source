#include <bits/stdc++.h>
#define fi first
#define se second
#define mkp(x, y) make_pair(x, y)
using namespace std;
using LL = long long;
using Pii = pair<int, int>;

ifstream fin("employ.in");
ofstream fout("employ.out");

const int kMaxN = 505, kMod = 998244353;

int n, m, a[kMaxN], fa[kMaxN], sum[kMaxN], c[kMaxN];
char s[kMaxN];
LL ans;

int Find(int x) {
  return (fa[x] == x ? x : fa[x] = Find(fa[x]));
}

void Union(int x, int y) {
  x = Find(x), y = Find(y);
  if(x != y) {
    fa[x] = y;
  }
}

LL Pow(LL x, int n, LL ans = 1) {
  for(; n; n >>= 1, x = x * x % kMod) {
    if(n & 1) {
      ans = ans * x % kMod; 
    }
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  fin >> n >> m;
  for(int i = 1; i <= n; i++) {
    fin >> s[i];
  }
  for(int i = 1; i <= n; i++) {
    fin >> c[i];
  }
  if(n <= 10) {
    iota(a + 1, a + n + 1, 1);
    do {
      int tot = 0;
      int pre = 0;
      for(int i = 1; i <= n; i++) {
        if(s[i] != '0' && pre < c[a[i]]) {
          tot++;
        } else {
          pre++;
        }
      }
      ans += (tot >= m);
    } while(next_permutation(a + 1, a + n + 1));
    fout << ans << endl;
    return 0;
  }
  
  if(m == 1) {
    
  }
  if(n <= 18) {
    LL ans = 0;
    for(int i = 0; i < (1 << n); i++) {
      iota(fa, fa + n + 1, 0);
      bool f = 1;
      for(int j = 0; j < n; j++) {
        int tmp = upper_bound(sum + 1, sum + n + 1, c[j]) - sum - 1;
        if(!Find(tmp)) {
          f = 0;
          break;
        }
        Union(tmp, tmp - 1);
      }
      if(f) {
        (++ans) %= kMod;
      }
    }
    fout << ans << endl;
  }
  return 0;
}

