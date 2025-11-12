#include <bits/stdc++.h>
using namespace std;
string s;
int a[111111],ans=0;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    getline(cin,s);
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            ans++;
            a[ans]=s[i]-'0';
        }
    }
    sort(a+1,a+ans+1);
    if(a[ans]==0)
    {
        cout<<0<<endl;
        return 0;
    }
    for(int i=ans;i>=1;i--)
    {
        cout<<a[i];
    }
    return 0;
}
