#include<bits/stdc++.h>
using namespace std;
//22:35~?
#define int long long
const int MAXN = 1e5+1;
int T, n, a[MAXN][10], m1c, m2c, m3c;
struct RIP{
    int i, val;
}rep21[MAXN], rep31[MAXN];
bool cmp(RIP x, RIP y) {
    return x.val > y.val;
}
signed main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
  cin >> T;
  while(T--) {
    cin >> n; m1c = m2c = m3c = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i][1] >> a[i][2] >> a[i][3];
        m1c += a[i][1]; m2c += a[i][2]; m3c += a[i][3];
    }
    if(m2c > m1c && m2c > m3c) {
        swap(m2c, m1c);
        for(int i = 1; i <= n; i++) {
            swap(a[i][2], a[i][1]);
        }
    } else if(m3c > m1c && m3c > m2c) {
        swap(m3c, m1c);
        for(int i = 1; i <= n; i++) {
            swap(a[i][3], a[i][1]);
        }
    }
    for(int i = 1; i <= n; i++) {
        rep21[i].i = i; rep21[i].val = a[i][2] - a[i][1];
        rep31[i].i = i; rep31[i].val = a[i][3] - a[i][1];
    }
    sort(rep21+1, rep21+1+n, cmp);
    for(int i = 1; i <= n / 2; i++) {
//        if(rep21[i].val < 0) break;
        m1c += rep21[i].val;
        rep31[i].val = a[i][3] - a[i][2];
    }
    sort(rep31+1, rep31+1+n, cmp);
    for(int i = 1; i <= n / 2; i++) {
        if(rep31[i].val < 0) break;
        m1c += rep31[i].val;
    }
    cout << m1c << endl;
  }

}
