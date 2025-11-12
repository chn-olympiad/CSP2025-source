#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    int m;
    int k;
    cin >> n >> m >> k;
    for(int i = 0; i < m; ++i) {
        int a;
        int b;
        int c;
        cin >> a >> b >> c;
    }
    int x = 0;
    int a[k];
    int b[k][n];
    for(int i = 0; i < k; ++i) {
        int luckkkkk;
        cin >> luckkkkk;
        a[i] = luckkkkk;
        if(luckkkkk != 0) {
            x = 1;
        }
        for(int j = 0; j < n; ++j) {
            int luck;
            cin >> luck;
            b[i][j] = luck;
            if(luck != 0) {
                x = 1;
            }
        }
    }
    if(x == 0) {
        cout << "0";
    } else {
        long long ans = 10000000000000000;
        long long minn = 0;
        for(int i = 0; i < k; ++i) {
            minn = minn + a[i];
            for(int j = 0; j < n; ++j) {
                minn = minn + b[i][j];
            }
            if(minn < ans) {
                ans = minn;
            }
            minn = 0;
        }
        cout << ans;
    }
    return 0;
}