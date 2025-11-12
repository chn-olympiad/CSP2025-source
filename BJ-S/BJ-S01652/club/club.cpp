#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int NR = 1e5 + 5;

struct node1
{
    int num, id;
};
bool cmp1(node1 a, node1 b)
{
    return a.num < b.num;
}

struct node
{
    node1 x[5];
    int t;
    int sum;

    void f()
    {
        x[1].id = 1;
        x[2].id = 2;
        x[3].id = 3;
        sum = x[1].num + x[2].num + x[3].num;
        t = abs(x[1].num - x[2].num) + abs(x[1].num - x[3].num);
        sort(x + 1, x + 4, cmp1);
    }
};

int n;
long long ans;
node a[NR];
int cnt[5];

bool cmp(node a, node b)
{
    if (a.t == b.t)
    {
        if (a.x[3].num == b.x[3].num)
        {
            if (a.x[2].num == b.x[2].num)
            {
                if (a.x[1].num == b.x[1].num)
                    return a.sum > b.sum;
                return a.x[1].num > b.x[1].num;
            }
            return a.x[2].num > b.x[2].num;
        }
        return a.x[3].num > b.x[3].num;
    }
    return a.t > b.t;
}

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T --)
    {
        cin >> n;

        for (int i = 1;i <= n;i ++)
        {
            cin >> a[i].x[1].num >> a[i].x[2].num >> a[i].x[3].num;
            a[i].f();
            //printf("%d %d %d\n", a[i].x[1].num, a[i].x[2].num, a[i].x[3].num);
        }

        sort(a + 1, a + n + 1, cmp);

        ans = 0;
        cnt[1] = cnt[2] = cnt[3] = 0;
        for (int i = 1;i <= n;i ++)
        {
            for (int j = 3;j >= 1;j --)
            {
                node1 t = a[i].x[j];
                //printf("i:%d j:%d %d\n", i, j, t.num);
                if (cnt[t.id] < n / 2)
                {
                    cnt[t.id] ++;
                    ans += t.num;
                    break;
                }
            }
        }

        cout << ans << '\n';
    }
    return 0;
}
