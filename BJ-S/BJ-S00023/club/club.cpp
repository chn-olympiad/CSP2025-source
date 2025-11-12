#include <bits/stdc++.h>
using namespace std;

priority_queue <int, vector<int>, greater<int> > q[4];
int a[100010][4];

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--)
    {
        while (!q[1].empty()) q[1].pop();
        while (!q[2].empty()) q[2].pop();
        while (!q[3].empty()) q[3].pop();
        int n, cnt1 = 0, cnt2 = 0, cnt3 = 0, ans = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d%d%d", &a[i][1], &a[i][2], &a[i][3]);
            if (a[i][1] >= max(a[i][2], a[i][3]))
            {
                cnt1++;
                q[1].push(a[i][1] - max(a[i][2], a[i][3]));
                ans += a[i][1];
            }
            else if (a[i][2] >= a[i][3])
            {
                cnt2++;
                q[2].push(a[i][2] - max(a[i][1], a[i][3]));
                ans += a[i][2];
            }
            else
            {
                cnt3++;
                q[3].push(a[i][3] - max(a[i][1], a[i][2]));
                ans += a[i][3];
            }
        }
        while (cnt1 > n / 2)
        {
            ans -= q[1].top();
            q[1].pop();
            cnt1--;
        }
        while (cnt2 > n / 2)
        {
            ans -= q[2].top();
            q[2].pop();
            cnt2--;
        }
        while (cnt3 > n / 2)
        {
            ans -= q[3].top();
            q[3].pop();
            cnt3--;
        }
        printf("%d\n", ans);
    }
    return 0;
}

