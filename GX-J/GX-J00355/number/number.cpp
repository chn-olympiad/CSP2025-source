#include <bits/stdc++.h>
using namespace std;
int b[100005];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin >> s;
    string a;
    for (int i = 0;i <= s.size();i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            a += s[i];
        }
    }
    int n = stoi(a);
    int i = 0;
    while (n > 0)
    {
        i++;
        b[i] = n % 10;
        n /= 10;
    }
    sort(b,b + i + 1);
    for (int j = i;j >= 1;j--)
    {
        cout << b[j];
    }
    return 0;
}
