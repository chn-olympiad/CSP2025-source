#include <bits/stdc++.h>
using namespace std;
struct node
{
    int chos = 0;
    long long a, b, c, a_b, b_c, a_c;
    long long chamax;
}peo[100010];

long long cham[100010];
int cnt1, cnt2, cnt3;
void clear(int n)
{
    cnt1 = cnt2 = cnt3 = 0;
    for (int i = 1; i <= n; ++i)
    {
        cham[i] = peo[i].chos = peo[i].a = peo[i].b = peo[i].c = peo[i].a_b = peo[i].a_c = peo[i].b_c = peo[i].chamax = 0;
    }
}
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        long long sum = 0;
        for (int i = 1; i <= n; ++i)
        {
            cin >> peo[i].a >> peo[i].b >> peo[i].c;
            if (peo[i].a > peo[i].b)
            {
                if (peo[i].c >= peo[i].a)
                {
                    peo[i].chos = 3;
                    ++cnt3;
                }
                else peo[i].chos = 1, ++cnt1;
            }
            else{
                if (peo[i].c > peo[i].b)
                {
                    peo[i].chos = 3, ++cnt3;
                }
                else peo[i].chos = 2, ++cnt2;
            }
            peo[i].a_b = peo[i].a - peo[i].b;
            peo[i].a_c = peo[i].a - peo[i].c;
            peo[i].b_c = peo[i].b - peo[i].c;
            if (peo[i].chos == 1)
            {
                sum += peo[i].a;
                peo[i].chamax = abs((peo[i].b_c > 0) ? peo[i].a_b : peo[i].a_c);
            }
            if (peo[i].chos == 2)
            {
                sum += peo[i].b;
                peo[i].chamax = abs((peo[i].a_c > 0) ? peo[i].a_b : peo[i].b_c);
            }
            if (peo[i].chos == 3)
            {
                sum += peo[i].c;
                peo[i].chamax = abs((peo[i].a_b > 0) ? peo[i].a_c : peo[i].b_c);
            }

        }
        if (cnt1  <= (n >> 1) && cnt2 <= (n >> 1) && cnt3 <= (n >> 1))
        {
            cout << sum << "\n";
            clear(n);
            continue;
        }

        if (cnt1 > (n >> 1))
        {
            int cha = cnt1 - (n >> 1);
            int cnt = 0;
            for (int i = 1; i <= n; ++i)
            {
                if (peo[i].chos == 1)
                {
                    ++cnt;
                    cham[cnt] = peo[i].chamax;
                }
            }
            sort(cham + 1, cham + cnt + 1);
            for (int i = 1; i <= cha; ++i)
            {
                sum -= cham[i];
            }
            cout << sum << "\n";
        }
        else if (cnt2 > (n >> 1))
        {
            int cha = cnt2 - (n >> 1);
            int cnt = 0;
            for (int i = 1; i <= n; ++i)
            {
                if (peo[i].chos == 2)
                {
                    ++cnt;
                    cham[cnt] = peo[i].chamax;
                }
            }
            sort(cham + 1, cham + cnt + 1);
            for (int i = 1; i <= cha; ++i)
            {
                sum -= cham[i];
            }
            cout << sum << "\n";
        }
        else if (cnt3 > (n >> 1))
        {
            int cha = cnt3 - (n >> 1);
            int cnt = 0;
            for (int i = 1; i <= n; ++i)
            {
                if (peo[i].chos == 3)
                {
                    ++cnt;
                    cham[cnt] = peo[i].chamax;
                }
            }
            sort(cham + 1, cham + cnt + 1);
            for (int i = 1; i <= cha; ++i)
            {
                sum -= cham[i];
            }
            cout << sum << "\n";
        }
        clear(n);
    }

    return 0;
}
