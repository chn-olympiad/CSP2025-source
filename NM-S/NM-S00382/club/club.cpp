#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int i, j, n, t;
long long ans;
const int maxn = 100005;

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n;
        ans = 0;
        int range = n / 2;
        int r[3] = {};
        int dp[maxn] = {};
        int a[maxn][3] = {};
        int judge[maxn] = {};
        for (i = 0; i < n; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cin >> a[i][j];
            }
        }
        for (int i = 0; i < n; i++)
        {
            int choose = 0;
            for (int j = 0; j < 3; j++)
            {
                if (a[i][j] > dp[i])
                {
                    dp[i] = a[i][j];
                    choose = j;
                }
            }
            judge[i] = choose;
            r[choose]++;
        }
        for (int i = 0; i < n; i++)
        {
            ans += dp[i];
        }
        for (int j = 0; j < 3; j++)
        {
            if (r[j] > range)
            {
                vector<int> temp(r[j]);
                int cnt = 0;
                for (int i = 0; i < n; i++)
                {
                    if (judge[i] != j)
                    {
                        continue;
                    }
                    temp[cnt] = 0x3f3f3f3f;
                    for (int j_ = 0; j_ < 3; j_++)
                    {
                        if (j_ != judge[i])
                        {
                            temp[cnt] = min(temp[cnt], dp[i] - a[i][j_]);
                        }
                    }
                    cnt++;
                }
                sort(temp.begin(), temp.end());
                cnt = 0;
                while (r[j] > range)
                {
                    ans -= temp[cnt];
                    r[j]--;
                    cnt++;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}