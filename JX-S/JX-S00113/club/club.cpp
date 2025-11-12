/*
    Author : Sparkle_ZH & Sparklee
    Right Output ! & Accepted !
*/

#include <bits/stdc++.h>
#define lowbit(x) ((x) & (- (x)))
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define ll long long
#define fir first
#define sec second
using namespace std;

template<typename T> inline void write(T x, int f = -1) {
    if (x < 0) putchar('-'), x = -x;
    static short Stack[50], top(0);
    do Stack[++ top] = x % 10, x /= 10; while (x);
    while (top) putchar(Stack[top --] | 48);
    if (~ f) putchar(f ? '\n' : ' ');
}

const int N = 1e5 + 5;
int n, p, ans, cnt[3], bel[N], val[N];

void solve() {
    ans = cnt[0] = cnt[1] = cnt[2] = 0;

    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        if (x >= y && x >= z) {
            ans += x;
            val[i] = x - max(y, z);
            bel[i] = 0, cnt[0] ++;
        } else if (y >= x && y >= z) {
            ans += y;
            val[i] = y - max(x, z);
            bel[i] = 1, cnt[1] ++;
        } else {
            ans += z;
            val[i] = z - max(x, y);
            bel[i] = 2, cnt[2] ++;
        }
    }

    if (cnt[0] > n / 2) p = 0;
    else if (cnt[1] > n / 2) p = 1;
    else if (cnt[2] > n / 2) p = 2;
    else { write(ans, 1); return ; }

    vector<int> vec;
    for (int i = 1; i <= n; i ++)
        if (bel[i] == p) vec.pb(val[i]);

    sort(vec.begin(), vec.end());

    for (int i = 0; i < cnt[p] - n / 2; i ++)
        ans -= vec[i];

    write(ans, 1);
}

signed main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    int t; scanf("%d", &t);
    while (t --) solve();

    return 0;
}
