#include <bits/stdc++.h>
using namespace std;

int ac_n, ac_m, ac_a[10001], ac_r, ac_r_i;

bool ac_cmp(int ac_a, int ac_b)
{
    return ac_a > ac_b;
}

int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    cin >> ac_n >> ac_m;
    int ac_l = ac_n * ac_m;
    for (int ac_i = 1; ac_i <= ac_n * ac_m; ac_i++)
        cin >> ac_a[ac_i];
    ac_r = ac_a[1];
    sort(ac_a + 1, ac_a + ac_l + 1, ac_cmp);

    for (int ac_i = 1; ac_i <= ac_l; ac_i++)
        if (ac_r == ac_a[ac_i])
        {
            ac_r_i = ac_i;
            break;
        }
    int ac_lie = -1;
    if (ac_r_i % ac_n == 0)
        ac_lie = ac_r_i / ac_n;
    else
        ac_lie = ac_r_i / ac_n + 1;
    cout << ac_lie << " ";

    if (ac_lie % 2)
    {
        if (ac_r_i % ac_n)
            cout << (ac_r_i % ac_n);
        else
            cout << ac_n;
    }
    else
    {
        if (ac_r_i % ac_n)
            cout << ac_n + 1 - (ac_r_i % ac_n);
        else
            cout << 1;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
