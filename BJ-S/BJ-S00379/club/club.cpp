#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 1e5 + 5, PMAXN = 205;
int T;
int n, ans, cntB, a[MAXN][3], f[PMAXN][PMAXN / 2][PMAXN / 2], maxa[3];
vector<int> vA, vB;
bool fB[MAXN];
bool cmp(int x, int y)
{
    return x > y;
}
signed main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> T;
    while (T--)
    {
        memset(f, 0, sizeof(f));
        memset(maxa, 0, sizeof(maxa));
        memset(fB, 0, sizeof(fB));
        while (!vA.empty()) vA.pop_back();
        while (!vB.empty()) vB.pop_back();
        ans = 0;
        cntB = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) for (int j = 0; j <= 2; j++)
            cin >> a[i][j], maxa[j] = max(maxa[j], a[i][j]);
        if (maxa[1] == 0 && maxa[2] == 0)
        {
            for (int i = 1; i <= n; i++) vA.push_back(a[i][0]);
            sort(vA.begin(), vA.end(), cmp);
            for (int i = 0; i < n / 2; i++) ans += vA[i];
            cout << ans << endl;
            continue;
        }
        else if (maxa[2] == 0)
        {
            for (int i = 1; i <= n; i++) ans += max(a[i][0], a[i][1]);
            for (int i = 1; i <= n; i++) if (a[i][0] > a[i][1]) fB[i] = 1, cntB++;
            if (cntB < n / 2)
            {
                for (int i = 1; i <= n; i++)
                    if (!fB[i]) vB.push_back(a[i][1] - a[i][0]);
                sort(vB.begin(), vB.end());
                for (int i = 0; i < n / 2 - cntB; i++) ans -= vB[i];
            }
            if (cntB > n / 2)
            {
                for (int i = 1; i <= n; i++)
                    if (fB[i]) vB.push_back(a[i][0] - a[i][1]);
                sort(vB.begin(), vB.end());
                for (int i = 0; i < cntB - n / 2; i++) ans -= vB[i];
            }
            cout << ans << endl;
            continue;
        }
        for (int i = 1; i <= n; i++)
        for (int j = 0; j <= i && j <= n / 2; j++)
        for (int k = 0; j + k <= i && k <= n / 2; k++)
        {
            int l = i - j - k;
            if (l > n / 2) continue;
            if (j > 0) f[i][j][k] = max(f[i][j][k], f[i - 1][j - 1][k] + a[i][0]);
            if (k > 0) f[i][j][k] = max(f[i][j][k], f[i - 1][j][k - 1] + a[i][1]);
            if (l > 0) f[i][j][k] = max(f[i][j][k], f[i - 1][j][k] + a[i][2]);
            ans = max(ans, f[i][j][k]);
        }
        cout << ans << endl;
    }
    return 0;
}