#include <iostream>
using namespace std;

int n, k, a[500010], ans;
bool f = false;

int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        f += (a[i] == 1);
    }
    if (k <= 1 && f == true)
    {
        if (k == 0)
        {
            for (int i = 1; i <= n; i++)
            {
                if (a[i] == 0)
                    ans++;
                else
                {
                    int j = i + 1;
                    while (a[j] == 0)
                        j++;
                    i = j;
                    ans++;
                }
            }
            cout << ans << endl;
        }
        else
        {
            for (int i = 1; i <= n; i++)
            {
                if (a[i] == 1)
                    ans++;
                else
                {
                    int j = i + 1;
                    while (a[j] == 1)
                        j++;
                    i = j;
                    ans++;
                }
            }
            cout << ans << endl;
        }
    }
    else if (k == 0 && f == false)
    {
        if (n % 2 == 0)
            cout << n / 2 << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}
