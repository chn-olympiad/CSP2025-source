#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000005]={},x=1;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int n=s.size();
    if(n==1&&('0'<=s[0]&&'9'>=s[0]))
    {
        cout<<s;
        return 0;
    }
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            a[x]=s[i]-48;
            x++;
        }
    }
    if(x==1)
    {
        cout<<0;
        return 0;
    }
    sort(a+1,a+x+1);
    for(int i=x;i>=2;i--)
    {

        cout<<a[i];
    }
    return 0;
}
