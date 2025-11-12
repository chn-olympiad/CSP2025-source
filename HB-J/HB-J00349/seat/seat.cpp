#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n = 0;
    int m = 0;
    cin >> n;
    cin >> m;
    int r = 0;
    int pm = 0;
    int wzn = 0;
    int wzm = 0;
    int s[105] = {};
    for (int i = 1; i <= m * n; i ++)
    {
        cin >> s[i];
    }
    r = s[1];
    for (int i = 2; i <= m * n; i ++)
    {
        for (int j = 2; j <= m * n; j ++)
        {
            if (s[j] > s[j - 1])
            {
                swap(s[j], s[j - 1]);
            }
        }
    }
    for (int i = 1; i <= m * n; i ++)
    {
        if (s[i] == r)
        {
            pm = i;
            break;
        }
    }
    if (pm % n == 0)
    {
        wzm = pm / n;
        if ((pm / n) % 2 == 0)
        {
            wzn = 1;
        }
        else
        {
            wzn = n;
        }
    }
    else
    {
        wzm = pm / n + 1;
        if (wzm % 2 == 0)
        {
            wzn = n - (pm % n) + 1;
        }
        else
        {
            wzn = pm % n;
        }
    }
    cout << wzm << " " << wzn << endl;
    return 0;
}
