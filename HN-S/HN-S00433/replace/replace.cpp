#include<bits/stdc++.h>
#define int long long
#define H 19260817
#define rint register int
#define For(i,l,r) for(rint i=l;i<=r;++i)
#define FOR(i,r,l) for(rint i=r;i>=l;--i)
#define mod 1000000007

using namespace std;

const int N = 3e3 + 10, L = 2e6 + 10;

int n, m, p[L], Hash1[2][N][N], Hash2[2][N][N], len[N], Len[N];

string s[2][N], t[2][N];

int cnt(int id, int op, int l, int r) {
  if(l > r) return 0;
  return (Hash1[op][id][r] - (Hash1[op][id][l-1] * p[r-l+1] % mod) + mod) % mod;
}

int Cnt(int id, int op, int l, int r) {
  if(l > r) return 0;
  return (Hash2[op][id][r] - (Hash2[op][id][l-1] * p[r-l+1] % mod) + mod) % mod;
}

signed main() {
  freopen("replace.in", "r", stdin);
  freopen("replace.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n >> m;
  p[0] = 1; 
  For(i,1,L-5) p[i] = (p[i-1] * H) % mod;
  For(i,1,n) {
    cin >> s[0][i] >> s[1][i];
    len[i] = s[0][i].size();
    s[0][i] = " " + s[0][i];
    s[1][i] = " " + s[1][i];
    For(j,1,len[i]) Hash1[0][i][j] = ((Hash1[0][i][j-1] * H) % mod + (s[0][i][j] - 'a')) % mod;
    For(j,1,len[i]) Hash1[1][i][j] = ((Hash1[1][i][j-1] * H) % mod + (s[1][i][j] - 'a')) % mod;
  }
  For(i,1,m) {
    cin >> t[0][i] >> t[1][i];
    Len[i] = t[0][i].size();
    
    t[0][i] = " " + t[0][i];
    t[1][i] = " " + t[1][i];
    For(j,1,Len[i]) Hash2[0][i][j] = ((Hash2[0][i][j-1] * H) % mod + (t[0][i][j] - 'a')) % mod;
    For(j,1,Len[i]) Hash2[1][i][j] = ((Hash2[1][i][j-1] * H) % mod + (t[1][i][j] - 'a')) % mod;
  }
  For(i,1,m) {
    int ans = 0;
    For(j,1,n) {
      For(k,1,Len[i]-len[j]+1) {
        int l = k, r = k + len[j] - 1;
        if(Cnt(i, 0, 1, l-1) == Cnt(i, 1, 1, l-1) &&
           Cnt(i, 0, r+1, Len[i]) == Cnt(i, 1, r+1, Len[i]) &&
           Cnt(i, 0, l, r) == cnt(j, 0, 1, len[j]) &&
           Cnt(i, 1, l, r) == cnt(j, 1, 1, len[j]) ) {
          ans++;
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}

/*
我不会在给自己留遗憾了，就算失败也值得，因为这就是我独有的人生，风光而璀璨
*/