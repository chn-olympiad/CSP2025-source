#include<bits/stdc++.h>
using namespace std;
string s;
int b[1000005];
int flag=0;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9')
        {
            b[flag++]=s[i]-'0';
        }
    }
    sort(b,b+flag);
    for(int i=flag-1;i>=0;i--)
    {
        cout<<b[i];
    }
    return 0;
}
