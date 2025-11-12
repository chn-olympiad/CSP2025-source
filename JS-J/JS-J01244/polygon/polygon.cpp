#include<bits/stdc++.h>
using namespace std;
int a[5005], ans[5005], num;
bool flag[5005];
int n;
void dfs(int m, int k, int la)
{
    if(k == m + 1)
    {
        int maxx = 0, sum = 0;
        for(int i = 1;i <= m;i++)
        {
            sum += ans[i];
            maxx = max(maxx, ans[i]);
        }
        if(sum > maxx * 2)
        {
            num++;
        }
        return;
    }
    flag[la] = true;
    for(int i = la;i <= n;i++)
    {
        if(flag[i] == false)
        {
            ans[k] = a[i];
            dfs(m, k + 1, i);
        }
    }
    flag[la] = false;
}
int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin>>n;
    for(int i = 1;i <= n;i++)
    {
        cin>>a[i];
    }
    for(int i = 3;i <= n;i++)
    {
        memset(flag, false,sizeof(flag));
        dfs(i, 1, 0);
    }
    cout<<num % 998244353;
    return 0;
}
