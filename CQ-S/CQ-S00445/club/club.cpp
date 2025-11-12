#include <bits/stdc++.h>
using namespace std;

#define int long long
#define PII pair<int, int>
#define _for(i, a, b) for (int i = (a); i <= (b); i++)
#define _pfor(i, a, b) for (int i = (a); i >= (b); i--)

int read() {
  char c;
  int x = 0, f = 1;
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + c - '0';
    c = getchar();
  }
  return x * f;
}

void wr(int x) {
  if (x < 0) x = -x, putchar('-');
  if (x > 9) wr(x / 10);
  putchar(x % 10 + '0');
}

const int N = 1e5 + 5;

int T, n, a[N][3], posmax[N], cnt[N], b[3], bb[N], tot;

signed main() {
//  freopen("club5.in", "r", stdin);
//  freopen("club5.out", "w", stdout);
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);
  cin >> T;
  while (T--) {
    cin >> n;
    _for(i, 1, n) a[i][0] = read(), a[i][1] = read(), a[i][2] = read();
    cnt[0] = cnt[1] = cnt[2] = 0; 
    int res = 0;
    _for(i, 1, n) {
      int maxn = 0;
      _for(j, 0, 2) {
        if (a[i][j] > maxn) {
          maxn = a[i][j];
          posmax[i] = j;
        }
      }
      res += maxn;
      cnt[posmax[i]]++;
    }
    if (max({cnt[0], cnt[1], cnt[2]}) <= n / 2) cout << res << endl;
    else {
      int id = -1;
      _for(i, 0, 2) if (cnt[i] > n / 2) id = i;
      tot = 0;
      _for(i, 1, n) {
        b[0] = a[i][0], b[1] = a[i][1], b[2] = a[i][2];
        sort(b, b + 3);
        if (cnt[posmax[i]] > n / 2) {
          bb[++tot] = b[2] - b[1];
        }
      }
      sort(bb + 1, bb + tot + 1);
      _for(i, 1, max({cnt[0], cnt[1], cnt[2]}) - n / 2) res -= bb[i]; 
      cout << res << endl;
    }
  }
} 
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
