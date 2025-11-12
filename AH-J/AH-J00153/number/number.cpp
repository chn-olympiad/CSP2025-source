#include <bits/stdc++.h>
using namespace std;
int b[1000001];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int sum = 1;
    string s;
    cin >> s;
    for (int i = 1;i <= s.length();i++)
    {
        if (s[i-1] <= '9' && s[i-1] >= '0')
        {
            b[sum] = s[i-1] - 48;
            sum++;
        }
    }
    sort(b+1,b+sum+1);
    for (int i = sum;i > 1;i--)
    {
        cout << b[i];
    }
    return 0;
}
