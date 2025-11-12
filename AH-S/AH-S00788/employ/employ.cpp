#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353
int n, m;
char s[501] = {0};
int c[501] = {0};
int flag[501] = {0};
int sum1 = 0;
int ans = 0;
long long f_ans = 0;
void dfs(int id)
{
    if (id == n+1)
    {
        if (ans >= m)
            f_ans = (f_ans + 1) % MOD;
    }
    for (int i=1;i<=n;i++)
    {
        if (flag[i] == 0)
        {
            flag[i] = 1;
            if (sum1 >= c[i] || s[id-1] == '0')
                sum1++;
            else
                ans++;
            dfs(id+1);
            flag[i] = 0;
            if (sum1-1 >= c[i] || s[id-1] == '0')
                sum1--;
            else
                ans--;
        }
    }
}
int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m >> s;
    for (int i=1;i<=n;i++)
        cin >> c[i];
    dfs(1);
    cout << f_ans;
}
