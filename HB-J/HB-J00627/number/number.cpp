#include <bits/stdc++.h>
using namespace std;
string a;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    string s;
    cin>>s;
    for (int i=0;i<s.length();i++)
    {
        if (s[i]>='0' && s[i]<='9')
        {
            a+=s[i];
        }

    }

    for (int i=0;i<=a.length();i++)
    {
        for (int j=0;j<=i;j++)
        {
            if (i==a.length() &&j==i-1)
            {
                break;
            }
            if (a[j]<a[j+1])
            {
                swap(a[j],a[j+1]);
            }
        }
    }

    cout<<a;
    return 0;
}
