#include<bits/stdc++.h>
using namespace std;
int n, m;
int c[505];
string s;
int str[505];
bool check()
{
    //cout << "ok";
    for (int i = 1; i <= n; i++)
    {
        if (str[i] != 1) return 0;
        //cout << "ok" << ' ';
    }
    //cout << endl;
    return 1;
}

long long A(int x, int y)
{
    long long mul = 1;
    for (int i = x; i >= x - y + 1; i--)
    {
        mul = mul * i % 998244353;
    }
    return mul;
}

long long ans = 0;
int newc[505];

bool check2()
{
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (str[i] == 0) continue;
        else
        {
            int cnt0 = 0;
            for (int j = 1; j < i; j++)
            {
                //cout << i << 'a' << j << endl;
                if (str[j] == 0 ) cnt0++;
            }
            //cout << newc[i] << ' ' << cnt0 << endl;
            if (newc[i] > cnt0) cnt++;
        }
    }
    if (cnt >= m) return 1;
    return 0;
}

bool vis[505];

void dfs(int now)
{
    if (now > n)
    {
        if(check2())
        {
            ans++;
        }
        return ;
    }
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] != 1)
        {
            vis[i] = 1;
            newc[i] = c[now];
            dfs(now + 1);
            vis[i] = 0;
            newc[i] = 0;
        }
    }
}

int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        str[i + 1] = s[i] - '0';
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    if (check())
    {
        //cout << "haha";
        cout << A(n, n);
    }
    else
    {
        //cout << "haha";
        dfs(1);
        cout << ans;
    }
    return 0;
}
