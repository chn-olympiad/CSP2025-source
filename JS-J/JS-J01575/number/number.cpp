#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010],t;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    std::ios::sync_with_stdio(false);
    cin>>s;
    for(int i=0;i<s.size();i++)
        if(isdigit(s[i]))
            a[++t]=s[i]-'0';
    sort(a+1,a+t+1);
    if(a[t]=='0')
    {
        cout<<0;
        return 0;
    }
    for(int i=t;i>=1;i--)
        cout<<a[i];
    return 0;
}
