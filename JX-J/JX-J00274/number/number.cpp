#include <bits/stdc++.h>
using namespace  std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    string s;
    cin >> a;
    for (int i = 1;i <= a.length();i++)
    {
        if (a[i] >= 0 && a[i] <=9 )
        {
            s[i] = a[i];
        }
    }
    int len = s.length();
    sort (s+1,s+len+1);
    cout << s;
    return 0;
}
