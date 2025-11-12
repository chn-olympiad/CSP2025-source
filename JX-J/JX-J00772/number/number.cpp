#include <bits/stdc++.h>

using namespace std;


string a;
long long n, k;
long long b[1000005];

int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out","w", stdout);

    cin >> a;

    n = a.size();

    for (int i = 0; i < n; i++)
    {
        if ('0' <= a[i] and a[i] <= '9')
        {
            b[k] = a[i] - '0';
            k++;
        }
    }

    sort(b, b + k);

    for (int i = k - 1; i >= 0; i--)
    {
        cout << b[i];
    }

    return 0;

}
