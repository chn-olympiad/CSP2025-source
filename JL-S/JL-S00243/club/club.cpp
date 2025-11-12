#include <bits/stdc++.h>
#define int long long

struct want
{
    int id, score;

    bool operator<(const want &a) const
    {
        return score < a.score;
    }

    bool operator>(const want &a) const
    {
        return score > a.score;
    }
};

int num[3];
want tmp[3];

signed main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    int t;
    std::cin >> t;

    while (t --)
    {
        std::priority_queue<want, std::vector<want>, std::greater<want> > cost[3];

        int n;
        std::cin >> n;

        const int maxv = n / 2;

        int result = 0;

        num[0] = 0, num[1] = 0, num[2] = 0;

        for (int i = 0; i < n; i ++)
        {
            std::cin >> tmp[0].score >> tmp[1].score >> tmp[2].score;
            tmp[0].id = 0, tmp[1].id = 1, tmp[2].id = 2;

            std::sort(tmp, tmp + 3);
            std::reverse(tmp, tmp + 3);

            if (num[tmp[0].id] == maxv)
            {
                auto top = cost[tmp[0].id].top();

                if (tmp[0].score >= top.score)
                {
                    result += tmp[0].score - top.score;
                    num[top.id] ++;
                    cost[tmp[0].id].pop();
                    cost[tmp[0].id].push({tmp[1].id, tmp[0].score - tmp[1].score});
                }
                else
                {
                    result += tmp[1].score;
                    num[tmp[1].id] ++;
                    cost[tmp[1].id].push({tmp[2].id, tmp[1].score - tmp[2].score});
                }
            }
            else
            {
                result += tmp[0].score;
                num[tmp[0].id] ++;
                cost[tmp[0].id].push({tmp[1].id, tmp[0].score - tmp[1].score});
            }
        }

        std::cout << result << "\n";
    }

    return 0;
}