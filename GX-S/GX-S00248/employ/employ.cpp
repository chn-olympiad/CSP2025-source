#include <iostream>
#include <map>
#include <fstream>

using namespace std;

int n, m, c[501], que[501];
bool vis[501];
bool dd[501];
map<int, int> unused;
map<string, int> ma;

int dfs (int dep, int ac, int wa)
{
    if (dep == n)
        return ac >= m;
    string id = to_string(dep) + "c" + to_string(wa) + "d" + to_string(ac);
    for (auto it = unused.begin(); it != unused.end(); it++)
    {
        id = id + "a" + to_string(it -> first) + "b" + to_string(it -> second);
    }
    if (ma.find(id) != ma.end())
        return ma[id];
    if (ac >= m)
    {
        int sum = 1;
        for (int i = 2; i <= n - dep; i++)
            sum *= i;
        return ma[id] = sum;
        //return sum;
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            vis[i] = 1;
            que[dep] = c[i];
            unused[c[i]]--;
            if (wa >= que[dep] || !dd[dep])
                sum += dfs(dep + 1, ac, wa + 1);
            else if (dd[dep])
                sum += dfs(dep + 1, ac + 1, wa);
            vis[i] = 0;
            unused[c[i]]++;
        }
    }
    return (ac >= m) ? (ma[id] = sum) : sum;
    //return sum;
}

int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        char ccccc;
        cin >> ccccc;
        dd[i] = bool(ccccc - '0');
    }
    for (int i = 0; i < n; i++)
        cin >> c[i];
    for (int i = 0; i < n; i++)
        unused[c[i]]++;
    cout << dfs(0, 0, 0);
    return 0;
}
