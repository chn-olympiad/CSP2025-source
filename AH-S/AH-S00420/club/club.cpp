#include <bits/stdc++.h>
using namespace std;
int t, n;
struct node{
    int num;
    int a[3];
};
struct f {
    int a[3];
};
const int N = 1e5 + 10;
f ab[N];
node dp[N][3];
int is(int a, int b, int c)
{
    if (dp[a][b].a[c] > 0) return 1;
    else return 0;
}
bool cmp(f a, f b)
{
    if (a.a[0] > b.a[0]) return true;
    else if (a.a[0] < b.a[0]) return false;
    else{
        if (a.a[1] > b.a[1]) return true;
        else if (a.a[1] < b.a[1]) return false;
        else{
            if (a.a[2] > b.a[2]) return true;
            else if (a.a[2] < b.a[2]) return false;
            else return true;
        }

    }
}
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    while(t--)
    {
        cin >> n;
        for (int i = 1; i <= n; ++i)
        {
            cin >>ab[i].a[0]>> ab[i].a[1] >> ab[i].a[2];
            dp[i][0].num = dp[i][1].num = dp[i][2].num = 0;
        }
        dp[0][0].a[0] = dp[0][0].a[1] = dp[0][0].a[2] = n / 2;
        dp[0][1].a[0] = dp[0][1].a[1] = dp[0][1].a[2] = n / 2;
        dp[0][2].a[0] = dp[0][2].a[1] = dp[0][2].a[2] = n / 2;
        sort(ab + 1, ab + n + 1, cmp);
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                int k1 = dp[i - 1][0].num + ab[i].a[j] * is(i - 1, 0, j);
                int k2 = dp[i - 1][1].num + ab[i].a[j] * is(i - 1, 1 ,j);
                int k3 = dp[i - 1][2].num + ab[i].a[j] * is(i - 1, 2, j);
                if (k1 > k2)
                {
                    if (k1 > k3)
                    {
                        dp[i][j].num = k1;
                        dp[i][j].a[0] = dp[i - 1][0].a[0];
                        dp[i][j].a[1] = dp[i - 1][0].a[1];
                        dp[i][j].a[2] = dp[i - 1][0].a[2];
                        if (dp[i - 1][0].a[j] > 0)
                        {
                            dp[i][j].a[j]--;
                        }
                    }else{
                        dp[i][j].num = k3;
                        dp[i][j].a[0] = dp[i - 1][2].a[0];
                        dp[i][j].a[1] = dp[i - 1][2].a[1];
                        dp[i][j].a[2] = dp[i - 1][2].a[2];
                        if (dp[i - 1][2].a[j] > 0)
                        {
                            dp[i][j].a[j]--;
                        }
                    }
                }else{
                    if (k2 > k3)
                    {
                        dp[i][j].num = k2;
                        dp[i][j].a[0] = dp[i - 1][1].a[0];
                        dp[i][j].a[1] = dp[i - 1][1].a[1];
                        dp[i][j].a[2] = dp[i - 1][1].a[2];
                        if (dp[i - 1][1].a[j] > 0)
                        {
                            dp[i][j].a[j]--;
                        }
                    }else{
                        dp[i][j].num = k3;
                        dp[i][j].a[0] = dp[i - 1][2].a[0];
                        dp[i][j].a[1] = dp[i - 1][2].a[1];
                        dp[i][j].a[2] = dp[i - 1][2].a[2];
                        if (dp[i - 1][2].a[j] > 0)
                        {
                            dp[i][j].a[j]--;
                        }
                    }
                }
            }
        }
        cout << max(dp[n][0].num, max(dp[n][1].num, dp[n][2].num));
    }
    return 0;
}
