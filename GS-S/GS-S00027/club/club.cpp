#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
struct node
{
    vector<int> s;
    map<int, int> ha;
    bool join;
};
vector<int> res;
bool cmp(int a, int b)
{
    return a >= b;
}
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    res.push_back(0);
    int t, n;
    cin >> t;
    for (int now = 1; now <= t; now++)
    {
        node a[N];
        cin >> n;
        if (n == 2)
        {
            int ans = 0;
            int haha[5][5];
            //input
            for (int i = 1; i <= 2; i++)
            {
                cin >> haha[i][1] >> haha[i][2] >> haha[i][3];
            }
            for (int i = 1; i <= 3; i++)
            {
                for (int j = 1; j <= 3; j++)
                {
                    if (j == i)
                        continue;
                    ans = max(ans, haha[1][i] + haha[2][j]);
                }
            }
            res.push_back(ans);
        }
    }
    for (int now = 1; now <= t; now++)
    {
        cout << res[now] << endl;
    }
    return 0;
}