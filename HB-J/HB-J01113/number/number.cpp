#include <bits/stdc++.h>
using namespace std;
string a;
long long c[10];
int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> a;
    for (int i = 0; i < a.size(); ++i)
        if (a[i] >= '0' && a[i] <= '9')
            c[a[i] - '0']++;
    for (int i = 9; i >= 0; --i)
        while (c[i]--)
            cout << i;
    return 0;
}