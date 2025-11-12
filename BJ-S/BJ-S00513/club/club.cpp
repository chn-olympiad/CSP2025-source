#include<bits/stdc++.h>

using namespace std;

int t;
struct My
{
    int a, b, c;
};

My myd[100010];

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    cin >> t;

    for(int i = 1; i <= t; i++)
    {
        int n;
        int sum = 0;
        bool checka = true;
        int ca[100010];
        int c = 1;
        cin >> n;
        memset(myd, n, 0);

        for(int j = 1; j <= n; j++)
        {
            cin >> myd[j].a;
            cin >> myd[j].b;
            cin >> myd[j].c;
            if(myd[j].b != 0 || myd[j].c != 0)
            {
                checka == false;
            }
            ca[j] = myd[j].a;
        }

        if(n == 2)
        {
            sum = max(myd[1].a + myd[2].b,
                      max(myd[1].a + myd[2].c,
                          max(myd[1].b + myd[2].a,
                              max(myd[1].b + myd[2].c,
                                  max(myd[1].c + myd[2].a, myd[1].c + myd[2].b)))));
            cout << sum;
            continue;
        }

        if(checka == true)
        {
            sort(ca + 1, ca + n + 1);
            for(int i = n; i > n / 2; i--)
            {
                sum += ca[i];
            }
            cout << sum;
            continue;
        }
    }

    return 0;
}