#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int a[s.length()+5],ans=0;
    for (int i=0;i<s.length();i++)
    {
        if((s[i]>='1')&&(s[i]<='9'))
        {
            ans++;
            cout<<s[i];
            a[ans]=stoi(s[i]);
        }
    }
    sort(a+1,a+ans+1);
    for (int i=ans;i>=1;i--)
    {
        cout<<a[i];
    }
    return 0;
    }
