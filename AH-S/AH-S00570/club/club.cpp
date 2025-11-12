#include <bits/stdc++.h>
using namespace std;
int tt;
int n;
const int N = 1e5 + 10;
int a[N][5];
int in[N][5];
int del[N];
signed main(void) {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> tt;
    while (tt --) {
        cin >> n;
        int ans = 0;
        for (int i = 1; i <= n; i ++) cin >> a[i][1] >> a[i][2] >> a[i][3];
        in[0][1] = in[0][2] = in[0][3] = 0;
        for (int i = 1; i <= n; i ++) {
            if(a[i][1] >= max(a[i][2], a[i][3])) in[++ in[0][1]][1] = i, del[i] = a[i][1] - max(a[i][2], a[i][3]);
            else if(a[i][2] >= max(a[i][1], a[i][3])) in[++ in[0][2]][2] = i, del[i] = a[i][2] - max(a[i][1], a[i][3]);
            else in[++ in[0][3]][3] = i, del[i] = a[i][3] - max(a[i][2], a[i][1]);
            ans += max(a[i][1], max(a[i][2], a[i][3]));
        }
        int ne = -1;
        if(in[0][1] > n / 2) ne = 1;
        else if(in[0][2] > n / 2) ne = 2;
        else if(in[0][3] > n / 2) ne = 3;
        if(ne == -1) cout << ans << endl;
        else {
            vector <int> vec;
            for (int i = 1; i <= in[0][ne]; i ++) vec.emplace_back(del[in[i][ne]]);
            sort(vec.begin(), vec.end());
            for (int i = 0; i < in[0][ne] - n / 2; i ++) ans -= vec[i];
            cout << ans << endl;
        }
    }
    return 0;
}
