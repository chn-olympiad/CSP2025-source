#include<bits/stdc++.h>
using namespace std;
int b[1000010],n;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i = 0;i<s.length();i++)
    {
        if(s[i]>='0' && s[i]<='9')
        {

            n++;
            b[n]=s[i]-'0';
        }
    }
    sort(b+1,b+n+1);
    for(int i = n;i>=1;i--)
    {
        cout<<b[i];
    }
    return 0;
}
