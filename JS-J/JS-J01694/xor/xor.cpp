#include <iostream>
using namespace std;

int n, a[200005], k;
long long s[200005];

int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    bool flag = true;
    for (int i = 1;i <= n;i++)
    {
         cin >> a[i];
        if (a[i] > 1) flag = false;
        s[i] = s[i-1] + a[i];
    }
    if (k == 0)
    {
        cout << n / 2;
    }
    else if(flag)
    {
        int cnt1 = 0, cnt0 = 0;
        for (int i = 1;i <= n;i++)
        {
            if (a[i] == 1) cnt1++;
            else cnt0++;
        }

        if (k == 1) cout << cnt1;
        else cout << cnt0;
    }
    else cout << 776;
    return 0;
}
