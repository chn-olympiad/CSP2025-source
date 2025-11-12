#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

const int N = 210;


struct Node {
    pii a, b, c;
    long long cnt;
}dp[N][N];

long long ans1[N][N][3];

pair<int, int> a[N][4];
int f[4];

int lmt, n;
int t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    #ifndef LOCAL
    freopen("club.in", "r", stdin);
    freopen("club.out1", "w", stdout);
    #endif // LOCAL

    cin >> t;
    for (int ZhX = 1;ZhX <= t; ZhX++) {
        cin >> n;
        lmt = n / 2;

        for (int i = 1; i <= n; i++) {
            int a1, b1, c1;
            cin >> a1 >> b1 >> c1;
            pair<int, int> a2 = {a1, 1}, b2 = {b1, 2}, c2 = {c1, 3};

            if (a2.first < b2.first) {
                pii p = a2;
                a2 = b2;
                b2 = p;
            }
            if (c2.first > b2.first) {
                pii p = c2;
                c2 = b2;
                b2 = p;
            }
            if (a2.first < b2.first) {
                pii p = a2;
                a2 = b2;
                b2 = p;
            }

            ans1[i][i][a2.second] = a2.first;
            ans1[i][i][b2.second] = b2.first;
            ans1[i][i][c2.second] = c2.first;
        }

        for (int kkk = 0; kkk < 3; kkk++)
        for (int len = 1; len < n; len++) {
            for (int i = 1; i <= n; i++) {
                int j = i + len;
                ans1[i][j][kkk] = min(ans1[i+1][j][kkk], ans1[j][j-1][kkk]);
            }
        }

        long long int ansa = min(ans1[1][n][0], ans1[1][n][1]);
        ansa = min(ans1[1][n][2], ansa);

        cout << ansa << '\n';
    }

    return 0;
}
