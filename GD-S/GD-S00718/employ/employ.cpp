#include <bits/stdc++.h>
using namespace std;
const int N = 501;
int n, m, cnt;
int c[N], a[N];
string s;
bool vis[N];
int fact(int n)
{
	long long ans = 1;
	for (int i = 1; i <= n; i++)
		ans = (ans * i) % 998244353;
	return ans;
}
void dfs(int step)
{
    if (step > n)
    {
        int emp = 0, person = 0;
        for (int i = 1; i <= n; i++)
        {
            if (person >= a[i] || s[i] == '0')
            {
                person++;
                continue;
            }
            if (++emp >= m)
            {
                cnt = (cnt + 1) % 998244353;
                break;
            }
        }
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
            continue;
        a[step] = c[i];
        vis[i] = 1;
        dfs(step + 1);
        a[step] = 0;
        vis[i] = 0;
    }
    return;
}
int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m >> s;
    s = ' ' + s;
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    dfs(1);
    cout << cnt << endl;
    return 0;
}
