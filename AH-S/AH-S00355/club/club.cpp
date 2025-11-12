#include <bits/stdc++.h>
using namespace std;
int T;

bool cmp(int x, int y) {
    return x > y;
}

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> T;
    while (T --) {
        int n;
        cin >> n;
        int a[n + 5][5];
        bool flag1 = true, flag2 = true;
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= 3; j ++) {
                cin >> a[i][j];
                if (j != 1 && a[i][j] != 0) flag1 = false;
                if (j == 3 && a[i][j] != 0) flag2 = false;
            }
        if (flag1 == true) {
            long long tot = 0;
            int b[n + 5];
            for (int i = 1; i <= n; i ++) b[i] = a[i][1];
            sort(b + 1, b + n + 1, cmp);
            for (int i = 1; i <= n / 2; i ++) tot += b[i];
            cout << tot << endl;
            continue;
        }
        if (flag2 == true) {
            int choose1[n + 5], choose2[n + 5], middle[n + 5];
            int dist1[n + 5], dist2[n + 5];
            int num1 = 0, num2 = 0, num3 = 0, distnum1 = 0, distnum2 = 0;
            for (int i = 1; i <= n; i ++) {
                if (a[i][1] > a[i][2]) {
                    num1 ++;
                    choose1[num1] = a[i][1];
                    distnum1 ++;
                    dist1[distnum1] = a[i][1] - a[i][2];
                }
                else if (a[i][1] < a[i][2]) {
                    num2 ++;
                    choose2[num2] = a[i][2];
                    distnum2 ++;
                    dist2[distnum2] = a[i][2] - a[i][1];
                }
                else {
                    num3 ++;
                    middle[num3] = a[i][1];
                }
            }
            long long tot = 0;
            sort(choose1 + 1, choose1 + num1 + 1, cmp);
            sort(choose2 + 1, choose2 + num2 + 1, cmp);
            for (int i = 1; i <= num1; i ++) tot += choose1[i];
            for (int i = 1; i <= num2; i ++) tot += choose2[i];
            for (int i = 1; i <= num3; i ++) tot += middle[i];
            if (num1 <= n / 2 && num2 <= n / 2) {
                cout << tot << endl;
                continue;
            }
            else if (num1 > n / 2) {
                sort(dist1 + 1, dist1 + distnum1 + 1);
                for (int i = 1; i <= num1 - n / 2; i ++) tot -= dist1[i];
            }
            else {
                sort(dist2 + 1, dist2 + distnum2 + 1);
                for (int i = 1; i <= num2 - n / 2; i ++) tot -= dist2[i];
            }
            cout << tot << endl;
            continue;
        }
        //if (n <= 16) {
            int sum[n + 5];
            for (int i = 0; i <= n; i ++) sum[i] = 0;
            long long ans = 0;
            while (1) {
                sum[n] ++;
                for (int i = n; i >= 1; i --)
                    if (sum[i] == 3) {
                        sum[i] = 0;
                        sum[i - 1] ++;
                    }
                if (sum[0] == 1) break;
                int num1 = 0, num2 = 0, num3 = 0;
                for (int i = 1; i <= n; i ++) {
                    if (sum[i] == 0) num1 ++;
                    else if (sum[i] == 1) num2 ++;
                    else num3 ++;
                }
                if (num1 > n / 2 || num2 > n / 2 || num3 > n / 2) continue;
                long long tot = 0;
                for (int i = 1; i <= n; i ++) tot += a[i][sum[i] + 1];
                if (tot > ans) ans = tot;
            }
            cout << ans << endl;
            //continue;
        //}

    }
    return 0;
}
