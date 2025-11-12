#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n, ans = 0;
vector<bool>vis;
vector<int>a, temp;
bool check(vector<int>& temp)
{
    long long tot = 0;
    int maxn = INT_MIN;
    for (auto x : temp) {
        tot += a[x];
        maxn = max(maxn, a[x]);
    }
    return tot > 2 * maxn;
}
void dfs(int bri, int id)
{
    if(int(temp.size()) == bri) {
        if(check(temp)) {
            ans = (ans + 1) % mod;
        }
        return;
    }
    for (int i = id; i <= n; i++)
    {
        if(!vis[i])
        {
            temp.push_back(i);
            vis[i] = true;
            dfs(bri, i);
            temp.pop_back();
            vis[i] = false;
        }
    }
}
int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    bool flag = true;
    a.resize(n + 1, 0);
    vis.resize(n + 1, false);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if(a[i] != a[1]) flag = false;
    }
    if(flag) {
        cout << n - 2 << endl;
        return 0;
    }
    for (int bri = 3; bri <= n; bri++) dfs(bri, 1);
    cout << ans << endl;
    return 0;
}
/*
g++ -Wall -O2 -std=c++14 -static polygon.cpp -o polygon
*/
