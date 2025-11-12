#include <bits/stdc++.h>
using namespace std;
vector <int> clubs[3];
int t, n, a[(int)1e5+3][3], s[3][(int)(1e5+3)];
long ans;
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 3; j++)
                cin >> a[i][j];
            if (a[i][0] >= a[i][1] && a[i][0] >= a[i][2])
            {
                if (clubs[0].size()+1 > n/2)
                {
                    long t = -(1e8), b;
                    for (int i = 0; i < clubs[0].size(); i++)
                    {
                        int temp = max(a[i][1], a[i][2]) - a[i][0];
                        if (temp > t)
                        {
                            t = temp;
                            b = i;
                        }
                    }
                    ans += t + a[i][0];
                    clubs[0][b] = i;
                }
                else
                {
                    ans += a[i][0];
                    clubs[0].push_back(i);
                }
            }
            else if (a[i][1] >= a[i][2])
            {
                if (clubs[1].size()+1 > n/2)
                {
                    long t = -(1e8), b;
                    for (int i = 0; i < clubs[1].size(); i++)
                    {
                        int temp = max(a[i][0], a[i][2]) - a[i][1];
                        if (temp > t)
                        {
                            t = temp;
                            b = i;
                        }
                    }
                    ans += t + a[i][1];
                    clubs[1][b] = i;
                }
                else
                {
                    ans += a[i][1];
                    clubs[1].push_back(i);
                }
            }
            else
            {
                if (clubs[2].size()+1 > n/2)
                {
                    long t = -(1e8), b;
                    for (int i = 0; i < clubs[2].size(); i++)
                    {
                        int temp = max(a[i][1], a[i][0]) - a[i][2];
                        if (temp > t)
                        {
                            t = temp;
                            b = i;
                        }
                    }
                    ans += t + a[i][2];
                    clubs[2][b] = i;
                }
                else
                {
                    ans += a[i][2];
                    clubs[2].push_back(i);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
