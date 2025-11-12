#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int ans =0;
    cin >> s;
    char a[10005];
    for (int i=0;i<s.size();i++)
    {
        if(s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'||s[i]=='0')
        {
            a[i] =s[i];
        }
        else
        {
            ans++;
        }
    }
    for (int i=0;i<s.size();i++)
    {
        for (int j = i;j<s.size();j++)
        {
            if(a[i] <a[j])
            {
                swap(a[j],a[i]);
            }
        }
    }
    for (int i=0;i<s.size();i++)
    {
        cout <<a[i];
    }
    return 0;
}
