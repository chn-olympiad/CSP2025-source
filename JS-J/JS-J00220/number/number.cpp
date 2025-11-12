#include<bits/stdc++.h>
using namespace std;
string s, a;
int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < s.size(); i++)
        if (s[i] >= '0' && s[i] <= '9')
            a[++cnt] = s[i];
    for (int i = 0; i <= cnt; i++)
    {
        for (int j = 0; j < i; j++)
            if (a[i] > a[j])
                swap(a[i], a[j]);
    }
    for (int i = 0; i <= cnt; i++)
        cout << a[i];

    return 0;
}
