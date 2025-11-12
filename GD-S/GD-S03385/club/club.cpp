#include <iostream>
#include <algorithm>
#include <queue>
#define MAXN 100015
using std::cin;
using std::cout;
using std::greater;
using std::ios;
using std::priority_queue;
using std::vector;
using std::max;

struct Person
{
    int which;
    int a[5];
    bool operator>(const Person &p) const
    {
        return a[which] > p.a[p.which];
    }
    bool operator<(const Person &p) const
    {
        return a[which] < p.a[p.which];
    }
} people[MAXN];

int n;
int cnt[5];
int ans = 0;
priority_queue<Person, vector<Person>, greater<Person>> pq;

void solve()
{
    ans = 0;
    cnt[1] = cnt[2] = cnt[3] = 0;

    for (int i = 0; i < n; i++)
    {
        int &which = people[i].which;
        which = 1;
        for (int j = 1; j <= 3; j++)
        {
            cin >> people[i].a[j];
            if (people[i].a[which] < people[i].a[j])
            {
                which = j;
            }
        }
        cnt[which]++;
        ans += people[i].a[which];
    }

    int invaild = 0;
    for (int i = 1; i <= 3; i++)
    {
        if (cnt[i] > n / 2)
        {
            invaild = i;
            break;
        }
    }

    if (invaild != 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (people[i].which == invaild)
            {
                pq.push(people[i]);
            }
        }
        // 只会有一组不合法
        while (cnt[invaild] > n / 2)
        {
            Person p = pq.top();
            pq.pop();

            int next = 0;
            for (int i = 1; i <= 3; i++)
            {
                if (i == p.which)
                    continue;
                if (p.a[i] > p.a[next])
                {
                    next = i;
                }
            }
            cnt[invaild]--;
            cnt[next]++;
            ans = ans - p.a[p.which] + p.a[next];
            p.which = next;
        }

        while (!pq.empty())
            pq.pop();
    }

    bool swapable = false;
    do
    {
        swapable = false;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                int group_i = people[i].which;
                int group_j = people[j].which;
                if (group_i == group_j)
                    continue;

                int original = people[i].a[group_i] + people[j].a[group_j];
                int swap_benefit = people[i].a[group_j] + people[j].a[group_i];
                if (original < swap_benefit)
                {
                    ans = ans - original + swap_benefit;
                    people[i].which = group_j;
                    people[j].which = group_i;
                    swapable = true;
                }
            }
        }
    } while (swapable);

    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        solve();
    }
        

    return 0;
}