#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);

    string s;
    int n, a[1000010];

    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (isdigit(s[i]))
        {
            n++;
            a[i] = s[i] - '0';
        }
    }
    sort(a, a + s.size(), greater<int>());
    for (int i = 0; i < n; i++)
        cout << a[i];
    return 0;
}
