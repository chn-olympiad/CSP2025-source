#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <ctime>
#include <random>
#include <chrono>

typedef long long ll;
typedef unsigned long long ull;
typedef double lf;
typedef unsigned int uint;

using namespace std;

const int MAXN = 1e5 + 10;

int n, a[MAXN][3], b[3][MAXN], c[MAXN];
int cnt[3];

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    int T; cin >> T;
    while (T--)
    {
        cin >> n;
        int lmt = n / 2;
        ll ans = 0;
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < 3; i++) b[i][0] = 0;
        for (int i = 1; i <= n; i++)
        {
            int mx = -1, p = 0;
            for (int j = 0; j < 3; j++)
            {
                cin >> a[i][j];
                if (a[i][j] > mx) mx = a[i][j], p = j;
            }
            ans += mx, cnt[p]++, b[p][++b[p][0]] = i;
        }
        int p = 0, mx = -1;
        for (int j = 0; j < 3; j++)
            if (mx < cnt[j]) mx = cnt[j], p = j;
        if (p != 0)
        {
            for (int i = 1; i <= n; i++)
                swap(a[i][0], a[i][p]);
            swap(cnt[0], cnt[p]);
            swap(b[0], b[p]);
        }
        int m = b[0][0];
        for (int i = 1; i <= m; i++) c[i] = a[b[0][i]][0] - max(a[b[0][i]][1], a[b[0][i]][2]);
        sort(c + 1, c + m + 1);
        int x = cnt[0], k = 1;
        while (x > lmt) ans -= c[k++], x--;
        cout << ans << '\n';
    }
    return 0;
}