#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll a[5005], n, choose[5005], cnt = 0;

bool chk()
{
    ll sum = 0, maxn = 0;
    for(ll i = 1; i <= n; i ++)
    {
        if(choose[i] == 1)
        {
            sum += a[i];
            maxn = max(maxn, a[i]);
        }
    }
    return sum > (maxn * 2);
}

bool cmp(int x, int y)
{
    return x > y;
}

void dfs(ll st)
{
    if(st > n)
    {
        if(chk())
        {
            cnt ++;
        }
        return ;
    }
    choose[st] = 0;
    dfs(st + 1);
    choose[st] = 1;
    dfs(st + 1);
}

int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    int maxn2 = 0;
    for(ll i = 1; i <= n; i ++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1, cmp);
    dfs(1);
    cout <<  cnt;
    return 0;
}
