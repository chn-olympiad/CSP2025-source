#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int i,a[1000000],j=0;
    for(i=0;i<s.length();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        a[j]=s[i]-48;
    }
    sort(a,a+j+1);
    int num=0;
    for(i=j-1;i<=0;i++)
       num=a[i]+num*10;
    cout<<num;
    return 0;
}
