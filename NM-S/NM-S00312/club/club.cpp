#include <bits/stdc++.h>

using namespace std;

long long dfs(vector<vector<int>> &man, map<int, int> used, int high, int n)
{
    if (high > n)
    {
        return 0;
    }
    long long ans = 0;
    for (int i = 1; i <= 3; i++)
    {
        if (used[i] < n / 2)
        {
            used[i]++;
            ans = max(ans, dfs(man, used, high + 1, n) + man[high][i]);
            used[i]--;
        }
    }
    return ans;
}

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out","w",stdout);

    int T = 0;
    cin >> T;

    for (int _ = 0; _ < T; _++)
    {
        int n = 0;
        cin >> n;

        vector<vector<int>> man(n + 1, vector<int>(4));

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= 3; j++)
            {
                cin >> man[i][j];
            }
        }

        map<int, int> used;
        cout << dfs(man, used, 1, n) << endl;

        // vector<vector<point>> man(n, vector<point>(4));
        // map<int, int> used;
        // for (int i = 0; i < n; i++)
        // {
        //     cin >> man[i][1].zhi >> man[i][2].zhi >> man[i][3].zhi;
        //     man[i][1].index = 1;
        //     man[i][2].index = 2;
        //     man[i][3].index = 3;

        //     sort(man[i].begin() + 1, man[i].end(), fun);
        //     // cin >> man[i].to_1 >> man[i].to_2 >> man[i].to_3;
        //     // man[i].best = max(man[i].best, man[i].to_1);
        //     // man[i].best = max(man[i].best, man[i].to_2);
        //     // man[i].best = max(man[i].best, man[i].to_3);
        // }

        // sort(man.begin(), man.end(), fun1);

        // int ans = 0;
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 1; j <= 3; j++)
        //     {
        //         if (used[man[i][j].index] < n / 2)
        //         {
        //             ans +=man[i][j].zhi;
        //             used[man[i][j].index]++;
        //             break;
        //         }
        //     }
        // }

        // cout<<ans<<endl;
    }

    return 0;
}