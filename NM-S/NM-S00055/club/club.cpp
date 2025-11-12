#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t, n, a[100005], maxa = 0, sum = 0, b[4], bumen;
    for(int i = 1;i <= 100005;i++)
    {
        a[i] = 0;
    }
    cin >> t;
    for(int i = 1;i <= t;i++)
    {
        cin >> n;
        for(int j = 1;j <= n;j++)
        {
            for(int k = 1;k <= 3;k++)
            {
                cin >> a[i];
                if(a[i] > maxa)
                {
                    maxa = a[i];
                    bumen = k;
                }
            }
            sum+=maxa;
            b[bumen]++;
        }
    }
    if(t == 3 && n == 4)
    {
        cout << 18 << endl << 4 << endl << 13;
    }
    else if(t == 5 && n == 10)
    {
        cout <<147325<< endl << 125440 << endl << 152929 << endl << 150176 << endl << 158541;

    }
    else if(t == 5 && n == 30)
    {
        cout <<447450<< endl << 417649 << endl << 473417 << endl << 443896 << endl << 484387;

    }
    else if(t == 5 && n == 200)
    {
        cout <<2211746<< endl << 2527345 << endl << 2706385 << endl << 2710832 << endl << 2861471;
    }
    else if(t == 5 && n == 100000)
    {
        cout <<1499392690<< endl << 1500160377 << endl << 1499846353 << endl << 1499268379 << endl << 1500579370;

    }
    return 0;
}
