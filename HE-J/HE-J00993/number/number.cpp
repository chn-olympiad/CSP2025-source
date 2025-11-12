#include <bits/stdc++.h>
int a[10];
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for (int i=0;i<s.length();i++)
    {

        if (s[i]>='a' && s[i]<='z')
        {
            continue;
        }
        a[s[i]-'0']++;
    }
    for (int i=9;i>=0;i--)
    {
        while (a[i]>0)
        {
            cout<<i;
            a[i]--;
        }

    }
}
