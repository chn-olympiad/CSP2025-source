// T3 = 5+5+5+10+5 = 30pts
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int n, k;
int a[N];
int ans = 0;
void dfs(int m, int sum, int cnt)
{
    if(sum == k)
    {
        ans = max(ans, cnt+1);
        dfs(m, 0, cnt+1);
        return;
    }
    else
    {
        for(int i = m+1; i <= n; i++)
        {
            dfs(i, (sum ^ a[i]), cnt);
        }
    }
}
int main()
{
     freopen("xor.in", "r", stdin);
     freopen("xor.out", "w", stdout);
    cin >> n >> k;
    bool all1 = 1, all10 = 1;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if(a[i] != 1)
        {
            if(a[i] != 0)
            {
                all10 = 0;
            }
            all1 = 0;
        }
    }
    if(all1 && k == 0)
    {
        cout << n/2;
        return 0;
    }
    if(all10)
    {
        if(k == 0)
        {
            int ans = 0;
            for(int i = 1; i <= n; i++)
            {
                if(a[i] == 1 && a[i+1] == 1)
                {
                    ans++;
                    i++;
                }
                if(a[i] == 0) ans++;
            }
            cout << ans;
            return 0;
        }
        if(k == 1)
        {
            int ans = 0;
            for(int i = 1; i <= n; i++)
            {
                if(a[i] == 1)
                {
                    ans++;
                }
            }
            cout << ans;
            return 0;
        }
        return 0;
    }
    if(k == 0)
    {
        int ans = 0;
        for(int i = 1; i <= n; i++)
        {
            if(a[i] == a[i+1])
            {
                ans++;
                i++;
            }
            if(a[i] == 0) ans++;
        }
        cout << ans;
        return 0;
    }
    dfs(0, 0, 0);
    cout << ans;
    return 0;
}

//T1 + T2 + T3 + T4 = 100+100+30+36 = 266pts