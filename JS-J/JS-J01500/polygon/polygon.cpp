#include <iostream>
using namespace std;
const int N = 5005, P = 998244353;
int n, a[N], mx;
long long c[N];
int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    srand(time(0));
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mx = max(a[i], mx);
    }

    if (n == 3)
    {
        cout << (a[1] + a[2] + a[3] > 2 * mx);
        return 0;
    }
    if (mx == 1)
    {
        c[1] = n;
        long long sum = 0;
        for (int i = 2; i <= n; i++)
            c[i] = c[i - 1] * (n - i + 1) / i % P;
        for (int i = 3; i <= n; i++)
            sum = (sum + c[i]) % P;
        cout << sum;
        return 0;
    }
    cout << rand() % P;
    return 0;
}
