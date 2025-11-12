#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int a1, a2, a3;
};
bool comp1(Node v1, Node v2)
{
    return v1.a1 > v2.a1;
}
int n;
Node a[100001] = {0};
int maxx = -1;
int ans = 0;
int flag[4] = {0};
void dfs(int id)
{
    if (id == n+1)
        maxx = max(maxx, ans);
    for (int i=1;i<=3;i++)
    {
        if (i == 1 && flag[1] < n / 2)
        {
            flag[1]++;
            ans += a[id].a1;
            dfs(id+1);
            ans -= a[id].a1;
            flag[1]--;
        }
        else if (i == 2 && flag[2] < n / 2)
        {
            flag[2]++;
            ans += a[id].a2;
            dfs(id+1);
            ans -= a[id].a2;
            flag[2]--;
        }
        else if (i == 3 && flag[3] < n / 2)
        {
            flag[3]++;
            ans += a[id].a3;
            dfs(id+1);
            ans -= a[id].a3;
            flag[3]--;
        }
    }
}
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        bool f = 0;
        for (int i=1;i<=n;i++)
        {
            cin >> a[i].a1 >> a[i].a2 >> a[i].a3;
            if (a[i].a2 != 0 || a[i].a3 != 0)
                f = 1;
        }

        if (n <= 10)
        {
            ans = 0;
            maxx = 0;
            dfs(1);
            cout << maxx << endl;
        }
        else if (f == 0)
        {
            sort(a+1, a+n+1, comp1);
            for (int i=1;i<=n/2;i++)
                ans += a[i].a1;
            cout << ans << endl;
        }

    }
}
