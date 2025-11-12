#include <algorithm>
#include <cstdio>
#include <vector>
constexpr int MaxN = 1e5 + 5;
int n;
int answer;
int w[MaxN];
int tot[5];
int p[MaxN][5];
std::vector<int> v;
void solve()
{
    v.clear();
    answer = 0;
    tot[1] = tot[2] = tot[3] = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        w[i] = 1;
        for (int j = 1; j <= 3; j++)
        {
            scanf("%d", &p[i][j]);
            if (p[i][j] > p[i][w[i]])
            {
                w[i] = j;
            }
        }
        answer += p[i][w[i]];
        tot[w[i]]++;
    }
    if (std::max(std::max(tot[1], tot[2]), tot[3]) <= n / 2)
    {
        printf("%d\n", answer);
        return;
    }
    int more = 0;
    for (int j = 1; j <= 3; j++)
    {
        if (tot[j] > n / 2)
        {
            more = j;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (w[i] != more)
        {
            continue;
        }
        int better = 0;
        for (int j = 1; j <= 3; j++)
        {
            if (j == more)
            {
                continue;
            }
            better = std::max(better, p[i][j]);
        }
        v.push_back(p[i][w[i]] - better);
    }
    std::sort(v.begin(), v.end());
    int take = tot[more] - n / 2;
    for (int i = 0; i < take; i++)
    {
        answer -= v[i];
    }
    printf("%d\n", answer);
    return;
}
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    return 0;
}
