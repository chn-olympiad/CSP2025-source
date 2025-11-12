#include <bits/stdc++.h>
using namespace std;

int n, a[100010][5], num[4];

long long sum = 0, ans = -1;

vector<int> c[4];

int n1, n2, n3;

bool cmp(int i, int j)
{
    if (a[i][n1] - a[i][n2] != a[j][n1] - a[j][n2]) return a[i][n1] - a[i][n2] > a[j][n1] - a[j][n2];
    return a[i][n3] - a[i][n1] < a[j][n3] - a[j][n1];
}

bool cmp1(int i, int j)
{
    return abs(a[i][1] - a[i][2]) < abs(a[j][1] - a[j][2]);
}

void SORT(int x)
{
    n3 = x;
    if (x == 1) n1 = 2, n2 = 3;
    if (x == 2) n1 = 1, n2 = 3;
    if (x == 3) n1 = 1, n2 = 2;
    sort(c[x].begin(), c[x].end(), cmp);
}

void dfs(int step)
{
    if (step > n)
    {
        if (num[1] <= n / 2 && num[2] <= n / 2 && num[3] <= n / 2)
        {
            ans = max(ans, sum);
        }
        return ;
    }
    num[1]++, sum += a[step][1];
    dfs(step + 1);
    num[1]--, sum -= a[step][1];
    num[2]++, sum += a[step][2];
    dfs(step + 1);
    num[2]--, sum -= a[step][2];
    num[3]++, sum += a[step][3];
    dfs(step + 1);
    num[3]--, sum -= a[step][3];
}

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        num[1] = num[2] = num[3] = 0;
        sum = 0;
        c[1].clear(), c[2].clear(), c[3].clear();
        bool flag = true;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d %d %d", &a[i][1], &a[i][2], &a[i][3]);
            if (a[i][3] != 0) flag = false;
            int M = max(max(a[i][1], a[i][2]), a[i][3]);
            sum += M;
            if (M == a[i][1])
            {
                num[1]++;
                c[1].push_back(i);
            }
            else if (M == a[i][2])
            {
                num[2]++;
                c[2].push_back(i);
            }
            else
            {
                num[3]++;
                c[3].push_back(i);
            }
        }
        if (n <= 10)
        {
            ans = -1, sum = 0, num[1] = num[2] = num[3] = 0;
            dfs(1);
            printf("%lld\n", ans);
            continue;
        }
        if (flag = true)
        {
            if (num[1] <= n / 2 && num[2] <= n / 2 && num[3] <= n / 2)
            {
                printf("%lld\n", sum);
                continue;
            }
            else
            {
                int delta = max(num[1], num[2]) - n / 2;
                if (num[1] > n / 2)
                {
                    sort(c[1].begin(), c[1].end(), cmp1);
                    for (int i = 0; i < delta; i++)
                    {
                        sum -= 1LL * (abs(a[c[1][i]][1] - a[c[1][i]][2]));
                    }
                }
                else
                {
                    sort(c[2].begin(), c[2].end(), cmp1);
                    for (int i = 0; i < delta; i++)
                    {
                        sum -= 1LL * (abs(a[c[2][i]][1] - a[c[2][i]][2]));
                    }
                }
                printf("%lld\n", sum);
            }
            continue;
        }
        if (num[1] <= n / 2 && num[2] <= n / 2 && num[3] <= n / 2)
        {
            printf("%lld\n", sum);
            continue;
        }
        int t;
        if (num[1] > n / 2) t = 1, SORT(1);
        if (num[2] > n / 2) t = 2, SORT(2);
        if (num[3] > n / 2) t = 3, SORT(3);
        long long sum2 = sum;
        int tmp1 = num[n1], tmp2 = num[n2];
        for (int i = c[t].size() - 1; i >= c[t].size() - (num[t] - n / 2); i++)
        {
            int id = c[t][i];
            if (num[n2] < n / 2)
            {
                sum2 -= 1LL * (a[id][t] - a[id][n2]);
                num[n2]++;
            }
            else
            {
                sum2 -= 1LL * (a[id][t] - a[id][n1]);
                num[n1]++;
            }
        }
        num[n1] = tmp1, num[n2] = tmp2;
        for (int i = 0; i < num[t] - n / 2; i++)
        {
            int id = c[t][i];
            if (num[n1] < n / 2)
            {
                sum -= 1LL * (a[id][t] - a[id][n1]);
                num[n1]++;
            }
            else
            {
                sum -= 1LL * (a[id][t] - a[id][n2]);
                num[n2]++;
            }
        }
        printf("%lld\n", max(sum, sum2));
    }
    return 0;
}
