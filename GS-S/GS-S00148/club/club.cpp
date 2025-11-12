#include <bits/stdc++.h>
using namespace std;

struct people
{
    int v[3];
    int like[3];
};

bool cmp_people1(people p1, people p2)
{
    return p1.v[p1.like[0]] > p2.v[p2.like[0]];
}
int t0 = 0, t1 = 0, t2 = 0, N = 0, sum1 = 0;
people P[100001];
bool check()
{
    int halfN = N / 2;
    return t0 > halfN || t1 > halfN || t2 > halfN;
}
void method1(int v, int sum)
{
    if (v >= N - 1)
    {
        //last
        t0 += 1;
        if (!check())
        {
            sum1 = max(sum1, sum + P[v].v[0]);
        }
        t0 -= 1;

        t1 += 1;
        if (!check())
        {
            sum1 = max(sum1, sum + P[v].v[1]);
        }
        t1 -= 1;

        t2 += 1;
        if (!check())
        {
            sum1 = max(sum1, sum + P[v].v[2]);
        }
        t2 -= 1;

        return;
    }
    else
    {
        t0 += 1;
        if (!check())
        {
            method1(v + 1, sum + P[v].v[0]);
        }
        t0 -= 1;

        t1 += 1;
        if (!check())
        {
            method1(v + 1, sum + P[v].v[1]);
        }
        t1 -= 1;

        t2 += 1;
        if (!check())
        {
            method1(v + 1, sum + P[v].v[2]);
        }
        t2 -= 1;
    }
    return;
}

int start(unsigned short turn)
{
    // printf("\n-- Test Turn: #%d\n", turn);
    // init vars
    int n = 0;
    cin >> n;
    int halfN = n / 2;
    if (n <= 20)
    {
        // METHOD 1
        // printf("USING METHOD 1\n");
        t0 = 0;
        t1 = 0;
        t2 = 0;
        N = n;
        sum1 = 0;
        for (int i = 0; i < n; i++)
        {
            // read people data
            cin >> P[i].v[0] >> P[i].v[1] >> P[i].v[2];
        }
        method1(0, 0);
        printf("%d\n", sum1);
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            // read people data
            cin >> P[i].v[0] >> P[i].v[1] >> P[i].v[2];
            P[i].like[0] = 0;
            P[i].like[1] = 1;
            P[i].like[2] = 2;
            for (short i1 = 0; i1 < 2; i1++)
            {
                for (short j1 = i1 + 1; j1 < 3; j1++)
                {
                    if (P[i].v[P[i].like[j1]] > P[i].v[P[i].like[i1]])
                        swap(P[i].like[j1], P[i].like[i1]);
                }
            }
        }
        sort(P + 0, P + n, cmp_people1);

        // pre get into clubs
        vector<people> c0, c1, c2; // three clubs

        for (auto &&p : P)
        {
            if (p.like[0] == 0)
            {
                c0.push_back(p);
            }
            else if (p.like[0] == 1)
            {
                c1.push_back(p);
            }
            else
            {
                c2.push_back(p);
            }
        }

        vector<people> dc0, dc1, dc2; //delta cx
        while (c0.size() > halfN)
        {
            people last = c0[c0.size() - 1];
            if (last.like[1] == 1)
            {
                dc1.push_back(last);
            }
            else
            {
                dc2.push_back(last);
            }
            c0.pop_back();
        }
        while (c1.size() > halfN)
        {
            people last = c1[c1.size() - 1];
            if (last.like[1] == 0)
            {
                dc0.push_back(last);
            }
            else
            {
                dc2.push_back(last);
            }
            c1.pop_back();
        }
        while (c2.size() > halfN)
        {
            people last = c2[c2.size() - 1];
            if (last.like[1] == 0)
            {
                dc0.push_back(last);
            }
            else
            {
                dc1.push_back(last);
            }
            c2.pop_back();
        }

        // get sum
        int sum = 0; 
        
        for (auto &&p : c0)
        {
            sum += p.v[0];
        }
        for (auto &&p : c1)
        {
            sum += p.v[1];
        }
        for (auto &&p : c2)
        {
            sum += p.v[2];
        }
        for (auto &&p : dc0)
        {
            sum += p.v[0];
        }
        for (auto &&p : dc1)
        {
            sum += p.v[1];
        }
        for (auto &&p : dc2)
        {
            sum += p.v[2];
        }

        printf("%d\n", sum);
    }
    return 0;
}

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    unsigned short t = 0;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        start(i);
    }

    return 0;
}
