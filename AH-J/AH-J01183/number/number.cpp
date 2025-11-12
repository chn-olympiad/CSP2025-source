#include<bits/stdc++.h>
using namespace std;
string s;

long long a[100],t,flag=0;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]<58&&s[i]>47)a[s[i]-48]++;
    }
    for(int i=9;i>=1;i--)
    {
        for(int j=1;j<=a[i];j++)
        {
            cout<<i;
            flag=1;
        }
    }
    if(flag==0)cout<<0;
    else
    {
        for(int j=1;j<=a[0];j++)
        {
            cout<<0;
        }
    }
    return 0;
}
//48 57
