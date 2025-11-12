#include <iostream>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int a[100], R[100], ans = 0, Rn = 0, Rm = 0;
    for (int i = 1;i <= n * m;i++)
    {
        cin >> a[i];
    }
    for (int i = 1;i <= n * m;i++)
    {
        if (a[1] < a[i])
        {
            ans += 1;
        }
    }
    if ((ans + 1) % n == 0)
    {
        Rn = (ans + 1) / n;
        Rm = n;
    }
    else
    {
        Rn = (ans + 1) / n + 1;
        Rm = ans + 1 - (Rn - 1) * n;
    }
    cout << Rn << " " << Rm;
    return 0;
}
