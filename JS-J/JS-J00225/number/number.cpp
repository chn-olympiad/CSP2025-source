#include <bits/stdc++.h>

using namespace std;
string s;
int t,a[1000003];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            a[++t]=int(s[i]-'0');
        }
    }
    sort(a+1,a+t+1,greater<int>());
    for(int i=1;i<=t;i++)
    {
        cout<<a[i];
    }
    return 0;
}
