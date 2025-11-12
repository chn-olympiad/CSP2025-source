#include <bits/stdc++.h>

using std::cin;
using std::cout;

constexpr int N = 100005;

int n;
int a[4][N];
int nd2;

bool cmp(int a, int b) { return a < b; }

void sol() {
    scanf("%d", &n);
    // cin >> n;
    nd2 = n / 2;
    for (int i = 0; i < n; ++i) {
        // cin >> a[0][i] >> a[1][i] >> a[2][i];
        scanf("%d%d%d", &a[0][i], &a[1][i], &a[2][i]);
    }

    int flag[N];
    memset(flag, 0, (n+2)*sizeof(flag[0]));
    int cnt[3];

    int maxsum = 0;
    while(flag[n] == 0) {
        //for (int i = 0; i < n; ++i) {
        //    cout << flag[i] << ' ';
        //}
        //cout << '\n';
        cnt[0] = cnt[1] = cnt[2] = 0;
        int sum = 0;
        bool broken = false;
        for (int i = 0; i < n; ++i) {
            if (cnt[flag[i]] >= nd2) {
                broken = true;
                break;
            }

            sum += a[flag[i]][i];
            ++cnt[flag[i]];
            //cout << "  " << flag[i] << ' ';
            //for (int i = 0; i < 3; ++i) {
            //    cout << cnt[i] << ' ';
            //}
            //cout << '\n';
        }
        if (!broken) {
            maxsum = std::max(sum, maxsum);
        }
        ++flag[0];
        for (int i = 0; i < n; ++i) {
            if (flag[i] >= 3) {
                flag[i] = 0;
                ++flag[i+1];
            }
        }
    }

    printf("%d\n", maxsum);
    // cout << maxsum << '\n';
    return;
}

int t;

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    scanf("%d", &t);
    // cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}
