#include <bits/stdc++.h>
using namespace std;
const int Nc = 1e5 + 5;
int n, sum, cnt[4], a[Nc][4];
priority_queue<int> q;
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--)
    {
        while (!q.empty()) q.pop();
        scanf("%d", &n);
        cnt[1] = cnt[2] = cnt[3] = sum = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= 3; j++) scanf("%d", &a[i][j]);
            if (a[i][1] >= a[i][2] && a[i][1] >= a[i][3]) cnt[1]++, sum += a[i][1];
            else if (a[i][2] >= a[i][1] && a[i][2] >= a[i][3]) cnt[2]++, sum += a[i][2];
            else if (a[i][3] >= a[i][1] && a[i][3] >= a[i][2]) cnt[3]++, sum += a[i][3];
        }
        if (cnt[1] <= n / 2 && cnt[2] <= n / 2 && cnt[3] <= n / 2)
        {
            printf("%d\n", sum);
            continue;
        }
        int id;
        for (int i = 1; i <= 3; i++)
            if (cnt[i] > n / 2) id = i;
        for (int i = 1; i <= n; i++)
        {
            if (!((a[i][1] >= a[i][2] && a[i][1] >= a[i][3] && id == 1) || (a[i][2] >= a[i][1] && a[i][2] >= a[i][3] && id == 2) || (a[i][3] >= a[i][1] && a[i][3] >= a[i][2] && id == 3))) continue;
            int tmp = 0;
            for (int j = 1; j <= 3; j++)
                if (j != id) tmp = max(tmp, a[i][j]);
            q.push(tmp - a[i][id]);
        }
        for (int i = 1; i <= cnt[id] - n / 2; i++)
        {
            sum += q.top();
            q.pop();
        }
        printf("%d\n", sum);
    }
    return 0;
}
