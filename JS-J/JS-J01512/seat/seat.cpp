#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
#define endl "\n"
using namespace std;

vector<int> v;

signed main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int t;
            cin >> t;
            v.push_back(t);
        }
    }
    int r = v[0];
    sort(v.begin(), v.end(), greater<int>());
    int l = 0;
    for (int j = 0; j < m; j++)
    {
        int flag = -1;
        if ((j & 1) == 0)
        {
            for (int i = 0; i < n; i++)
            {
                if (v[l] == r)
                {
                    flag = i;
                    break;
                }
                l++;
            }
        }
        else
        {
            for (int i = n - 1; i >= 0; i--)
            {
                if (v[l] == r)
                {
                    flag = i;
                    break;
                }
                l++;
            }
        }
        if (flag != -1)
        {
            cout << j + 1 << " " << flag + 1 << endl;
            break;
        }
    }
    return 0;
}