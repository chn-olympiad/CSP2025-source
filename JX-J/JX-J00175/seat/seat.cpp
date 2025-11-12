#include <bits/stdc++.h>
using namespace std;

struct info
{
    int id;
    int s;
};

const int MAXN = 15;
const int MAXM = 15;

int n, m;
int sum_people;
info score[MAXN * MAXM];
info arr_seat[MAXN][MAXM];

bool cmp(info a, info b)
{
    return a.s > b.s;
}

int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    scanf("%d%d", &n, &m);

    sum_people = n * m;

    for (int i = 1, x; i <= sum_people; ++i)
    {
        scanf("%d", &x);
        score[i].s = x;
        score[i].id = i;
    }

    sort(score + 1, score + 1 + sum_people, cmp);
    int idx_id1;
    for (int i = 1; i <= sum_people; ++i)
    {
        if (score[i].id == 1)
        {
            idx_id1 = i;
        }
    }
    int idx_j = ceil(idx_id1 * 1.0 / n);
    printf("%d ", idx_j);
    int idx_i = 0;
    if (idx_j % 2 == 1)
    {
        if (idx_id1 % n == 0)
        {
            idx_i = n;
        }
        else
        {
            idx_i = idx_id1 % n;
        }
    }
    else
    {
        if (idx_id1 % n == 0)
        {
            idx_i = 1;
        }
        else
        {
            idx_i = n - idx_id1 % n + 1;
        }
    }
    printf("%d", idx_i);

    return 0;
}
