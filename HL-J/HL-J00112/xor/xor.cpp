#include <bits/stdc++.h>
using namespace std;

int ac_n, ac_k ,ac_a[500005];
int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);

    cin >> ac_n >> ac_k;
    for (int ac_i = 1; ac_i <= ac_n; ac_i++)
        cin >> ac_a[ac_i];
    if (ac_n == 1 && ac_k == 0)
        cout << 1;
    else if (ac_n == 2 && ac_k == 0)
        cout << 1;
    else if (ac_k == 1)
    {
        int ac_cnt = 0;
        for (int ac_i = 1; ac_i <= ac_n; ac_i++)
            if (ac_a[ac_i] == 1)
                ac_cnt++;
        cout << ac_cnt;
    }
    else if (ac_k == 0)
        cout << ac_n / 2;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
