#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    int n = 0, b[1000000], k = 0, l = 0;
    string s;
    cin >> s;
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == '1' || s[i] == '2' || s[i] == '3' || s[i] == '4' || s[i] == '5' || s[i] == '6' || s[i] == '7' || s[i] == '8' || s[i] == '9')
        {
            a[n] = s[i];
            n++;
        }
    }
    sort(a, a + n + 1);
    for(int i = n; i > 0; i--)
    {
        b[k] = a[i];
        k++;
    }
    if(n == 1)
    {
        cout << s[n];
    }
    for(int i = 0; i < n; i++)
    {
        cout << b[i];
    }
    return 0;
}
