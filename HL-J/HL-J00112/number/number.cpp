#include <bits/stdc++.h>
using namespace std;

int ac_a[1000005];
string ac_s;
int ac_cnt = 0;

bool ac_cmp(int ac_a, int ac_b)
{
    return ac_a > ac_b;
}
int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> ac_s;
    for (int ac_i = 0; ac_i < ac_s.length(); ac_i++)
    {
        if (ac_s[ac_i] >= '0' && ac_s[ac_i] <= '9')
        {
            ac_a[ac_cnt] = ac_s[ac_i] - '0';
            ac_cnt++;
        }
    }
    sort(ac_a, ac_a + ac_cnt, ac_cmp);
    for (int ac_i = 0; ac_i < ac_cnt; ac_i++)
        cout << ac_a[ac_i];

    fclose(stdin);
    fclose(stdout);
    return 0;
}
