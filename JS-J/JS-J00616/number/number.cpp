#include<bits/stdc++.h>
using namespace std;
int a[1000005],x;
string s;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            x++;
            a[x]=s[i]-'0';
        }
    }
    sort(a+1,a+x+1);
    for(int i=x;i>=1;i--)
    {
        cout<<a[i];
    }
    return 0;
}
