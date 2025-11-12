#include <bits/stdc++.h>
using namespace std;
int t, n[10], a[10][100005][3], maxn[10], cnt[10][3], ans[10], maxans[10];
void dfs(int k, int i)
{
    if(k + 1 > n[i])
    {
        if(ans[i] > maxans[i])
        {
            maxans[i] = ans[i];
        }
        return;
    }
    for(int j = 0; j < 3; j++)
    {
        if(cnt[i][j] < maxn[i])
        {
            ans[i] += a[i][k][j];
            cnt[i][j]++;
            dfs(k + 1, i);
            ans[i] -= a[i][k][j];
            cnt[i][j]--;
        }
    }
}
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin>>t;
    for(int i = 0; i < t; i++)
    {
        cin>>n[i];
        maxn[i] = n[i] / 2;
        for(int j = 0; j < n[i]; j++)
        {
            cin>>a[i][j][0]>>a[i][j][1]>>a[i][j][2];
        }
    }
    for(int i = 0; i < t; i++)
    {
        dfs(0, i);
    }
    for(int i = 0; i < t; i++)
    {
        cout<<maxans[i]<<endl;
    }
    return 0;
}
