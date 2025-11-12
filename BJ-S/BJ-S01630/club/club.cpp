#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;
int n;
vector<int> e[5];
signed main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        int sum = 0;
        e[1].clear();
        e[2].clear();
        e[3].clear();
        for(int i = 1; i <= n; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            int mx = max({a, b, c});
            sum += mx;
            if(mx == a) e[1].push_back(min(a - b, a - c));
            else if(mx == b)    e[2].push_back(min(b - a, b - c));
            else    e[3].push_back(min(c - a, c - b));
        }
        for(int i = 1; i <= 3; i++)
        {
            sort(e[i].begin(), e[i].end());
            int res = (int)e[i].size() - (n / 2);
            if(res > 0)
            {
                for(int j = 0; j < res; j++)
                    sum -= e[i][j];
            }
        }
        cout << sum <<endl;
    }
    return 0;
}
