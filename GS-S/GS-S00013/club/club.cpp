#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct Node
{
    int num, loc;
};

int nub[100005][4], t, cl[4], ostr;

int main()
{
    //freopen("club.in", "r", stdin);
    //freopen("club.out", "w", stdout);
    cin >> t;
    while(t--)
    {
        int n = 0, ans = 0;
        memset(cl, 0, sizeof(cl));
        memset(nub, 0, sizeof(nub));
        cin >> n;
        if(n == 2)
        {
            for(int i = 1; i <= n; i++)
            {
                for(int j = 1; j <= 3; j++)
                {
                    cin >> nub[i][j];
                }
            }
            for(int i = 1; i <= 3; i++)
            {
                for(int j = 1; j <= 3; j++)
                {
                    if(j == i)
                    {
                        continue;
                    }
                    ans = max(ans, nub[1][i] + nub[2][j]);
                }
            }
            cout << ans;
            continue;
        }
        if(n ==4)
        {
            int ans1 = 0, ans2 = 0, ans3 = 0;
            for(int i = 1; i <= n; i++)
            {
                for(int j = 1; j <= 3; j++)
                {
                    cin >> nub[i][j];
                }
            }
            for(int i = 1; i <= 3; i++)
            {
                for(int j = 1; j <= 3; j++)
                {
                    for(int k = 1; k <= 3; k++)
                    {
                        for(int l = 1; l <= 3; l++)
                        {
                            ans = max(ans, max(nub[1][i] + nub[2][j], max(nub[1][i] + nub[3][k], max(nub[1][i] + nub[4][l], max(nub[2][j] + nub[3][k], max(nub[2][j] + nub[4][l], nub[3][k] + nub[4][l]))))));
                        }
                    }
                }
            }
            cout << ans;
            continue;
        }
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= 3; j++)
            {
                cin >> nub[i][j];
            }
        }
        if(nub[1][2] == 0 && nub[1][3] == 0)
        {
            int g[100005];
            memset(g, 0, sizeof(g));
            for(int i = 1; i <= n; i++)
            {
                g[i] = nub[i][1];
            }
            sort(g + 1, g + n + 1);
            for(int i = n; i >= n / 2; i--)
            {
                ans += g[i];
            }
            cout << ans;
            continue;
        }
        for(int i = 1; i <= n; i++)
        {
            if(nub[i][1] < nub[i][2])
            {
                if(cl[2] < n / 2)
                {
                    cl[2]++;
                    ans += nub[i][2];
                    ostr = nub[i][2];
                }
            }
            else
            {
                if(cl[1] < n / 2)
                {
                    cl[1]++;
                    ans += nub[i][1];
                    ostr = nub[i][2];
                }
            }
        }
        cout << ans;
    }
    return 0;
}
