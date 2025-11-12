#include<iostream>
#include<vector>
using namespace std;
long long mod = 998244353;
bool flag[5005];
long long a[5005];
int n, num = 0;
void dfs(int u)
{
    if(u > n) return;
    long long mx = -1, ans = 0, cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        if(flag[i] == 1)
        {
            mx = max(mx, a[i]);
            ans += a[i];
            cnt++;
        }
    }
    if(ans > 2 * mx && cnt >= 3 && flag[u] != 0)
    {
        num++;
        num %= mod;
    }
    flag[u + 1] = 1;
    dfs(u + 1);
    flag[u + 1] = 0;
    dfs(u + 1);
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
    dfs(0);
    cout << num % mod << endl;
    return 0;
}
