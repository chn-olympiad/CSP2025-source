#include<bits/stdc++.h>
using namespace std;
int a[1000010]={0},b=0,len;
string s;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    len=s.size();
    for(int i=0;i<=len;i++)
    {
       if(s[i]-'0'>=0&&s[i]-'0'<=9)
       {
           b++;
           a[b]=s[i]-'0';
       }
    }
    sort(a+1,a+b+1);
    for(int i=b;i>=1;i--)
    {
        cout<<a[i];
    }
    return 0;
}
