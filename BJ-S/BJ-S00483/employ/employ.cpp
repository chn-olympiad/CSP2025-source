#include<algorithm>
#include<cstdio>
#include<iostream>
using namespace std;

int n, m, sy, kt = 1, cnt, s[505], c[505];
const long long MOD = 998244353;
long long ans = 1;
bool flag, vis[505];

int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);

    cin >> n >> m;
    sy = n;
    for (int i = 1; i <= n; i++) {
        scanf("%1d", &s[i]);
    }
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    sort(c + 1, c + n + 1);
    while (cnt > m) {
        vis[kt] = true;
        sy--;
        kt++;
        flag = true;
        for (int i = kt; i <= n; i++) {
            c[i]--;
            if (!vis[i] && c[i] < 1) {
                vis[i] = true;
                sy--;
                if (flag) {
                    kt++;
                }
            }
            else {
                flag = false;
            }
        }
        cnt = 0;
        for (int i = kt; i <= n; i++) {
            if (!vis[i]) {
                cnt++;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        ans = ans * i % MOD;
    }
    cout << ans;

    return 0;
}
