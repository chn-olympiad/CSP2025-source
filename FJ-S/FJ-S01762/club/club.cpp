#include <bits/stdc++.h>
using namespace std;
#define FILE(x) freopen(x".in", "r", stdin); freopen(x".out", "w", stdout);
#define pb push_back
const int N = 1e5 + 5;
int T, ans, n, a[N][3];
vector <int> w[N];
int main()
{
    FILE("club");
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> n; ans = 0; 
        for (int j = 0; j < 3; j++) w[j].clear();
        for (int i = 1; i <= n; i++) 
        {
            int p = 0;
            for (int j = 0; j < 3; j++) cin >> a[i][j];
            if (a[i][1] > a[i][p]) p = 1;
            if (a[i][2] > a[i][p]) p = 2;
            if (!p) w[0].pb(a[i][0] - max(a[i][1], a[i][2])), ans += a[i][0];
            else if (p == 1) w[1].pb(a[i][1] - max(a[i][0], a[i][2])), ans += a[i][1];
            else w[2].pb(a[i][2] - max(a[i][0], a[i][1])), ans += a[i][2];
        }
        int p = 0;
        if ((int)w[1].size() > (int)w[p].size()) p = 1; if ((int)w[2].size() > (int)w[p].size()) p = 2;
        if ((int)w[p].size() > n / 2)
        {
            int x = (int)w[p].size() - n / 2;
            sort(w[p].begin(), w[p].end());
            for (int i = 0; i < x; i++) ans -= w[p][i];
        }
        cout << ans << "\n";
    }
    return 0;
}