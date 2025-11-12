#include <bits/stdc++.h>
using namespace std;
int n;
int a[5005];
bool operator==(vector<int> v1, vector<int> v2)
{
    if(v1.size() != v2.size())
        return false;
    // sort(v1.begin(), v1.end());
    // sort(v2.begin(), v2.end());
    for(int i = 0; i < v1.size(); i++)
    {
        if(v1[i] != v2[i])
            return false;
    }
    return true;
}
set<vector<int>> anss;
void dfs(int sum, int maxn, vector<int> c, int x)
{
    if(2 * maxn < sum && c.size() >= 3)
    {
        anss.insert(c);
        // cerr << "--------------\n";
        // for(int i : c)
        // {
        //     cerr << i << ' ';
        // }
        // cerr << '\n';
        // cerr << maxn << ' ' << sum << '\n';
    }
    for(int i = x + 1; i <= n; i++)
    {
        vector<int> tmp(c);
        tmp.push_back(i);
        dfs(sum + a[i], max(maxn, a[i]), tmp, i);
    }
}
int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    dfs(0, 0, {}, 0);
    cout << anss.size() % 998244353;
    return 0;
}