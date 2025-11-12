#include <bits/stdc++.h>
using namespace std;
int t, n;
struct node
{
    int a1, a2, a3;
    bool out1, out2, out3;
    int now, order[6] = {0, 0, 0, 0, 0, 0};
    node()
    {
        now = a1 = a2 = a3 = 0;
        out1 = out2 = out3 = 0;
    }
};
vector<node> a1, a2, a3;
long long sum = 0;
bool cmpa1(const node a, const node b)
{
    return a.a1 < b.a1;
}
bool cmpa2(const node a, const node b)
{
    return a.a2 < b.a2;
}
bool cmpa3(const node a, const node b)
{
    return a.a3 < b.a3;
}
void choose(node a)
{
    if (a.a1 >= a.a2)
    {
        if (a.a1 >= a.a3)
        {
            a1.push_back(a);
            sum += a.a1;
        }
        else
        {
            a3.push_back(a);
            sum += a.a3;
        }
    }
    else
    {
        if (a.a2 >= a.a3)
        {
            a2.push_back(a);
            sum += a.a2;
        }
        else
        {
            a3.push_back(a);
            sum += a.a3;
        }
    }
}
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--)
    {
        a1.clear(), a2.clear(), a3.clear();
        cin >> n;
        sum = 0;
        for (int i = 1; i <= n; i++)
        {
            node t;
            cin >> t.a1 >> t.a2 >> t.a3;
            pair<int, int> a[6];
            for (int i = 0; i < 6; i++)
            {
                a[i].first = i;
            }
            choose(t);
        }
        while (true)
        {
            bool flag = false;
            if (a1.size() > n / 2)
            {
                flag = true;
                sort(a1.begin(), a1.end(), cmpa1);
                for (auto it = a1.begin(); it != a1.end(); it++)
                {
                    if (a1.size() <= n / 2)
                    {
                        break;
                    }
                    it->out1 = true;
                    if (it->a2 >= it->a3 && !it->a2)
                    {
                        sum += it->a2;
                        a2.push_back(*it);
                    }
                    else
                    {
                        sum += it->a3;
                        a3.push_back(*it);
                    }
                    sum -= it->a1;
                    it = a1.erase(it);
                    a1.erase(it);
                }
            }
            if (a2.size() > n / 2)
            {
                sort(a2.begin(), a2.end(), cmpa2);
                flag = true;
                for (auto it = a2.begin(); it != a2.end();)
                {
                    if (a2.size() <= n / 2)
                    {
                        break;
                    }
                    it->out2 = true;
                    if (it->a1 >= it->a3 && !it->a1)
                    {
                        sum += it->a1;
                        a1.push_back(*it);
                    }
                    else
                    {
                        sum += it->a3;
                        a3.push_back(*it);
                    }
                    sum -= it->a2;
                    it = a2.erase(it);
                }
            }
            if (a3.size() > n / 2)
            {
                sort(a3.begin(), a3.end(), cmpa3);
                flag = true;
                for (auto it = a3.begin(); it != a3.end();)
                {
                    if (a3.size() <= n / 2)
                    {
                        break;
                    }
                    it->out3 = true;
                    if (it->a1 >= it->a2 && !it->a1)
                    {
                        sum += it->a1;
                        a1.push_back(*it);
                    }
                    else
                    {
                        sum += it->a2;
                        a2.push_back(*it);
                    }
                    sum -= it->a3;
                    it = a3.erase(it);
                }
            }
            if (!flag)
            {
                break;
            }
        }
        cout << sum << '\n';
    }
}
