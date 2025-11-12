#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);

    string a, ns;
    cin >> a;
    sort(a.begin(), a.end());

    for (int i = a.size() - 1; i >= 0; i--)
    {
        if (isdigit(a[i]))
        {
            ns += a[i];
        }
    }

    cout << ns;
    return 0;
}
