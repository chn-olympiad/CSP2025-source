#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5010;
const long long MOD = 998244353;

int n;
int arr[MAXN];
bool vis[MAXN] = {};
int goal = 0;
long long ans = 0;

vector<int> path;

void dfs1(int cnt, int sum, int maxn, int idx)
{
    if (cnt == goal)
    {
        if (sum > maxn * 2)
        {
            ans++;
        }
        /*
        for (int i = 0; i < path.size(); i++)
        {
            cout << path[i] << " ";
        }
        cout << endl;
        */
        return;
    }
    for (int i = idx; i <= n; i++)
    {
        if (!vis[i])
        {
            vis[i] = true;
            //path.push_back(arr[i]);
            dfs1(cnt + 1, sum + arr[i], max(maxn, arr[i]), idx + 1);
            //path.pop_back();
            vis[i] = false;
        }
    }
}

int main()
{
    //freopen("polygon.in", "r", stdin);
    //freopen("polygon.out", "w", stdout);

    scanf("%d", &n);

    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &arr[i]);
    }
    sort(arr + 1, arr + 1 + n);
    for (int i = 3; i <= n; i++)
    {
        goal = i;
        for (int i = 0; i <= n + 10; i++)
        {
            vis[i] = false;
        }
        dfs1(0, 0, 0, 1);
        //cout << endl;
    }

    printf("%lld", ans % MOD);

    return 0;
}
