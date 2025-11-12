#include<bits/stdc++.h>
#define int long long
#define rint register int
#define For(i,l,r) for(rint i=l;i<=r;++i)
#define FOR(i,r,l) for(rint i=r;i>=l;--i)
#define mod 99824353

using namespace std;

const int N = 1e5 + 10;

struct Node {
  int val[4], op[4], mn, mu;
} a[N];

int n, m, b[4], ans, pos, p[N], tot;

vector<int> vec[4];

bool cmp(int x, int y) {
  return (a[x].mn == a[y].mn ? a[x].mu < a[y].mu : a[x].mn < a[y].mn);
}

void solve() {
  memset(b, 0, sizeof b);
  memset(p, 0, sizeof p);
  pos = ans = tot = 0;
  For(i,1,3) vec[i].clear();
  cin >> n;
  For(i,1,n) {
    For(j,1,3) cin >> a[i].val[j];
    int num = INT_MIN;
    For(j,1,3) if(num < a[i].val[j]) num = a[i].val[j], a[i].op[1] = j;
    num = INT_MAX;
    For(j,1,3) if(num > a[i].val[j]) num = a[i].val[j], a[i].op[3] = j;
    a[i].op[2] = 6 - (a[i].op[1] + a[i].op[3]);
    ans += a[i].val[a[i].op[1]], b[a[i].op[1]]++;
    a[i].mn = a[i].val[a[i].op[1]] - a[i].val[a[i].op[2]];
    a[i].mu = a[i].val[a[i].op[1]] - a[i].val[a[i].op[3]];
    vec[a[i].op[1]].push_back(i);
  }
  For(i,1,3) if(vec[i].size() > n / 2) pos = i;
  for (auto x : vec[pos]) p[++tot] = x;
  if(pos == 0) {
    cout << ans << '\n';
    return ;
  }
  sort(p + 1, p + tot + 1, cmp);
  int txt = 0;
  For(i,1,tot) {
    int x = p[i];
    txt++;
    if(b[a[x].op[2]] < n / 2) {
      ans -= a[x].mn;
      b[a[x].op[2]]++;
    } else if(b[a[x].op[3]] < n / 2) {
      ans -= a[x].mu;
      b[a[x].op[3]]++;
    }
    if(txt == vec[pos].size() - (n / 2)) break;
  }
  cout << ans << '\n';
  return ;
}

signed main() {
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> m;
  while(m--) solve();
  return 0;
}
/*
我不会在给自己留遗憾了，就算失败也值得，因为这就是我独有的人生，风光而璀璨
*/