#include <bits/stdc++.h>
using namespace std;
int T,n,a[100005][5];
int aa,bb,cc;
bool cmp (int x,int y) {
    int xx = a[x][aa] - max(a[x][bb],a[x][cc]);
    int yy = a[y][aa] - max(a[y][bb],a[y][cc]);
    return xx > yy;
}
vector <int> v[4];
signed main () {
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> T;
    while (T--) {
        int ans = 0;
        cin >> n;
        for (int i = 1;i <= n;i++) {
            cin >> a[i][1] >> a[i][2] >> a[i][3];
            if (a[i][1] >= a[i][2] && a[i][1] >= a[i][3]) {
                v[1].push_back(i);
                ans += a[i][1];
                continue;
            }
            if (a[i][2] >= a[i][1] && a[i][2] >= a[i][3]) {
                v[2].push_back(i);
                ans += a[i][2];
                continue;
            }
            if (a[i][3] >= a[i][2] && a[i][3] >= a[i][1]) {
                v[3].push_back(i);
                ans += a[i][3];
                continue;
            }
        }
        aa = 1,bb = 2,cc = 3;
        if (v[2].size() > n / 2) {
            aa = 2,bb = 1;
        }
        if (v[3].size() > n / 2) {
            aa = 3,cc = 1;
        }
        int r = v[aa].size();
        sort(v[aa].begin(),v[aa].end(),cmp);
        while (r > n / 2) {
            int x = v[aa][r - 1];
            ans -= a[x][aa];
            ans += max(a[x][bb],a[x][cc]);
            r--;
        }
        cout << ans << endl;
        v[1].clear();
        v[2].clear();
        v[3].clear();
    }
    return 0;
}
/*
huai ren de xue cai shi hei se de
wo men yong yuan wan zi qian hong
yi fang shui tu yang yi bang ren jing
lang fei le liang shi hai jia zhuang qing xing
*/