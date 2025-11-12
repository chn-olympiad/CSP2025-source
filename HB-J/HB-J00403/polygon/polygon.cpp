#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5050;
const int MODE = 998244353;

int sticks[MAXN], n, ans, num[MAXN];

bool cmp(int a, int b) {
    return a > b;
}

void bl(int b, int now, int cnt, int maxx, int sum) {
    if (cnt == b && sum > 2 * maxx) {
        ans++;
        return ;
    }
    if (now == n || cnt > b) {
        return ;
    }
    bl(b, now + 1, cnt, maxx, sum); // do nothing but go on
    bl(b, now + 1, cnt + 1, max(maxx, sticks[now + 1]), sum + sticks[now + 1]); // plus the next one
    return ;
}

int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> sticks[i];
        num[sticks[i]]++;
    }
    if (num[1] == n) {
        for (int i = 3; i <= n; i++) {
            long int temp = 1;
            for (int j = 2; j <= n; j++) {
                temp *= j;
                temp %= MODE;
            }
            long int temp2 = 1, temp3 = 1;
            for (int j = 2; j <= i; j++) {
                temp2 *= j;
                temp2 %= MODE;
            }
            for (int j = 2; j <= n - i; j++) {
                temp3 *= j;
                temp3 %= MODE;
            }
            ans += (temp / temp2 / temp3);
            ans %= MODE;
        }
        cout << ans;
        return 0;
    }
    sort(sticks, sticks + n + 1, cmp);
    for (int i = 3; i <= n; i++) {
        bl(i, 0, 0, -1, 0);
        ans %= MODE;
    }
    cout << ans;
    return 0;
}
