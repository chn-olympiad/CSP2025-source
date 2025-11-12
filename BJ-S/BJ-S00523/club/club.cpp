#include <bits/stdc++.h>
using namespace std;

int a[100001][3], b[100001];

int calc(int n, vector<int>& pt, int x, int y, int z)
{
    int m = 0;
    for(int i : pt)
    {
        m++;
        b[m] = min(a[i][x] - a[i][y], a[i][x] - a[i][z]);
    }
    sort(b + 1, b + m + 1);
    int res = 0;
    for(int i = 1;i <= m - (n >> 1);i++)
    {
        res += b[i];
    }
    return res;
}

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        vector<int> cnt[3];
        int res = 0;
        for(int i = 1;i <= n;i++)
        {
            scanf("%d %d %d", &a[i][0], &a[i][1], &a[i][2]);
            int val = max(max(a[i][0], a[i][1]), a[i][2]);
            res += val;
            if(a[i][0] == val)
            {
                cnt[0].push_back(i);
            }
            else if(a[i][1] == val)
            {
                cnt[1].push_back(i);
            }
            else
            {
                cnt[2].push_back(i);
            }
        }
        if(cnt[0].size() >= (n >> 1))
        {
            res -= calc(n, cnt[0], 0, 1, 2);
        }
        else if(cnt[1].size() >= (n >> 1))
        {
            res -= calc(n, cnt[1], 1, 0, 2);
        }
        else if(cnt[2].size() >= (n >> 1))
        {
            res -= calc(n, cnt[2], 2, 1, 0);
        }
        printf("%d\n", res);
    }
    return 0;
}
